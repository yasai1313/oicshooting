#pragma once

#include "GameDefine.h"

class CEnemyShot{
private:
	CMeshContainer*		m_pMesh;	//�V���b�g�̃��b�V���|�C���^
	Vector3				m_Pos;		//���W
	Vector3				m_Spd;		//�ړ��x�N�g��
	bool				m_bShow;	//�\�����
	float				m_RotY;		//Y��]�p�x�i���W�A���j
public:
	CEnemyShot();
	~CEnemyShot();
	
	
	/**
	 * ������
	 *
	 */
	void Initialize();
	
	/**
	 * ����
	 *
	 */
	void Fire(const Vector3& p,const Vector3& s);
	
	/**
	 * �X�V
	 *
	 */
	void Update();
	
	/**
	 * �`��
	 *
	 */
	void Render();
	
	/**
	 * �f�o�b�O�\��
	 *
	 */
	void RenderDebug();
	
	/**
	 * �V���b�g�̃��b�V����ݒ肷��
	 *
	 */
	void SetMesh(CMeshContainer* pm){ m_pMesh = pm; }
	
	/**
	 * �\����Ԏ擾
	 *  �߂�l��true�Ȃ�\�����Afalse�Ȃ��\��
	 */
	bool GetShow(){ return m_bShow; }
	
	/**
	 * �\����Ԑ؂�ւ�
	 *
	 */
	void SetShow(bool bs){ m_bShow = bs; }
	
	/**
	 * �Փˋ���Ԃ�
	 *
	 */
	CSphere GetSphere(){ return CSphere(m_Pos,0.2f); }
	
	
	/**
	 * �e�̔z�񂩂��\���̂��̂���������
	 *
	 */
	static CEnemyShot* FindAvailableShot(CEnemyShot* shot,int smax);
};