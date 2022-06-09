#pragma once

#include "GameDefine.h"

class CEnemy{
private:
	int m_HP;
	CMeshContainer*		m_pMesh;
	Vector3				m_Pos;
	Vector3				m_Rot;
	bool				m_bShow;

	float				m_AnimTime;

public:
	CEnemy();
	~CEnemy();
	void Damage(int dmg);
	void RenderDebug();
	CSphere GetSphere() { return CSphere(m_Pos, 0.5f); }
	void Initialize();
	void Start(const Vector3& p);
	void Update();
	void Render();
	void RenderDebugText(int i);
	void SetMesh(CMeshContainer* pm){ m_pMesh = pm; }
	bool GetShow(){ return m_bShow; }
};