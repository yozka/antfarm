#pragma once
#include <memory>
#include "aaComponent_Geometry.h"

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
    class AComponentGeometryData
        :
        public AComponentGeometry
    {
        using super = AComponentGeometry;

    public:

        AComponentGeometryData(const TPointF &position = TPointF::Zero, const TPointF &boundSize = TPointF::Zero, const float angle = 0.0f);

    public:

        TPointF position()  const override; //����������� ������� �������
        TPointF boundSize() const override; //���������� ������ �������
        float   angle()     const override; //������� �������

    private:

        TPointF mPosition   = { 0.0f, 0.0f};
        TPointF mBoundSize  = { 0.0f, 0.0f};
        float   mAngle      = { 0.0f };

    };





}
