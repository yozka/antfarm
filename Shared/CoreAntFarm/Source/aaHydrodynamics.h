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
	/// √идродинамика
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

		float mSpeedFluidVertical = { 100 }; //скорость распостранени€ вниз

	};
	///-------------------------------------------------------------------------



	using PHydrodynamics = std::shared_ptr< AHydrodynamics >;


	///-------------------------------------------------------------------------


}
