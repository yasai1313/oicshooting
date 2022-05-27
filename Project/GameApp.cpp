/*************************************************************************//*!
					
					@file	GameApp.cpp
					@brief	��{�Q�[���A�v���B

															@author	�_�c�@��
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include	"Player.h"
#include	"Stage.h"
#include "Stage1.h"

CCamera				gCamera;
CVector3			gCameraPosition;
CVector3			gTargetPosition;
CVector3			gUpVector;
float				gRotUp;

#define ENEMY_COUNT (20)
CEnemy gEnemyArray[ENEMY_COUNT];

CDirectionalLight	gLight;
CPlayer				gPlayer;
CStage				gStage;

bool				gbDebug = false;




/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̏�����
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Initialize(void){
	//���\�[�X�z�u�f�B���N�g���̐ݒ�
	CUtilities::SetCurrentDirectory("Resource");

	gCameraPosition = Vector3(0, 6.0f, -17.0f); // �J�����|�W�V����
	gTargetPosition = Vector3(0, 0, -10);		// �^�[�Q�b�g�̃|�W�V����
	gUpVector		= Vector3(0, 1, 0);			// �A�b�v�x�N�g��

	gCamera.SetViewPort();

	gCamera.LookAt(
		gCameraPosition,	// �J�����|�W�V����
		gTargetPosition,	// �^�[�Q�b�g�̃|�W�V����
		gUpVector);			// �A�b�v�x�N�g��

	gCamera.PerspectiveFov(MOF_ToRadian(60), 1024.0f / 768.0f, 0.01f, 1000.0f);
	CGraphicsUtilities::SetCamera(&gCamera);
	gRotUp = 0;

	gLight.SetDirection(Vector3(-1, -2, 1.5f));
	gLight.SetDiffuse(MOF_COLOR_HGREEN);
	gLight.SetAmbient(MOF_COLOR_HBLUE);
	gLight.SetSpeculer(MOF_COLOR_WHITE);
	CGraphicsUtilities::SetDirectionalLight(&gLight);

	gPlayer.Load();
	gStage.Load();

	gPlayer.Initialize();
	gStage.Initialize(&gStg1EnemyStart);

	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		gEnemyArray[i].Initialize();
	}

	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̍X�V
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/

MofBool CGameApp::Update(void){
	//�L�[�̍X�V
	g_pInput->RefreshKey();
	gPlayer.Update();
	gStage.Update(gEnemyArray,ENEMY_COUNT);
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		gEnemyArray[i].Update();
	}
	if (g_pInput->IsKeyPush(MOFKEY_F1)) {
		gbDebug = ((gbDebug) ? false : true);
	}

	float posx = gPlayer.GetPosition().x * 0.4f;
	
	gCameraPosition.x = gTargetPosition.x = posx;
	gCamera.LookAt(gCameraPosition, gTargetPosition, gUpVector);
	
	gUpVector = Vector3(0, 1, 0);
	
	if (gPlayer.GetMove() != PlayerMove::IDLE){
		float v = 0;
		v = (gPlayer.GetMove() == PlayerMove::RIGHT) ? 0.1f : -0.1f;
		gRotUp = MOF_LERP(gRotUp, v, 0.01f);
		gUpVector.RotationZ(gRotUp);
	}
	else {
		gRotUp = MOF_LERP(gRotUp, 0, 0.1f);
		gUpVector.RotationZ(gRotUp);
	}

	gCamera.Update();
	return TRUE;
}

/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̕`��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Render(void){
	//�`�揈��
	g_pGraphics->RenderStart();
	// ��ʂ̃N���A
	g_pGraphics->ClearTarget(0.65f,0.65f,0.67f,0.0f,1.0f,0);

	g_pGraphics->SetDepthEnable(true);

	gStage.Render();

	gPlayer.Render();
	
	for (int i = 0; i < ENEMY_COUNT; i++)
	{
		gEnemyArray[i].Render();
	}

	if (gbDebug) {
		CMatrix44 matworld;
		matworld.Scaling(FIELD_HALF_X * 2, 1, FIELD_HALF_Z * 2);
		CGraphicsUtilities::RenderPlane(matworld, Vector4(1, 1, 1, 0.4f));
	}
	g_pGraphics->SetDepthEnable(false);

	if (gbDebug) {
//		CGraphicsUtilities::RenderString(10, 40, MOF_XRGB(0, 0, 0),"%f , rot : %f / dest : %f",v,rot, dest);

//gPlayer.RenderDebugText();
//		gStage.RenderDebugText();
		for (int i = 0; i < ENEMY_COUNT; i++)
		{
			gEnemyArray[i].RenderDebugText(i);
		}
	}

	// �`��̏I��
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			�A�v���P�[�V�����̉��
		@param			None
				
		@return			TRUE		����<br>
						����ȊO	���s�A�G���[�R�[�h���߂�l�ƂȂ�
*//**************************************************************************/
MofBool CGameApp::Release(void){
	gPlayer.Release();
	gStage.Release();
	return TRUE;
}