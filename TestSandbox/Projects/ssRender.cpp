#include "ssRender.h"

ARender::ARender()
{
}


void ARender::create(const int width, const int height)
{
	pixmap = QPixmap(width, height);
}



void ARender::draw(const Formicarium::PFormicarium &formicarium)
{
	//
	const float scale = mScale * mScaleBlock;
	//

	
	const auto width	= formicarium->world->size.x;
	const auto height	= formicarium->world->size.y;

	const int pixWidth = width * scale;
	const int pixHeight = height * scale;
	if (pixmap.width() != pixWidth || pixmap.height() != pixHeight)
	{
		create(pixWidth, pixHeight);
	}
	//

	

	QPainter painter;
	painter.begin(&pixmap);
	painter.fillRect(0, 0, pixmap.width(), pixmap.height(), Qt::white);


	//отрисовываем землю
	//воду
	const float shift = -scale * 0.5f;
	QColor colorGround(255, 134, 129);
	QColor colorWater(96, 172, 247);
    auto font = painter.font();
    auto fontSize = font.pointSizeF() * scale / 15.0f;
    font.setPointSizeF(fontSize);
    painter.setFont(font);

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			
			//земля
			const auto &ground = formicarium->world->ground.data(x, y);
			if (ground.ground)
			{
				QRectF rect(scale * x + shift, scale * y + shift, scale, scale);
				painter.fillRect(rect, colorGround);
			}

			//вода
			const auto &water = formicarium->world->water(x, y);
			if (water.isWater())
			{
                QRectF rect(scale * x + shift, scale * y + shift, scale, scale);
                painter.fillRect(rect, colorWater);
                painter.drawText(rect, QString::number(water.waterPressure()), Qt::AlignVCenter | Qt::AlignHCenter);
			}
			//

		}


	//



	//отрисовываем букашек
	QColor colorInsect(70, 101, 119);
	for (const auto &actor : formicarium->world->actors())
	{
		painter.save();

		const auto pos = actor->position() * scale;
		const auto size = actor->size() * scale;
		float angle = actor->angle();
		QRectF rect(- (size.x * 0.5f), - (size.y * 0.5f), size.x, size.y);

		painter.translate(pos.x, pos.y);
		painter.rotate(angle);
		painter.fillRect(rect, colorInsect);

		painter.restore();
	}



	/*
	QPen DarkGray((QColor::QColor(69, 86, 96)), 1);
	painter.setPen(DarkGray);
	painter.drawLine(0, 0, 500, 300);
	*/

	painter.end();

}