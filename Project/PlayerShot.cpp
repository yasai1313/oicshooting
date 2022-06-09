#include "PlayerShot.h"

/**
 * �R���X�g���N�^
 */
CPlayerShot::CPlayerShot() :
m_pMesh(NULL),
m_Pos(0.0f,0.0f,0.0f),
m_Speed(0.0f, 0.0f, 0.0f),
m_bShow(false),
m_Mode()
{
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
	m_Pos = Vector3(0, 0, 0);
	m_bShow = false;
}

/**
 * ����
 */
void CPlayerShot::Fire(const Vector3& p, const Vector3& s, PlayerShotMode m){
	m_Pos = p;
	m_Speed = s;
	m_Mode = m;
	m_bShow = true;
}

/**
 * �X�V
 */
void CPlayerShot::Update(){
	if (m_bShow) {
		
		UpdateMode();
		m_Pos += m_Speed;
		if (FIELD_HALF_Z < m_Pos.z) {
			m_bShow = false;
		}
	}
}

void CPlayerShot::UpdateMode(){	
	switch (m_Mode)
	{
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

void CPlayerShot::UpdateSingleMode() {
}

void CPlayerShot::UpdateDoubleMode() {
}

void CPlayerShot::UpdateTrippleMode() {
}

/**
 * �`��
 */
void CPlayerShot::Render(void){
	if (m_bShow) {
		CMatrix44 wmat;
		wmat.Translation(m_Pos);
		m_pMesh->Render(wmat);
	}
}

void CPlayerShot::RenderDebug(void) {
	if (!m_bShow)
	{
		return;
	}
	CGraphicsUtilities::RenderSphere(GetSphere(), Vector4(0, 1, 0, 0.3f));
}