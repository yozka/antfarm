#pragma once
#include <memory>

#include "aaWorld.h"


namespace Formicarium
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

		float mSpeedFluidVertical = { 50 }; //скорость распостранения вниз

    private:


        void fallWater(); //падение воды
        void pressureCalc();//просчет давления
        bool spreadingWater(); //растекание воды
        bool spreadingWaterCell(const int x, const int y, const int direct, const AWorld::ALayerGround &ground, AWorld::ALayerWater &water);


        void humidityEmitting(const float volume); //пересчет влажности
	};
	///-------------------------------------------------------------------------



	using PHydrodynamics = std::shared_ptr< AHydrodynamics >;


	///-------------------------------------------------------------------------


}
