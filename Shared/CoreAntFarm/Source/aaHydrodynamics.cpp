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

	//просчет падение воды
	for (int y = height - 2; y >= 0; y--)
		for (int x = 0; x < width; x++)
		{
			auto &waterUp	= water(x, y);
			if (waterUp.water)
			{
				//в текущей клетке есть вода
				const auto &groundDown	= ground(x, y + 1);
				auto &waterDown			= water(x, y + 1);

				if (!groundDown.ground && !waterDown.isWaterFull())
				{
					//внизу нет земли, вода может туда лится
					waterUp.waterMoveTo(timeSpan, waterDown);
				}
			}
		}



}