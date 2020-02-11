#pragma once
#include <memory>

#include "aaWorld.h"
#include "aaCellWater.h"
#include "aaCellGround.h"

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
	class AHydrodynamics
	{
	public:



		AHydrodynamics(const PWorld &world);
		virtual ~AHydrodynamics();


	public:


	


	public:




		void update(const float timeSpan);


	private:



		PWorld mWorld;

		float mSpeedFluidVertical   = { 50 }; //скорость распостранения вниз
        float mSpeedHumidity        = { 100 }; //скорость распостранения влажности
    private:


        //поведение воды
        void fallWater(); //падение воды
        void pressureCalc();//просчет давления
        bool spreadingWater(); //растекание воды
        bool spreadingWaterCell(const int x, const int y, const int direct, const AWorld::ALayerGround &ground, AWorld::ALayerWater &water);


        //влажность
        void humidityEmitting(const float volume); //пересчет влажности
        void humidityMoveTo(ACellWater &water, ACellWater &waterDest); //устанавливаем влагу из воды
	};
	///-------------------------------------------------------------------------



	using PHydrodynamics = std::shared_ptr< AHydrodynamics >;


	///-------------------------------------------------------------------------


}
