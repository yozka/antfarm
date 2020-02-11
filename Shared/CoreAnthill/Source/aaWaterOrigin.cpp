#include "aaWaterOrigin.h"
#include "aaActor.h"
#include "aaWorld.h"
#include "aaAlgo.h"
///-------------------------------------------------------------------------




///-------------------------------------------------------------------------
using namespace Anthill;
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
/// Обновление
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


    //
    mFlow -= timeSpan;
    if (mFlow > 0)
    {
        return;
    }
    mFlow = mFlowTimeMS;
    //

    const int width = world->size.x;
    const int height = world->size.y;

	const auto size = parent->size();
	const auto pt = parent->position() - size * 0.5f;

    for (float y = pt.y; y < pt.y + size.y; y += 1.0f)
        for (float x = pt.x; x < pt.x + size.x; x += 1.0f)
        {
            const int ix = minmaxBound<int>(0, width - 1, round(x));
            const int iy = minmaxBound<int>(0, height - 1, round(y));
            auto &water = world->water(ix, iy);
            if (!water.isWater())
            {
                water.pourWater();
            }
        }
}

