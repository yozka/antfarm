#pragma once
#include <memory>
#include <vector>

#include "aaPoint.h"

#include "ecs/aaContainer.h"
#include "ecs/update/aaSystem_Update.h"

#include "aaSystem_Hydrodynamics.h"
#include "aaSystem_Termodynamics..h"



namespace Anthill
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// Мир муровьев
	///
	///
	///-------------------------------------------------------------------------
	class AWorld
	{
	///-------------------------------------------------------------------------
	public:

		AWorld();
		virtual ~AWorld();


	///-------------------------------------------------------------------------
	public:



        ecs::AContainer     &container;


	///-------------------------------------------------------------------------
	public:


		void update(const float timeSpan);



	///-------------------------------------------------------------------------
	public:





	///-------------------------------------------------------------------------
	private:

        ecs::AContainer         mContainer;

        //системы
        ecs::ASystemUpdate      mSystemUpdate;
        ASystemHydrodynamics    mSystemHydrodynamics;
        ASystemTermodynamics    mSystemTermodynamics;


		

	};
	///-------------------------------------------------------------------------


	using PWorld = std::shared_ptr< AWorld >;

	///-------------------------------------------------------------------------

}
