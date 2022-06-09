#include "Player.h"

/**
 * �R���X�g���N�^
 */
CPlayer::CPlayer() :
m_Mesh(),
m_Pos(0.0f,0.0f,0.0f),
m_RotZ(0.0f),
m_SMesh(),
m_SArray(),
m_SWait(),
m_bDead(false),
m_SMode(),
m_SubMode()
{
}

/**
 * �f�X�g���N�^
 */
CPlayer::~CPlayer(){
}

/**
 * �ǂݍ���
 */
bool CPlayer::Load(void){
	// ���b�V���̓ǂݍ���
	m_Mesh.Load("player.mom");
	m_SMesh.Load("pshot.mom");

	for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
		m_SArray[i].SetMesh(&m_SMesh);
	}
	return true;
}

/**
 * ������
 */
void CPlayer::Initialize(void){
	m_Pos = Vector3(0, 0, -FIELD_HALF_Z + 2);
	m_RotZ = 0;
	m_SMode = PlayerShotMode::MODE_DOUBLE;
	m_SubMode = PlayerShotSubMode::MODE_DIRECT;
	m_bDead = false;
	for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
		m_SArray[i].Initialize();

	}
}

/**
 * �X�V
 */
#define MAX_SKILLTIME 100
int SkillTimer = MAX_SKILLTIME;

void CPlayer::Update(void){
	float Roll = 0;
	float PlayerSpeed = PLAYER_SPEED;
	float RotSpeed = MOF_ToRadian(10);

	if (m_bDead)
	{
		return;
	}
	if (g_pInput->IsKeyHold(MOFKEY_LSHIFT) && SkillTimer > 4 ) {
		PlayerSpeed *= 4;
		RotSpeed *= 4;
		SkillTimer-= 4;
	}
	else
	{
		if (MAX_SKILLTIME > SkillTimer)
			SkillTimer++;
	}

	// ���ړ�
	if (g_pInput->IsKeyHold(MOFKEY_LEFT)) {
		m_Pos.x = max(m_Pos.x - PlayerSpeed, -FIELD_HALF_X);
		Roll -= MOF_MATH_PI;
		m_Move = PlayerMove::LEFT;
	}
	else if (g_pInput->IsKeyHold(MOFKEY_RIGHT)) {
		m_Pos.x = min(m_Pos.x + PlayerSpeed, FIELD_HALF_X);
		Roll += MOF_MATH_PI;
		m_Move = PlayerMove::RIGHT;
	}else{ m_Move = PlayerMove::IDLE; }

	if (g_pInput->IsKeyHold(MOFKEY_UP)) {
		m_Pos.z = min(m_Pos.z + PlayerSpeed, FIELD_HALF_Z);
	}
	if (g_pInput->IsKeyHold(MOFKEY_DOWN)) {
		m_Pos.z = max(m_Pos.z - PlayerSpeed, -FIELD_HALF_Z);
	}

	if (Roll == 0) {
		RotSpeed = min(abs(m_RotZ) * 0.1f, RotSpeed);
	}
		
	if (abs(m_RotZ) <= RotSpeed || signbit(m_RotZ) != signbit(Roll)) {
		m_RotZ += Roll;
	}	
	m_RotZ -= copysignf(min(RotSpeed, abs(m_RotZ)), m_RotZ);
	
	// �L�[�P�FSingle�A�L�[2�FDouble�A�L�[3�FTripple�ɂ��ĂˁB
	UpdateMode();
	
	if (m_SWait <= 0) {
		if (g_pInput->IsKeyHold(MOFKEY_Z)) {

			switch (m_SMode) {
			case MODE_SINGLE:
				UpdateSingleMode();
				break;
			case MODE_DOUBLE:
				UpdateDoubleMode();
				break;
			case MODE_TRIPPLE:
				UpdateTrippleMode();
				break;
			}		
		}
	}
	else {
		m_SWait--;
	}

	for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
		m_SArray[i].Update();
	}
}

void CPlayer::UpdateMode() {
	if (g_pInput->IsKeyPush(MOFKEY_1)) {
		m_SMode = MODE_SINGLE;
	}
	else if (g_pInput->IsKeyPush(MOFKEY_2)) {
		m_SMode = MODE_DOUBLE;
	}
	else if (g_pInput->IsKeyPush(MOFKEY_3)) {
		m_SMode = MODE_TRIPPLE;
	}

	if (g_pInput->IsKeyPush(MOFKEY_RSHIFT)) {
		m_SubMode = (m_SubMode == MODE_DIRECT )? MODE_WIDE : MODE_DIRECT;
	}
}

