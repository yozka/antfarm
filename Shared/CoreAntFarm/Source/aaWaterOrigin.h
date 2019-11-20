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
	/// �������� ����
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

		float mFlowTimeMS = { 400 }; //����� ���������� � ��
        float mFlow = { 0 };

	};


	


}
