#include "aaWaterOrigin.h"
#include "aaActor.h"
#include "aaWorld.h"
///-------------------------------------------------------------------------




///-------------------------------------------------------------------------
using namespace Formicarium;
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Constructor
///
///
///-------------------------------------------------------------------------
AWaterOrigin::AWaterOrigin()
{





}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Destructor
///
///
///-------------------------------------------------------------------------
AWaterOrigin::~AWaterOrigin()
{


}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// ����������
///
///
///-------------------------------------------------------------------------
void AWaterOrigin :: update(const float timeSpan)
{
	const auto parent = actor();
	if (!parent)
	{
		return;
	}
	const auto world = parent->world();
	if (!world)
	{
		return;
	}
	//

	const auto size = parent->size();
	const auto pt = parent->position();// -size * 0.5f;

	auto &water = world->water(pt.x, pt.y);

	const float factor = 1.0f / mFlowTimeMS;
	water.appendWater(factor * timeSpan);

}

