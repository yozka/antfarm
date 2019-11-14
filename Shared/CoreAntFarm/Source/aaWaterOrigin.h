#pragma once
#include <memory>
#include "aaActorComponent.h"

namespace Formicarium
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

		float mFlowFactor = { 1.0 };


	};


	


}
