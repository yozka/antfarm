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

	//������� ������� ����
	for (int y = height - 2; y >= 0; y--)
		for (int x = 0; x < width; x++)
		{
			auto &waterTop	= water(x, y);
			if (waterTop.waterFluid(volume))
			{
				//� ������� ������ ���� ����
                //������� ����� ����������
                const auto &groundBottom = ground(x, y + 1);
                auto &waterBottom = water(x, y + 1);

                if (!groundBottom.ground && !waterBottom.isWater())
                {
                    //����� ��� �����, ���� ����� ���� �����
                    waterTop.takeWater();
                    waterBottom.makeWater();
                }
			}
		}

    //������� ���������� ����
    for (int y = 1; y < height - 1; y++)
        for (int x = 1; x < width - 1; x++)
        {
            auto &waterCenter = water(x, y);
            if (!waterCenter.isWaterFluid())
            {
                continue;
            }

            auto &waterTop = water(x, y - 1);
            if (!waterTop.isWaterFluid())
            {
                continue;
            }

            auto &groundBottom = ground(x, y + 1);
            if (!groundBottom.ground)
            {
                continue;
            }

            //������ ���� ����� ����� ����������
            //����������� �����
            auto &waterLeft = water(x - 1, y);
            auto &groundLeft = ground(x - 1, y);
            if (!waterLeft.isWater() && !groundLeft.ground)
            {
                waterCenter.takeWater();
                waterLeft.makeWater();
                continue;
            }
            //

            //����������� ������
            auto &waterRight = water(x + 1, y);
            auto &groundRight = ground(x + 1, y);
            if (!waterRight.isWater() && !groundRight.ground)
            {
                waterCenter.takeWater();
                waterRight.makeWater();
                continue;
            }
           

        }

}