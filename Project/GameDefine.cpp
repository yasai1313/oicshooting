#include "GameDefine.h"

/**
* �A�j���[�V������ԏ���
*/
float InterpolationAnim(float AnimTime, ANIM_DATA* AnimData, int cnt) {
	int phase;
	for (phase = 1; phase < cnt; phase++)
	{
		if (AnimTime < AnimData[phase].Time)
		{
			break;
		}
	}
	phase = MOF_MIN(phase, cnt - 1);
	// nt��� ���̃t���[���̍Đ��ώ���
	// at��� ���̃t���[���̍Đ����ׂ�����
	// t ��� nt/at = �����Đ��������i0.0 �` 1.0�j
	float nt = AnimTime - AnimData[phase - 1].Time;
	float at = AnimData[phase].Time - AnimData[phase - 1].Time;
	float t = nt / at;
	t = MOF_CLIPING(t, 0.0f, 1.0f);
	// �C�[�W���O
	switch (AnimData[phase].EasingType)
	{
	case EASE_IN_SINE:
		t = 1.0f - MOF_COS(MOF_MATH_HALFPI * t);
		break;
	case EASE_OUT_SINE:
		t = MOF_SIN(MOF_MATH_HALFPI * t);
		break;
	case EASE_INOUT_SINE:
		t = 0.5f - 0.5f * MOF_COS(MOF_MATH_PI * t);
		break;
	}
	// ���
	float from = AnimData[phase - 1].Value;
	float to = AnimData[phase].Value;
	return from + (to - from) * t;
}