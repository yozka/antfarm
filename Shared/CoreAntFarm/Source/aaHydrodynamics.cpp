#include "aaHydrodynamics.h"



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
AHydrodynamics::AHydrodynamics(const PWorld &world)
	:	
		mWorld(world)
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
AHydrodynamics :: ~AHydrodynamics()
{


}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Update 
///
///
///-------------------------------------------------------------------------
void AHydrodynamics::update(const float timeSpan)
{
	auto &water		= mWorld->water;
	auto &ground	= mWorld->ground;

	const auto width	= mWorld->size.x;
	const auto height	= mWorld->size.y;

	//������� ������� ����
	for (int y = height - 2; y >= 0; y--)
		for (int x = 0; x < width; x++)
		{
			auto &waterUp	= water(x, y);
			if (waterUp.water)
			{
				//� ������� ������ ���� ����
				const auto &groundDown	= ground(x, y + 1);
				auto &waterDown			= water(x, y + 1);

				if (!groundDown.ground && !waterDown.isWaterFull())
				{
					//����� ��� �����, ���� ����� ���� �����
					waterUp.waterMoveTo(timeSpan, waterDown);
				}
			}
		}



}