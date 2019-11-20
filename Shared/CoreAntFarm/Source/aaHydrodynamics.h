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


        void fallWater(const float volume); //падение воды
        void fallWaterVertical(const float volume); //падение воды

        void pressureCalc();//просчет давления

        bool spreadingWater(); //растекание воды
	};
	///-------------------------------------------------------------------------



	using PHydrodynamics = std::shared_ptr< AHydrodynamics >;


	///-------------------------------------------------------------------------


}
