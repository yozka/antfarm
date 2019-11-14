#include "aaActor.h"

using namespace Formicarium;



AActor::AActor()
{





}



AActor::~AActor()
{
	for (const auto &obj : mComponents)
	{
		obj->setParent(nullptr);
	}
	mComponents.clear();
}


void AActor::setPosition(const TPointF &pt)
{
	mPosition = pt;
}


void AActor::append(const PActorComponent &component)
{
	component->setParent(this);
	mComponents.push_back(component);
}

void AActor::remove(const PActorComponent &component)
{
	const auto item = std::find(mComponents.cbegin(), mComponents.cend(), component);
	if (item != mComponents.cend())
	{
		component->setParent(nullptr);
		mComponents.erase(item);
	}
}



void AActor::update(const float timeSpan)
{
	for (const auto &component : mComponents)
	{
		component->update(timeSpan);
	}
}