void CPlayer::UpdateSingleMode() {
	for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
		if (m_SArray[i].GetShow()) continue;

		CVector3 spos(0, 0, 0);
		spos += m_Pos;
		CVector3 spd(0, 0, PLAYERSHOT_SPEED);
		m_SWait = PLAYERSHOT_WAIT;
		m_SArray[i].Fire(spos, spd, m_SMode);
		break;
	}
}

void CPlayer::UpdateDoubleMode() {
	for (int cnt = 0; cnt < 2; cnt++) {
		for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
			if (m_SArray[i].GetShow()) continue;

			CVector3 spos(0.4f * (cnt * 2 - 1), 0, 0);
			spos.RotationZ(m_RotZ);
			spos += m_Pos;
			CVector3 spd(0, 0, PLAYERSHOT_SPEED);
			if (m_SubMode == MODE_WIDE) {
				spd = Vector3(cnt * WIDE_RAD*2 - WIDE_RAD, 0, PLAYERSHOT_SPEED);
			}
			m_SWait = PLAYERSHOT_WAIT;
			m_SArray[i].Fire(spos, spd, m_SMode);
			break;
		}
	}
}

void CPlayer::UpdateTrippleMode() {
	for (int cnt = 0; cnt < 3; cnt++) {
		for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
			if (m_SArray[i].GetShow()) continue;

			CVector3 spos(0.4f * (cnt * 1 - 1), 0, 0);
			spos.RotationZ(m_RotZ);
			spos += m_Pos;
//			CVector3 spd(cnt * WIDE_RAD - WIDE_RAD, 0, PLAYERSHOT_SPEED);
			CVector3 spd(0, 0, PLAYERSHOT_SPEED);
			if (m_SubMode == MODE_WIDE) {
				spd = Vector3(cnt * WIDE_RAD - WIDE_RAD, 0, PLAYERSHOT_SPEED);
			}
			m_SWait = PLAYERSHOT_WAIT;
			m_SArray[i].Fire(spos,spd, m_SMode);
			break;
		}
	}
}

/**
 * �`��
 */
void CPlayer::Render(void){
	if (m_bDead)
	{
		return;
	}
	CMatrix44 matWorld;
	matWorld.RotationZ(m_RotZ);
	matWorld.SetTranslation(m_Pos);
	m_Mesh.Render(matWorld);

	for (int i = 0; i < SkillTimer; i++) {
		CGraphicsUtilities::RenderString(800 + i*2, 0, MOF_COLOR_YELLOW,"|");
	}

	for (int i = 0; i < PLAYERSHOT_COUNT; i++) {
		m_SArray[i].Render();
	}

}

/**
 * �f�o�b�O�����`��
 */
void CPlayer::RenderDebugText(void){
	// �ʒu�̕`��
	CGraphicsUtilities::RenderString(10,40,MOF_XRGB(0,0,0),
			"�v���C���[�ʒu X : %.1f , Y : %.1f , Z : %.1f",m_Pos.x,m_Pos.y,m_Pos.z);
	
	
}

/*
*
*/
void CPlayer::RenderDebug(void) {
	//�����蔻��̕\��
	CGraphicsUtilities::RenderSphere(GetSphere(), Vector4(0, 1, 0, 0.3f));
	//�ʂ̕`��
	for (int i = 0; i < PLAYERSHOT_COUNT; i++)
	{
		m_SArray[i].RenderDebug();
	}
}

void CPlayer::CollisionEnemy(CEnemy& ene) {
	if(!ene.GetShow())
	{
		return;
	}
	CSphere ps = GetSphere();
	CSphere es = ene.GetSphere();
	if (ps.CollisionSphere(es))
	{
		m_bDead = true;
	}
	for (int i = 0; i < PLAYERSHOT_COUNT; i++)
	{
		if (!m_SArray[i].GetShow())
		{
			continue;
		}
		CSphere ss = m_SArray[i].GetSphere();
		if (ss.CollisionSphere(es))
		{
			ene.Damage(1);
			m_SArray[i].SetShow(false);
			break;
		}
	}
}
/**
 * ���
 */
void CPlayer::Release(void){
	m_Mesh.Release();
	m_SMesh.Release();
}