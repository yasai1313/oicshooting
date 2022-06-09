#include "EnemyShot.h"

/**
 * �R���X�g���N�^
 *
 */
CEnemyShot::CEnemyShot() :
m_pMesh(NULL),
m_Pos(0,0,0),
m_Spd(0,0,0),
m_bShow(false),
m_RotY(0){
}

/**
 * �f�X�g���N�^
 *
 */
CEnemyShot::~CEnemyShot(){
}

/**
 * ������
 *
 */
void CEnemyShot::Initialize(){
	m_Pos = Vector3(0,0,0);
	m_Spd = Vector3(0,0,0);
	m_bShow = false;
	m_RotY = 0;
}

/**
 * ����
 *
 */
void CEnemyShot::Fire(const Vector3& p,const Vector3& s){
	m_Pos = p;
	m_Spd = s;
	m_bShow = true;
	m_RotY = 0;
}

/**
 * �X�V
 *
 */
void CEnemyShot::Update(){
	// ��\��
	if(!m_bShow)
	{
		return;
	}
	// ���x�𗘗p�����ړ�
	
	// ��ʊO�ŏ���
	
	// �e����]
	
}

/**
 * �`��
 *
 */
void CEnemyShot::Render(){
	if(!m_bShow)
	{
		return;
	}
	//��]�𔽉f
	
	//���W��ݒ�
	
	//�`��
}

/**
 * �f�o�b�O�\��
 *
 */
void CEnemyShot::RenderDebug(void){
	if(!m_bShow)
	{
		return;
	}
	
	CGraphicsUtilities::RenderSphere(GetSphere(),Vector4(1,0,0,0.3f));
}

/**
 * �e�̔z�񂩂��\���̂��̂���������
 *
 */
CEnemyShot* CEnemyShot::FindAvailableShot(CEnemyShot* shot,int smax){
	return NULL;
}