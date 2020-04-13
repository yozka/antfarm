#pragma once
#include <memory>
#include "ecs/update/aaComponent_Update.h"

namespace Anthill
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// �������� ����
	///
	///
	///-------------------------------------------------------------------------
	class AComponentWaterOrigin
		: 
        public ecs::AComponentUpdate
	{
        using super = ecs::AComponentUpdate;

	public:

		AComponentWaterOrigin();
		~AComponentWaterOrigin() override;

	public:


		void update(const float timeSpan) override;

	private:

		float mFlowTimeMS = { 0.2f }; //����� ���������� � ���
        float mFlow = { 0.0f };

	};


	


}
