/*************************************************************************//*!

					@file	GameApp.cpp
					@brief	基本ゲームアプリ。

															@author	濱田　享
															@date	2014.05.14
*//**************************************************************************/

//INCLUDE
#include	"GameApp.h"
#include "Player.h"
<<<<<<< HEAD

//カメラ
CCamera gCamera;
CDirectionalLight gLight;
CPlayer gPlayer;
=======
#include "Stage.h"

CCamera gCamera;

CDirectionalLight gLight;

CPlayer gPlayer;

CStage gStage;

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
bool gbDebug = false;
/*************************************************************************//*!
		@brief			アプリケーションの初期化
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Initialize(void) {
	//リソース配置ディレクトリの設定
	CUtilities::SetCurrentDirectory("Resource");
<<<<<<< HEAD
	gCamera.SetViewPort();
	gCamera.LookAt(Vector3(0, 6.0f, -17.0f), Vector3(0, 0, -10), Vector3(0, 1, 0));
	gCamera.PerspectiveFov(MOF_ToRadian(60.0f), 1024.0f / 768.0f, 0.01f, 1000.0f);
	CGraphicsUtilities::SetCamera(&gCamera);

	gLight.SetDirection(Vector3(-1, -2, 1.5f));
	gLight.SetDiffuse(MOF_COLOR_WHITE);
	gLight.SetAmbient(MOF_COLOR_WHITE);
=======



	//カメラポジション
	gCamera.SetViewPort();
	gCamera.LookAt(Vector3(0, 6.0f, -17.0f), Vector3(0, 0, -10), Vector3(0, 1, 0));

	gCamera.PerspectiveFov(MOF_ToRadian(60, 0f), 1024.0f / 768.0f, 0.01f, 1000.0f);
	CGraphicsUtilities::SetCamera(&gCamera);

	//ライト
	gLight.SetDirection(Vector3(-1, -2, 1.5f));
	gLight.SetDiffuse(MOF_COLOR_RED);
	gLight.SetAmbient(MOF_COLOR_HBLACK);
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	gLight.SetSpeculer(MOF_COLOR_WHITE);
	CGraphicsUtilities::SetDirectionalLight(&gLight);

	gPlayer.Load();

<<<<<<< HEAD
	gPlayer.Initialize();
	
=======
	gStage.Load();

	gPlayer.Initialize();

	gStage.Initialize();

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの更新
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Update(void) {
	//キーの更新
	g_pInput->RefreshKey();

	gStage.Update();

	gPlayer.Update();
	if (g_pInput->IsKeyPush(MOFKEY_F1))
	{
		gbDebug = ((gbDebug) ? false : true);
	}


	float posx = gPlayer.GetPosition().x * 0.4f;
	CVector3 cpos = gCamera.GetViewPosition();
	CVector3 tpos = gCamera.GetTargetPosition();
	CVector3 vup = CVector3(0, 1, 0);
	cpos.x = posx;
	tpos.x = posx;
	vup.RotationZ(gPlayer.GetPosition().x / FIELD_HALF_X * MOF_ToRadian(10.0f));
	gCamera.LookAt(cpos, tpos, vup);
	gCamera.Update();
	return TRUE;
}

/*************************************************************************//*!
		@brief			アプリケーションの描画
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
MofBool CGameApp::Render(void) {
	//描画処理
	g_pGraphics->RenderStart();
	// 画面のクリア
	g_pGraphics->ClearTarget(0.65f, 0.65f, 0.67f, 0.0f, 1.0f, 0);

	g_pGraphics->SetDepthEnable(TRUE);

	gStage.Render();

	gPlayer.Render();

	if (gbDebug)
	{
		CMatrix44 matworld;
		matworld.Scaling(FIELD_HALF_Z * 2, 1, FIELD_HALF_Z * 2);
		CGraphicsUtilities::RenderPlane(matworld, Vector4(1, 1, 1, 0.4f));
	}

	g_pGraphics->SetDepthEnable(FALSE);

	if (gbDebug)
	{
		gStage.RenderDebugText();
		gPlayer.RenderDebugText();
	}

	// 描画の終了
	g_pGraphics->RenderEnd();
	return TRUE;
}
/*************************************************************************//*!
		@brief			アプリケーションの解放
		@param			None

		@return			TRUE		成功<br>
						それ以外	失敗、エラーコードが戻り値となる
*//**************************************************************************/
<<<<<<< HEAD
MofBool CGameApp::Release(void){
	gPlayer.Release();
=======
MofBool CGameApp::Release(void) {
	gPlayer.Release();
	gStage.Release();
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	return TRUE;
}