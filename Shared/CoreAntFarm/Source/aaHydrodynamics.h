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



	};
	///-------------------------------------------------------------------------



	using PHydrodynamics = std::shared_ptr< AHydrodynamics >;


	///-------------------------------------------------------------------------


}
