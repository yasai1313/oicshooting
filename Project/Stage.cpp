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
	return true;
}

/**
 * ������
 *
 */
void CStage::Initialize(){
}

/**
 * �X�V
 *
 */
void CStage::Update(){
}

/**
 * �`��
 *
 */
void CStage::Render(){
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
}
