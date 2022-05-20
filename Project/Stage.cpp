#include "Stage.h"

/**
 * �R���X�g���N�^
 *
 */
CStage::CStage():
m_BG(),
m_Scroll(0.0f){
}

/**
 * �f�X�g���N�^
 *
 */
CStage::~CStage(){
}

/**
 * �ǂݍ���
 *
 */
bool CStage::Load(){
	//�w�i
	if (!m_BG.CreateSprite("road.png"))
	{
		return false;
	}

	return true;
}

/**
 * ������
 *
 */
void CStage::Initialize(){
	m_BG.m_Angle.x  = MOF_MATH_HALFPI;
	m_BG.m_Angle.y = MOF_MATH_HALFPI;
	m_BG.m_Scale = Vector3(200, 200, 200);
	m_BG.m_Position.y = -15;
	m_BG.SetImageRect(0, 0, m_BG.GetTexture()->GetWidth() * 4, m_BG.GetTexture()->GetHeight() * 4);
}

/**
 * �X�V
 *
 */
void CStage::Update(){
	m_Scroll += SCROLL_SPEED;
}

/**
 * �`��
 *
 */
void CStage::Render(){
	for (int i = 0; i < 2; i++)
	{
		m_BG.m_Position.z = 50.0f + fmodf(-m_Scroll, m_BG.m_Scale.z) + i * m_BG.m_Scale.z;
		m_BG.Update();
		m_BG.Render();

	}
}

/**
 * �f�o�b�O�����`��
 *
 */
void CStage::RenderDebugText(){
	//�X�N���[���l�̕`��
	CGraphicsUtilities::RenderString(10,10,MOF_XRGB(0,0,0),
		"�X�N���[�� : %.0f",m_Scroll);
}

/**
 * ���
 *
 */
void CStage::Release(){
	m_BG.Release();
}
