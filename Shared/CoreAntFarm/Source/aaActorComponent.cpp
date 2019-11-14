#include "aaActorComponent.h"

using namespace Formicarium;



AActorComponent::AActorComponent()

{





}



AActorComponent::~AActorComponent()
{


}

void AActorComponent::setParent(AActor *parent)
{
	mParent = parent;
}
