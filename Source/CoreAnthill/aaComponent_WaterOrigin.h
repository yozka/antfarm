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
	/// Источник воды
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

		float mFlowTimeMS = { 0.2f }; //время заполнения в сек
        float mFlow = { 0.0f };

	};


	


}
