#pragma once
#include <memory>

#include "ecs/aaSystem.h"


namespace Anthill
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// Система термодинамики
	///
	///
	///-------------------------------------------------------------------------
	class ASystemTermodynamics
        :
        public ecs::ISystem
	{
	public:

		

        ASystemTermodynamics();
		~ASystemTermodynamics() override;


	public:


        void refreshComponents(); //нужно изменить компаненты



	public:



		void update(const float timeSpan);


	private:



		



	};
	///-------------------------------------------------------------------------






	///-------------------------------------------------------------------------


}
