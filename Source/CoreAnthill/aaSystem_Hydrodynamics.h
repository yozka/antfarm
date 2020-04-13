#pragma once
#include <memory>

#include "ecs/aaSystem.h"
#include "aaComponent_Layers.h"

namespace Anthill
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// �������������
	///
	///
	///-------------------------------------------------------------------------
	class ASystemHydrodynamics
        :
            public ecs::ISystem
	{
	public:



        ASystemHydrodynamics();
		~ASystemHydrodynamics() override;


	public:

        void refreshComponents(); //����� �������� ����������
	

    public:

		void update(const float timeSpan);


	private:

        PComponentLayerGround       mGround;
        PComponentLayerWater        mWater;
        PComponentLayerTemperature  mTemperature;


    private:


		float mSpeedFluidVertical   = { 50 }; //�������� �������������� ����
        float mSpeedHumidity        = { 100 }; //�������� �������������� ���������
    private:


        //��������� ����
        void fallWater(); //������� ����
        void pressureCalc();//������� ��������
        bool spreadingWater(); //���������� ����
        bool spreadingWaterCell(const int x, const int y, const int direct, const ALayerGround &ground, ALayerWater &water);


        //���������
        void humidityEmitting(const float volume); //�������� ���������
        void humidityMoveTo(ACellWater &water, ACellWater &waterDest); //������������� ����� �� ����
	};
	///-------------------------------------------------------------------------



	


	///-------------------------------------------------------------------------


}
