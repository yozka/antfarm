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
/// ������� ���� 
///
///
///-------------------------------------------------------------------------
void AHydrodynamics :: fallWater(const float volume)
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
    //
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
void AHydrodynamics::fallWaterVertical(const float volume)
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
            if (waterCenter.isWaterFluid())
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
            if (waterCenter.isWaterFluid())
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
            if (waterCenter.isWaterFluid())
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

    //���������� ����, � ��������� ������ 1
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
                //������������ ���������
                continue;
            }


            //������ ���� ����� ����� ����������
            //����������� ������
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

 

    //���������� ����, � ��������� ������ 1
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
                //������������ ���������
                continue;
            }

            //�����
            //������ ���� ����� ����� ����������
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