#include "Enemy.h"

ANIM_DATA g_EnemyAnimPosY[2] = {
	{1.0f,-10.0f,EASE_LINEAR},
	{3.0f,0.0f,EASE_INOUT_SINE},
};
ANIM_DATA g_EnemyAnimPosZ[5] = {
	{0.0f,-FIELD_HALF_Z,EASE_LINEAR},
	{1.0f,FIELD_HALF_Z-10.0f,EASE_LINEAR},
	{2.0f,FIELD_HALF_Z,EASE_OUT_SINE},
	{3.0f,FIELD_HALF_Z - 10.0f,EASE_IN_SINE},
	{5.0f,-FIELD_HALF_Z,EASE_LINEAR},
};
/**
 * �R���X�g���N�^
 *
 */
CEnemy::CEnemy():
m_pMesh(NULL),
m_Pos(0,0,0),
m_Rot(0,0,0),
m_HP(5),
m_AnimTime(0){
}

/**
 * �f�X�g���N�^
 *
 */
CEnemy::~CEnemy(){
}

/**
 * ������
 *
 */
void CEnemy::Initialize(){
	m_Pos = Vector3(0, 0, 0);
	m_Rot = Vector3(0, 0, 0);
	m_bShow = false;
	m_AnimTime = 0;
}

/**
 * �J�n
 *
 */
void CEnemy::Start(const Vector3& p){
	m_Pos = p;
	m_Rot = Vector3(0, 0, 0);
	m_bShow = true;
	m_AnimTime = 0;
	m_HP = 5;
}

/**
 * �X�V
 *
 */
void CEnemy::Update(){
	//��\��
	if (!GetShow())
	{
		return;
	}
	m_AnimTime += CUtilities::GetFrameSecond();

	m_Pos.y = InterpolationAnim(m_AnimTime, g_EnemyAnimPosY, 2);
	m_Pos.z = InterpolationAnim(m_AnimTime, g_EnemyAnimPosZ, 5);

	if (g_EnemyAnimPosZ[4].Time < m_AnimTime)
	{
		m_bShow = false;
	}
}

/**
 * �`��
 *
 */
void CEnemy::Render(){
	if(!GetShow())
	{
		return;
	}
	
	CMatrix44 matWorld;
	matWorld.RotationZXY(m_Rot);
	matWorld.SetTranslation(m_Pos);
	m_pMesh->Render(matWorld);


}

void CEnemy::RenderDebug() {
	if (!GetShow())
	{
		return;
	}
	CGraphicsUtilities::RenderSphere(GetSphere(), Vector4(1, 0, 0, 0.3f));
}
/**
 * �f�o�b�O�����`��
 *
 */
void CEnemy::RenderDebugText(int i){
	//�ʒu�̕`��
	CGraphicsUtilities::RenderString(10,70 + i * 24,MOF_XRGB(0,0,0),
		"�G[%d] %s , �ʒu X : %.1f , Y : %.1f , Z : %.1f",i + 1,
		(GetShow() ? "�\��" : "��\��"),m_Pos.x,m_Pos.y,m_Pos.z);
}

void CEnemy::Damage(int dmg) {
	m_HP -= dmg;
	if (m_HP <= 0)
	{
		m_bShow = false;
	}
}