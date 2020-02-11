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

		float mFlowTimeMS = { 200 }; //����� ���������� � ��
        float mFlow = { 0 };

	};


	


}
