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
	/// ������� �������������
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


        void refreshComponents(); //����� �������� ����������



	public:



		void update(const float timeSpan);


	private:



		



	};
	///-------------------------------------------------------------------------






	///-------------------------------------------------------------------------


}
