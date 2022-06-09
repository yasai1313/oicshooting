#pragma once

#include "GameDefine.h"
#include "PlayerShot.h"
#include "Enemy.h"
class CPlayer{
private:
	CMeshContainer	m_Mesh;
	CVector3		m_Pos;
	float			m_RotZ;
	PlayerMove		m_Move;
	bool m_bDead;
	CMeshContainer	m_SMesh;
	CPlayerShot		m_SArray[PLAYERSHOT_COUNT];
	int				m_SWait;

	PlayerShotMode		m_SMode;
	PlayerShotSubMode	m_SubMode;

public:
	CPlayer();
	~CPlayer();
	void CollisionEnemy(CEnemy& ene);
	bool IsDead() { return m_bDead; }
	void RenderDebug();
	CSphere GetSphere();
	bool Load();
	void Initialize();
	void Update();
	void Render();
	void RenderDebugText();
	const CVector3 GetPosition(){ return m_Pos; }
	void Release();
	PlayerMove GetMove() { return m_Move; }
	
	void UpdateMode();
	void UpdateSingleMode();
	void UpdateDoubleMode();
	void UpdateTrippleMode();
};