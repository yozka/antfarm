#include "aaCellWater.h"
#include "aaAlgo.h"
///-------------------------------------------------------------------------




///-------------------------------------------------------------------------
using namespace Formicarium;
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Constructor
///
///
///-------------------------------------------------------------------------
ACellWater::ACellWater()
{





}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Destructor
///
///
///-------------------------------------------------------------------------
ACellWater::~ACellWater()
{


}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// ���������� ���������� ���� �� 0..1
///
///
///-------------------------------------------------------------------------
void ACellWater :: appendWaterUp(const float volume)
{
	waterVolumeUp += volume;
	normalizeWater();
}
///-------------------------------------------------------------------------








 ///------------------------------------------------------------------------
///
///
///
/// ���������� ���������� ���� �� 0..1
///
///
///-------------------------------------------------------------------------
void ACellWater::appendWaterDown(const float volume)
{
	waterVolumeDown += volume;
	normalizeWater();
}
///-------------------------------------------------------------------------










 ///------------------------------------------------------------------------
///
///
///
/// ������������ ������ ����
///
///
///-------------------------------------------------------------------------
void ACellWater :: normalizeWater()
{
	waterVolumeUp	= minmaxBound<float>(0.0f, 1.0f, waterVolumeUp);
	waterVolumeDown = minmaxBound<float>(0.0f, 1.0f, waterVolumeDown);

	const auto volume = waterVolumeUp + waterVolumeDown;
	if (volume < 0.0001)
	{
		water = false;
		waterFull = false;
		waterVolumeUp = 0;
		waterVolumeDown = 0;
		return;
	}

	water = true;
	if (volume > 0.9999f)
	{
		waterFull = true;
		waterVolumeUp = 0.0f;
		waterVolumeDown = 1.0f;
		return;
	}

	waterFull = false;

}
///-------------------------------------------------------------------------










 ///------------------------------------------------------------------------
///
///
///
/// ��������� ���� �����
///
///
///-------------------------------------------------------------------------
float ACellWater::takeWaterDown(const float volume)
{
	float vol = volume;
	waterVolumeDown -= vol;
	if (waterVolumeDown <= 0)
	{
		vol += waterVolumeDown;
		waterVolumeDown = 0;
	}
	normalizeWater();
	return vol;
}
