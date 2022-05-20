#include "PlayerShot.h"

/**
 * �R���X�g���N�^
 */
CPlayerShot::CPlayerShot() :
m_pMesh(NULL),
m_Pos(0.0f,0.0f,0.0f),
m_bShow(false){
}

/**
 * �f�X�g���N�^
 */
CPlayerShot::~CPlayerShot(){
}

/**
 * ������
 */
void CPlayerShot::Initialize(void){
	m_Pos = Vector3(0.0f, 0.0f, 0.0f);
	m_bShow = false;
}

/**
 * ����
 */
void CPlayerShot::Fire(const Vector3& p){
	m_Pos = p;
	m_bShow = false;
}

/**
 * �X�V
 */
void CPlayerShot::Update(void){
	if (!m_bShow)
	{
		return;
	}
	m_Pos.z += PLAYERSHOT_SPEED;
	if (FIELD_HALF_Z < m_Pos.z)
	{
		m_bShow = false;
	}
}

/**
 * �`��
 */
void CPlayerShot::Render(void){
	if (!m_bShow)
	{
		return;
	}
	CMatrix44 wMat;
	wMat.Translation(m_Pos);
	m_pMesh->Render(wMat);
}
