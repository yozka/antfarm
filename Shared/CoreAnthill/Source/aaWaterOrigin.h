#pragma once
#include <memory>
#include "aaActorComponent.h"

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
	class AWaterOrigin
		: 
			public AActorComponent
	{
	public:

		AWaterOrigin();
		~AWaterOrigin() override;

	public:


		void update(const float timeSpan) override;

	private:

		float mFlowTimeMS = { 200 }; //время заполнения в мс
        float mFlow = { 0 };

	};


	


}
