#include "Player.h"

/**
 * �R���X�g���N�^
 */
CPlayer::CPlayer() :
	m_Mesh(),
	m_Pos(0.0f, 0.0f, 0.0f),
	m_RotZ(0.0f),
	m_Spd(1.0f),
    m_ShotMesh(),
	m_ShotArray(),
	m_ShotWait(){
}

/**
 * �f�X�g���N�^
 */
CPlayer::~CPlayer() {
}

/**
 * �ǂݍ���
 */
bool CPlayer::Load(void) {
	// ���b�V���̓ǂݍ���
	if (!m_Mesh.Load("player.mom"))
	{
		return false;
	}
<<<<<<< HEAD
=======

	if (!m_ShotMesh.Load("pshot.mom"))
	{
		return false;
	}
	for (int i = 0; i < PLAYERSHOT_COUNT;i++)
	{
		m_ShotArray[i].SetMesh(&m_ShotMesh);
	}
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	return true;
}

/**
 * ������
 */
<<<<<<< HEAD
void CPlayer::Initialize(void){
	m_Pos = Vector3(0.0f, 0.0f, -FIELD_HALF_Z + 2.0f);
	m_RotZ = 0;
=======
void CPlayer::Initialize(void) {
	m_Pos = Vector3(0.0f, 0.0f, -FIELD_HALF_Z + 2.0f);
	m_RotZ = 0;

	for (int i = 0; i < PLAYERSHOT_COUNT; i++)
	{
		m_ShotArray[i].Initialize();
	}


>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}

/**
 * �X�V
 */
<<<<<<< HEAD
void CPlayer::Update(void){
	float Roll = 0;

=======
void CPlayer::Update(void) {
	float Roll = 0;
	m_Spd = PLAYER_SPEED;

	//����������
	if (g_pInput->IsKeyHold(MOFKEY_LSHIFT) && g_pInput->IsKeyHold(MOFKEY_LEFT))
	{
		m_Spd *= 4;
		m_Pos.x = max(m_Pos.x - PLAYER_SPEED, -FIELD_HALF_X);
	}
	if (g_pInput->IsKeyHold(MOFKEY_LSHIFT) && g_pInput->IsKeyHold(MOFKEY_RIGHT))
	{
		m_Spd *= 4;
		m_Pos.x = min(m_Pos.x + PLAYER_SPEED, FIELD_HALF_X);
	}
	//�L�[�ړ�
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	if (g_pInput->IsKeyHold(MOFKEY_LEFT))
	{
		m_Pos.x = max(m_Pos.x - PLAYER_SPEED, -FIELD_HALF_X);
		Roll -= MOF_MATH_PI;
<<<<<<< HEAD
	}
=======

	}

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	if (g_pInput->IsKeyHold(MOFKEY_RIGHT))
	{
		m_Pos.x = min(m_Pos.x + PLAYER_SPEED, FIELD_HALF_X);
		Roll += MOF_MATH_PI;
<<<<<<< HEAD
	}
	if (g_pInput->IsKeyHold(MOFKEY_UP))
	{
		m_Pos.z = min(m_Pos.z + PLAYER_SPEED, FIELD_HALF_Z);
	}
	if (g_pInput->IsKeyHold(MOFKEY_UP))
	{
		m_Pos.z = max(m_Pos.z - PLAYER_SPEED, -FIELD_HALF_Z);
	}
	float RotSpeed = MOF_ToRadian(10);
	if (Roll == 0);
=======

	}

	if (g_pInput->IsKeyHold(MOFKEY_UP))
	{
		m_Pos.z = min(m_Pos.z + PLAYER_SPEED, FIELD_HALF_Z);

	}

	if (g_pInput->IsKeyHold(MOFKEY_DOWN))
	{
		m_Pos.z = max(m_Pos.z - PLAYER_SPEED, -FIELD_HALF_Z);

	}

	//��]
	float RotSpeed = MOF_ToRadian(10);
	if (Roll == 0)
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	{
		RotSpeed = min(abs(m_RotZ) * 0.1f, RotSpeed);
	}
	if (abs(m_RotZ) <= RotSpeed || signbit(m_RotZ) != signbit(Roll))
	{
		m_RotZ += Roll;
	}
	m_RotZ -= copysignf(min(RotSpeed, abs(m_RotZ)), m_RotZ);

<<<<<<< HEAD
=======
	if (m_ShotWait <= 0)
	{
		if (g_pInput->IsKeyHold(MOFKEY_SPACE))
		{
			for (int cnt = 0; cnt < 2; cnt++)
			{
				for (int i = 0; i < PLAYERSHOT_COUNT; i++)
				{
					if (m_ShotArray[i].GetShow()) { continue; }
					CVector3 ShotPos(0.4f * (cnt * 2 - 1), 0, 0);
					ShotPos.RotationZ(m_RotZ);
					ShotPos += m_Pos;
					m_ShotWait = PLAYERSYOT_WAIT;
					m_ShotArray[i].Fire(ShotPos);
					break;
				}

			}
		}
	}
	else
	{
		m_ShotWait--;
	}
	for (int i = 0; i < PLAYERSHOT_COUNT; i++)
	{
		m_ShotArray[i].Update();
	}

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}


/**
 * �`��
 */
<<<<<<< HEAD
void CPlayer::Render(void){
	CMatrix44 matWorld;
	matWorld.RotationZ(m_RotZ);
	matWorld.SetTranslation(m_Pos);
	m_Mesh.Render(matWorld);
=======
void CPlayer::Render(void) {
	//���[���h�s��쐬
	CMatrix44 matworld;
	matworld.RotationZ(m_RotZ);
	matworld.SetTranslation(m_Pos);
	//���b�V���`��
	m_Mesh.Render(matworld);
	for (int i = 0; i < PLAYERSHOT_COUNT; i++)
	{
		m_ShotArray[i].Render();
	}

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}

/**
 * �f�o�b�O�����`��
 */
void CPlayer::RenderDebugText(void) {
	// �ʒu�̕`��
	CGraphicsUtilities::RenderString(10, 40, MOF_XRGB(0, 0, 0),
		"�v���C���[�ʒu X : %.1f , Y : %.1f , Z : %.1f", m_Pos.x, m_Pos.y, m_Pos.z);
}

/**
 * ���
 */
<<<<<<< HEAD
void CPlayer::Release(void){
	m_Mesh.Release();
=======
void CPlayer::Release(void) {
	m_Mesh.Release();
	m_ShotMesh.Release();
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}