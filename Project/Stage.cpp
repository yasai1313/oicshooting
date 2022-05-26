#include "Stage.h"

/**
 * コンストラクタ
 *
 */
CStage::CStage():
m_BG(),
m_Scroll(0.0f){
}

/**
 * デストラクタ
 *
 */
CStage::~CStage(){
}

/**
 * 読み込み
 *
 */
bool CStage::Load(){
<<<<<<< HEAD
=======
	//背景
	if (!m_BG.CreateSprite("road.png"))
	{
		return false;
	}

>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
	return true;
}

/**
 * 初期化
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
 * 更新
 *
 */
void CStage::Update(){
<<<<<<< HEAD
=======
	m_Scroll += SCROLL_SPEED;
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}

/**
 * 描画
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
 * デバッグ文字描画
 *
 */
void CStage::RenderDebugText(){
	//スクロール値の描画
	CGraphicsUtilities::RenderString(10,10,MOF_XRGB(0,0,0),
		"スクロール : %.0f",m_Scroll);
}

/**
 * 解放
 *
 */
void CStage::Release(){
<<<<<<< HEAD
=======
	m_BG.Release();
>>>>>>> 9426745917d87e031c47c8d3f100abab6a6c3f0c
}
