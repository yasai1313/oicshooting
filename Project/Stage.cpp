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
<<<<<<< HEAD
=======
	//�w�i
	if (!m_BG.CreateSprite("road.png"))
	{
		return false;
	}

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	return true;
}

/**
 * ������
 *
 */
void CStage::Initialize(){
<<<<<<< HEAD
=======
	m_BG.m_Angle.x  = MOF_MATH_HALFPI;
	m_BG.m_Angle.y = MOF_MATH_HALFPI;
	m_BG.m_Scale = Vector3(200, 200, 200);
	m_BG.m_Position.y = -15;
	m_BG.SetImageRect(0, 0, m_BG.GetTexture()->GetWidth() * 4, m_BG.GetTexture()->GetHeight() * 4);
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}

/**
 * �X�V
 *
 */
void CStage::Update(){
<<<<<<< HEAD
=======
	m_Scroll += SCROLL_SPEED;
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}

/**
 * �`��
 *
 */
void CStage::Render(){
<<<<<<< HEAD
=======
	for (int i = 0; i < 2; i++)
	{
		m_BG.m_Position.z = 50.0f + fmodf(-m_Scroll, m_BG.m_Scale.z) + i * m_BG.m_Scale.z;
		m_BG.Update();
		m_BG.Render();

	}
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
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
<<<<<<< HEAD
=======
	m_BG.Release();
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}
