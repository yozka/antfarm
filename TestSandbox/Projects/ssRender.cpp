#include "ssRender.h"

ARender::ARender()
{
}


void ARender::create(const int width, const int height)
{
	pixmap = QPixmap(width, height);
}



void ARender::draw(const Anthill::PWorld &world)
{
    

	//
	const float scale = mScale * mScaleBlock;
	//

    const auto layerGround      = world->container.findComponent< Anthill::AComponentLayerGround >();
    const auto layerWater       = world->container.findComponent< Anthill::AComponentLayerWater >();
    const auto layerTemperature = world->container.findComponent< Anthill::AComponentLayerTemperature >();

	
    const auto width = layerGround->width();
    const auto height = layerGround->height();

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

    QColor colorGround      (255, 134, 129);
    QColor colorWater       (96, 172, 247);
    QColor colorHumidity    (121, 184, 247);

    auto font = painter.font();
    auto fontSize = font.pointSizeF() * scale / 15.0f;
    font.setPointSizeF(fontSize);
    painter.setFont(font);

	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
		{
			
			//земля
			const auto &ground = layerGround->data(x, y);
			if (ground.ground)
			{
				QRectF rect(scale * x + shift, scale * y + shift, scale, scale);
				painter.fillRect(rect, colorGround);
			}

			//вода
			const auto &water = layerWater->data(x, y);
			if (water.isWater())
			{
                QRectF rect(scale * x + shift, scale * y + shift, scale, scale);
                painter.fillRect(rect, colorWater);
                if (mRenderWaterText) painter.drawText(rect, QString::number(water.waterPressure()), Qt::AlignVCenter | Qt::AlignHCenter);
			}
            else
            //влажность
            if (water.isHumidity() && mRenderHumidity)
            {
                QRectF rect(scale * x + shift, scale * y + shift, scale, scale);
                const auto value = water.humidityValue();
                colorHumidity.setAlpha(240 * value);
                painter.fillRect(rect, colorHumidity);
                if (mRenderHumidityText) painter.drawText(rect, QString::number((int)(99.0f * value)), Qt::AlignVCenter | Qt::AlignHCenter);

            }

		}


	//


    /*

	//отрисовываем букашек
	QColor colorInsect(70, 101, 119);
	for (const auto &actor : formicarium->world->actors())
	{
		painter.save();

		const auto pos = actor->position() * scale;
		const auto size = actor->size() * scale;
		float angle = actor->angle();
		QRectF rect(- (size.x * 0.5f), - (size.y * 0.5f), size.x, size.y);

		painter.translate(pos.x + shift, pos.y + shift);
		painter.rotate(angle);
		painter.fillRect(rect, colorInsect);

		painter.restore();
	}


	painter.end();

    */

}