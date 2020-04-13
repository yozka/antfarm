#include "aaComponent_WaterOrigin.h"
#include "aaComponent_Layers.h"
#include "aaComponent_Geometry.h"

#include "aaAlgo.h"

#include "ecs/aaContainer.h"
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
AComponentWaterOrigin::AComponentWaterOrigin()
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
AComponentWaterOrigin::~AComponentWaterOrigin()
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
void AComponentWaterOrigin :: update(const float timeSpan)
{
    super::update(timeSpan);

    auto container = getContainer();
    if (!container)
    {
        return;
    }


    const auto water = container->findComponent<AComponentLayerWater>();
    const auto geometry = findComponent<AComponentGeometry>();

    if (!water || !geometry)
    {
        return;
    }



    //
    mFlow -= timeSpan;
    if (mFlow > 0)
    {
        return;
    }
    mFlow = mFlowTimeMS;
    //

    const int width = water->width();
    const int height = water->height();

	const auto size = geometry->boundSize();
	const auto pt = geometry->position() - size * 0.5f;

    for (float y = pt.y; y < pt.y + size.y; y += 1.0f)
        for (float x = pt.x; x < pt.x + size.x; x += 1.0f)
        {
            const int ix = minmaxBound<int>(0, width - 1, round(x));
            const int iy = minmaxBound<int>(0, height - 1, round(y));
            auto &cell = water->data(ix, iy);
            if (!cell.isWater())
            {
                cell.pourWater();
            }
        }

}

