#pragma once
#include <memory>


namespace Formicarium
{
	class AActor;


	class AActorComponent
	{
	public:

		AActorComponent();
		virtual ~AActorComponent();

	public:


		virtual void update(const float timeSpan) {};

	protected:

		friend class AActor;
		void setParent(AActor *parent);


	private:

		AActor* mParent = { nullptr };


	};


	using PActorComponent = std::shared_ptr<AActorComponent>;


}
