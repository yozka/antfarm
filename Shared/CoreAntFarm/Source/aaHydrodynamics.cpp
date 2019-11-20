#include "aaHydrodynamics.h"
#include <algorithm>


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
    const float volume = (1.0f / mSpeedFluidVertical) * timeSpan;
    fallWater(volume);

    while (true)
    {
        pressureCalc();
        if (!spreadingWater())
        {
            break;
        }
    }
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// падение воды 
///
///
///-------------------------------------------------------------------------
void AHydrodynamics :: fallWater(const float volume)
{
    auto &water = mWorld->water;
    const auto &ground = mWorld->ground;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;


    //просчет падение воды
    for (int y = height - 2; y >= 0; y--)
        for (int x = 0; x < width; x++)
        {
            auto &waterTop = water(x, y);
            if (waterTop.waterFluid(volume))
            {
                //в текущей клетке есть вода
                //которая может перетекать
                const auto &groundBottom = ground(x, y + 1);
                auto &waterBottom = water(x, y + 1);

                if (!groundBottom.ground && !waterBottom.isWater())
                {
                    //внизу нет земли, вода может туда лится
                    waterTop.takeWater();
                    waterBottom.makeWater();
                }
            }
        }
    //
}
///-------------------------------------------------------------------------







///------------------------------------------------------------------------
///
///
///
/// падение воды 
///
///
///-------------------------------------------------------------------------
void AHydrodynamics::fallWaterVertical(const float volume)
{
    auto &water = mWorld->water;
    const auto &ground = mWorld->ground;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;


    //просчет падение воды
    for (int y = height - 2; y >= 0; y--)
        for (int x = 0; x < width; x++)
        {
            auto &waterTop = water(x, y);
            if (waterTop.waterFluid(volume))
            {
                //в текущей клетке есть вода
                //которая может перетекать
                const auto &groundBottom = ground(x, y + 1);
                auto &waterBottom = water(x, y + 1);

                if (!groundBottom.ground && !waterBottom.isWater())
                {
                    //внизу нет земли, вода может туда лится
                    waterTop.takeWater();
                    waterBottom.makeWater();
                }
            }
        }
    //
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// просчет давления
///
///
///-------------------------------------------------------------------------
void AHydrodynamics :: pressureCalc()
{
    auto &water = mWorld->water;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;

    //просчет водяного давления
    for (int x = 0; x < width; x++)
    {
        int pressure = 0;
        for (int y = 0; y < height; y++)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWaterFluid())
            {
                //вода полностью норм
                pressure++;
                waterCenter.makePressure(pressure);
            }
            else
            {
                pressure = 0;
            }
        }
    }
    //просчет давления по горизонтали
    for (int y = 0; y < height; y++)
    {
        //просчет давление слева на право
        int pressureMax = 0;
        for (int x = 0; x < width; x++)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWaterFluid())
            {
                //вода полностью норм
                pressureMax = std::max(waterCenter.waterPressure(), pressureMax);
                waterCenter.makePressure(pressureMax);
            }
            else
            {
                pressureMax = 0;
            }
        }

        //просчет давление справо на лево
        pressureMax = 0;
        for (int x = width - 1; x >= 0; x--)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWaterFluid())
            {
                //вода полностью норм
                pressureMax = std::max(waterCenter.waterPressure(), pressureMax);
                waterCenter.makePressure(pressureMax);
            }
            else
            {
                pressureMax = 0;
            }
        }

    }

}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// растекание воды
///
///
///-------------------------------------------------------------------------
bool AHydrodynamics::spreadingWater()
{
    bool process = false;
    auto &water = mWorld->water;
    const auto &ground = mWorld->ground;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;

    //растекание воды, с давлением больше 1
    for (int y = height - 2; y > 0; y--)
        for (int x = 1; x < width - 1; x++)
        {
            auto &waterCenter = water(x, y);
            if (!waterCenter.isWaterFluid())
            {
                continue;
            }

            if (waterCenter.waterPressure() <= 1)
            {
                //сминимальным давлением
                continue;
            }


            //сниузу есть земля можно растекатся
            //растекаемся справа
            auto &waterRight = water(x + 1, y);
            auto &groundRight = ground(x + 1, y);
            auto &waterRightBottom = water(x + 1, y + 1);
            auto &groundRightBottom = ground(x + 1, y + 1);
            if ((!waterRight.isWater() && !groundRight.ground) &&
                (waterRightBottom.isWaterFluid() || groundRightBottom.ground)
                )
            {
                waterCenter.takeWater();
                waterRight.makeWater();
                process = true;
            }

        }

 

    //растекание воды, с давлением больше 1
    for (int y = height - 2; y > 0; y--)
        for (int x = width - 2; x > 0; x--)
        {
            auto &waterCenter = water(x, y);
            if (!waterCenter.isWaterFluid())
            {
                continue;
            }

            if (waterCenter.waterPressure() <= 1)
            {
                //сминимальным давлением
                continue;
            }

            //слева
            //сниузу есть земля можно растекатся
            auto &waterLeft = water(x - 1, y);
            auto &groundLeft = ground(x - 1, y);
            auto &waterLeftBottom = water(x - 1, y + 1);
            auto &groundLeftBottom = ground(x - 1, y + 1);
            if ((!waterLeft.isWater() && !groundLeft.ground) &&
                (waterLeftBottom.isWaterFluid() || groundLeftBottom.ground)
                )
            {
                waterCenter.takeWater();
                waterLeft.makeWater();
                process = true;
            }
        }

    return process;
}