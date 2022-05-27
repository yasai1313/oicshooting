#pragma once

#include "Mof.h"

// �ړ��\�͈͂̔���
#define FIELD_HALF_X (9.0f)
#define FIELD_HALF_Z (14.0f)

enum EASTING_TYPE {
	EASE_LINEAR,
	EASE_IN_SINE,
	EASE_OUT_SINE,
	EASE_INOUT_SINE,zzz
};

struct ANIM_DATA {
	float Time;
	float Value;
	EASTING_TYPE EasingType;
};
float InterpolationAnim(float AnimTime,ANIM_DATA* AnimDate, int cnt);
/********************** Player **********************/
// �ړ����x
#define PLAYER_SPEED		(0.1f)

// �ړ����x
#define PLAYERSHOT_SPEED	(0.4f)

// �e�̔��ˌ��E��
#define PLAYERSHOT_COUNT	(40)

// �e�̔��ˊԊu
#define PLAYERSHOT_WAIT		(5)

// �e�̔��ˊp�x
#define WIDE_RAD			(0.05f)

enum PlayerMove {
	IDLE,
	LEFT,
	RIGHT,
};

enum PlayerShotMode {
	MODE_SINGLE,
	MODE_DOUBLE,
	MODE_TRIPPLE,
};

enum PlayerShotSubMode {
	MODE_DIRECT,
	MODE_WIDE,
};


/********************** Stage **********************/
// �X�N���[�����x
#define		SCROLL_SPEED	(1.0f)

