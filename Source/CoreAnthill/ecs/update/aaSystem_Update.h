#pragma once
#include <memory>

#include "../aaSystem.h"
#include "aaComponent_Update.h"


namespace ecs
{
    ///-------------------------------------------------------------------------
    ///-------------------------------------------------------------------------






     ///------------------------------------------------------------------------
    ///
    ///
    ///
    /// Система которая работает над компанентами
    ///
    ///
    ///-------------------------------------------------------------------------
    class ASystemUpdate
            :
                public ASystem<AComponentUpdate>
    {
    public:


        ASystemUpdate(const float timeSlow);
        ~ASystemUpdate() override;



        ///-------------------------------------------------------------------------
    
    public:


        void update(const float timeSpan);




        ///-------------------------------------------------------------------------

    private:

        const float         mTimeSlow   = { 0 };
        float               mTime       = { 0 }; //время медленного обновления


    };
    ///-------------------------------------------------------------------------




}
