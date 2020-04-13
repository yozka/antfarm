#pragma once
#include <memory>
#include "ecs/aaComponent.h"
#include "aaPoint.h"

namespace Anthill
{
    ///-------------------------------------------------------------------------





     ///------------------------------------------------------------------------
    ///
    ///
    ///
    /// Геометрия физического объекта
    ///
    ///
    ///-------------------------------------------------------------------------
    class AComponentGeometry
        :
        public ecs::AComponent
    {
        using super = ecs::AComponent;

    public:


        virtual TPointF position()  const = 0; //центральная позиция объекта
        virtual TPointF boundSize() const = 0; //занимающий размер объекта
        virtual float   angle()     const = 0; //поворот объекта

    

    };


    


}
