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
    /// ��������� ����������� �������
    ///
    ///
    ///-------------------------------------------------------------------------
    class AComponentGeometry
        :
        public ecs::AComponent
    {
        using super = ecs::AComponent;

    public:


        virtual TPointF position()  const = 0; //����������� ������� �������
        virtual TPointF boundSize() const = 0; //���������� ������ �������
        virtual float   angle()     const = 0; //������� �������

    

    };


    


}
