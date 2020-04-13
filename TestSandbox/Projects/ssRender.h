#pragma once
#include <QPixmap>
#include <QPainter>
#include "../../Source/CoreAnthill/CoreAnthill.h"

class ARender
{
public:

	ARender();

	QPixmap pixmap;


public:

	void draw(const Anthill::PWorld &world);
	

    void setRenderWaterText(const bool value) { mRenderWaterText = value; }

private:



	void create(const int width, const int height);


	float mScale		= { 1.0f };
	float mScaleBlock	= { 10.0f };


    bool mRenderWaterText       = { false };
    
    bool mRenderHumidity        = { false };
    bool mRenderHumidityText    = { false };

};
