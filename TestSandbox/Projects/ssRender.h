#pragma once
#include <QPixmap>
#include <QPainter>
#include "CoreAntFarm.h"

class ARender
{
public:

	ARender();

	QPixmap pixmap;


public:

	void draw(const Formicarium::PFormicarium &formicarium);
	

private:



	void create(const int width, const int height);


	float mScale		= { 1.0f };
	float mScaleBlock	= { 10.0f };



};
