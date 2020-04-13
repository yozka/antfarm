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
	/// Гидродинамика
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

        void refreshComponents(); //нужно изменить компаненты
	

    public:

		void update(const float timeSpan);


	private:

        PComponentLayerGround       mGround;
        PComponentLayerWater        mWater;
        PComponentLayerTemperature  mTemperature;


    private:


		float mSpeedFluidVertical   = { 0.05f }; //скорость распостранения вниз
        float mSpeedHumidity        = { 0.10f }; //скорость распостранения влажности
    private:


        //поведение воды
        void fallWater(); //падение воды
        void pressureCalc();//просчет давления
        bool spreadingWater(); //растекание воды
        bool spreadingWaterCell(const int x, const int y, const int direct, const ALayerGround &ground, ALayerWater &water);


        //влажность
        void humidityEmitting(const float volume); //пересчет влажности
        void humidityMoveTo(ACellWater &water, ACellWater &waterDest); //устанавливаем влагу из воды
	};
	///-------------------------------------------------------------------------



	


	///-------------------------------------------------------------------------


}
