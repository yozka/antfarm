#include "aaSystem_Hydrodynamics.h"
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
ASystemHydrodynamics::ASystemHydrodynamics()
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
ASystemHydrodynamics :: ~ASystemHydrodynamics()
{


}
///-------------------------------------------------------------------------







 ///------------------------------------------------------------------------
///
///
///
/// ����� �������� ���������� 
///
///
///-------------------------------------------------------------------------
void ASystemHydrodynamics::refreshComponents()
{
    mGround         = container->findComponent<AComponentLayerGround>();
    mWater          = container->findComponent<AComponentLayerWater>();
    mTemperature    = container->findComponent<AComponentLayerTemperature>();



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
void ASystemHydrodynamics::update(const float timeSpan)
{
    updatingSystem();

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
void ASystemHydrodynamics:: fallWater()
{
    if (!mWater || !mGround)
    {
        return;
    }

    auto &water = *mWater;
    const auto &ground = *mGround;

    const auto width = water.width();
    const auto height = water.height();


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
void ASystemHydrodynamics:: pressureCalc()
{
    if (!mWater)
    {
        return;
    }

    auto &water = *mWater;

    const auto width = water.width();
    const auto height = water.height();

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
bool ASystemHydrodynamics::spreadingWater()
{
    if (!mWater || !mGround)
    {
        return false;
    }


    bool process = false;
    auto &water = *mWater;
    const auto &ground = *mGround;

    const auto width = water.width();
    const auto height = water.height();

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
bool ASystemHydrodynamics::spreadingWaterCell(const int x, const int y, const int direct, const ALayerGround &ground, ALayerWater &water)
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
void ASystemHydrodynamics :: humidityEmitting(const float volume)
{
    if (!mWater)
    {
        return;
    }

    auto &water = *mWater;

    const auto width = water.width() - 1;
    const auto height = water.height() - 1;

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
void ASystemHydrodynamics :: humidityMoveTo(ACellWater &water, ACellWater &waterDest)
{


}