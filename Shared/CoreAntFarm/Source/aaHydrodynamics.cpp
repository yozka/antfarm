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
    fallWater();

    int count = 10;

    while (count--)
    {
        pressureCalc();
        if (!spreadingWater())
        {
            break;
        }
    }

    humidityEmitting(volume);
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
void AHydrodynamics :: fallWater()
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
            if (waterTop.isWater())
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
            if (waterCenter.isWater())
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
            if (waterCenter.isWater())
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
            if (waterCenter.isWater())
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

    //растекание воды
    for (int y = height - 2; y > 0; y--)
        for (int x = 1; x < width - 1; x++)
        {
            //направо
            process |= spreadingWaterCell(x, y, +1, ground, water);
        }

 

    for (int y = height - 2; y > 0; y--)
        for (int x = width - 2; x > 0; x--)
        {
            //на лево
            process |= spreadingWaterCell(x, y, -1, ground, water);
        }

    return process;
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
bool AHydrodynamics::spreadingWaterCell(const int x, const int y, const int direct, const AWorld::ALayerGround &ground, AWorld::ALayerWater &water)
{
    auto &waterCenter = water(x, y);
    if (!waterCenter.isWater())
    {
        return false;
    }

    if (waterCenter.waterPressure() <= 1)
    {
        //сминимальным давлением
        return false;
    }

    //сниузу есть земля можно растекатся
    auto &waterSide         = water(x + direct, y);
    auto &groundSide        = ground(x + direct, y);
    auto &waterSideBottom   = water(x + direct, y + 1);
    auto &groundSideBottom  = ground(x + direct, y + 1);
    
    if (waterSide.isWater())
    {
        return false;
    }
        
    if (groundSide.ground)
    {
        return false;
    }

    
    if (!waterSideBottom.isWater() && !groundSideBottom.ground)
    {
        //сбоку пустота, нет воды и земли
        //смотрим чтобы снизу небыло пустоты
        auto &waterBottom = water(x, y + 1);
        auto &groundBottom = ground(x, y + 1);
        if (!waterBottom.isWater() && !groundBottom.ground)
        {

            return false;
        }
    }

    waterCenter.takeWater();
    waterSide.makeWater();

    return true;
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// пересчет влажности
///
///
///-------------------------------------------------------------------------
void AHydrodynamics :: humidityEmitting(const float volume)
{
    auto &water = mWorld->water;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;

    //вода отдает свою влжаность
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWater())
            {


            }
        }
    }
}