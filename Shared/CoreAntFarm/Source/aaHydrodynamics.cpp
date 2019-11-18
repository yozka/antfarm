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
	float volume = (1.0f / mSpeedFluidVertical) * timeSpan;

	auto &water		= mWorld->water;
	auto &ground	= mWorld->ground;

	const auto width	= mWorld->size.x;
	const auto height	= mWorld->size.y;

	//просчет падение воды
	for (int y = height - 2; y >= 0; y--)
		for (int x = 0; x < width; x++)
		{
			auto &waterTop	= water(x, y);
			if (waterTop.water && waterTop.waterVolumeDown > 0)
			{
				//в текущей клетке есть вода
				const auto &groundBottom	= ground(x, y + 1);
				auto &waterBottom			= water(x, y + 1);

				if (!groundBottom.ground && !waterBottom.waterFull)
				{
					//внизу нет земли, вода может туда лится
					waterBottom.appendWaterUp(waterTop.takeWaterDown(volume));
				}
			}
		}



}