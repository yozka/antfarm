#include "aaFormicarium.h"

using namespace Formicarium;



AFormicarium::AFormicarium(const int width, const int height)
	:
	mSize		({ width, height }),
	mWorld		(mSize),

	world		(mWorld)
{




}



AFormicarium::~AFormicarium()
{


}


void AFormicarium :: append(const PActor &actor)
{
	mActors.push_back(actor);
}




void AFormicarium :: update(const float timeSpan)
{
	for (const auto &actor : mActors)
	{
		actor->update(timeSpan);
	}

}