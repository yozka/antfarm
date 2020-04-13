#pragma once
#include <memory>
#include "ecs/aaComponentHandler.h"

#include "aaLayer.h"
#include "aaCellGround.h"
#include "aaCellTemperature.h"
#include "aaCellWater.h"

namespace Anthill
{
    ///-------------------------------------------------------------------------





     ///------------------------------------------------------------------------
    ///
    ///
    ///
    /// Компанентная система
    ///
    ///
    ///-------------------------------------------------------------------------


    using ALayerGround      = ALayer< ACellGround >;
    using ALayerWater       = ALayer< ACellWater >;
    using ALayerTemperature = ALayer< ACellTemperature >;




    using AComponentLayerGround         = ecs::AComponentHandler< ALayerGround >;
    using AComponentLayerWater          = ecs::AComponentHandler< ALayerWater >;
    using AComponentLayerTemperature    = ecs::AComponentHandler< ALayerTemperature >;


    using PComponentLayerGround         = std::shared_ptr< AComponentLayerGround >;
    using PComponentLayerWater          = std::shared_ptr< AComponentLayerWater >;
    using PComponentLayerTemperature    = std::shared_ptr< AComponentLayerTemperature >;



}
