#include "aaHydrodynamics.h"
#include <algorithm>


///-------------------------------------------------------------------------
using namespace Anthill;
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
/// ������� ����, � ��������� 
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
        pressureCalc();//������� ��������
        if (!spreadingWater()) //����������
        {
            break;
        }
    }

    //������ ���������
    const float volumeHumidity = (1.0f / mSpeedHumidity) * timeSpan;
    humidityEmitting(volumeHumidity);
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// ������� ���� 
///
///
///-------------------------------------------------------------------------
void AHydrodynamics :: fallWater()
{
    auto &water = mWorld->water;
    const auto &ground = mWorld->ground;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;


    //������� ������� ����
    for (int y = height - 2; y >= 0; y--)
        for (int x = 0; x < width; x++)
        {
            auto &waterTop = water(x, y);
            if (waterTop.isWater())
            {
                //� ������� ������ ���� ����
                //������� ����� ����������
                const auto &groundBottom = ground(x, y + 1);
                auto &waterBottom = water(x, y + 1);

                if (!groundBottom.ground && !waterBottom.isWater())
                {
                    //����� ��� �����, ���� ����� ���� �����
                    waterTop.moveWaterTo(waterBottom);
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
/// ������� ��������
///
///
///-------------------------------------------------------------------------
void AHydrodynamics :: pressureCalc()
{
    auto &water = mWorld->water;

    const auto width = mWorld->size.x;
    const auto height = mWorld->size.y;

    //������� �������� ��������
    for (int x = 0; x < width; x++)
    {
        int pressure = 0;
        for (int y = 0; y < height; y++)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWater())
            {
                //���� ��������� ����
                pressure++;
                waterCenter.makePressure(pressure);
            }
            else
            {
                pressure = 0;
            }
        }
    }
    //������� �������� �� �����������
    for (int y = 0; y < height; y++)
    {
        //������� �������� ����� �� �����
        int pressureMax = 0;
        for (int x = 0; x < width; x++)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWater())
            {
                //���� ��������� ����
                pressureMax = std::max(waterCenter.waterPressure(), pressureMax);
                waterCenter.makePressure(pressureMax);
            }
            else
            {
                pressureMax = 0;
            }
        }

        //������� �������� ������ �� ����
        pressureMax = 0;
        for (int x = width - 1; x >= 0; x--)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWater())
            {
                //���� ��������� ����
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
/// ���������� ����
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

    //���������� ����
    for (int y = height - 2; y > 0; y--)
        for (int x = 1; x < width - 1; x++)
        {
            //�������
            process |= spreadingWaterCell(x, y, +1, ground, water);
        }

 

    for (int y = height - 2; y > 0; y--)
        for (int x = width - 2; x > 0; x--)
        {
            //�� ����
            process |= spreadingWaterCell(x, y, -1, ground, water);
        }

    return process;
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// ���������� ����
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
        //������������ ���������
        return false;
    }

    //������ ���� ����� ����� ����������
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
        //����� �������, ��� ���� � �����
        //������� ����� ����� ������ �������
        auto &waterBottom = water(x, y + 1);
        auto &groundBottom = ground(x, y + 1);
        if (!waterBottom.isWater() && !groundBottom.ground)
        {

            return false;
        }
    }

    waterCenter.moveWaterTo(waterSide);
    return true;
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// �������� ���������
/// ����������� ���� �� �����
///
///-------------------------------------------------------------------------
void AHydrodynamics :: humidityEmitting(const float volume)
{
    auto &water = mWorld->water;

    const auto width = mWorld->size.x - 1;
    const auto height = mWorld->size.y - 1;

    //���� ������ ���� ���������
    for (int x = 1; x < width; x++)
    {
        for (int y = 1; y < height; y++)
        {
            auto &waterCenter = water(x, y);
            if (waterCenter.isWater())
            {
                humidityMoveTo(waterCenter, water(x - 1, y));
                humidityMoveTo(waterCenter, water(x + 1, y));
                humidityMoveTo(waterCenter, water(x    , y - 1));
                humidityMoveTo(waterCenter, water(x    , y + 1));
            }
        }
    }
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// �������� ���������
/// ������������� ����� �� ����
///
///-------------------------------------------------------------------------
void AHydrodynamics::humidityMoveTo(ACellWater &water, ACellWater &waterDest)
{


}