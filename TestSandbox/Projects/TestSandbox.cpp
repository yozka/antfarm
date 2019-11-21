#include "TestSandbox.h"



void roomRect(const Formicarium::PWorld &world, const int x, const int y, const int w, const int h)
{
	int sx = x - w * 0.5f;
	int sy = y - h * 0.5f;
	for (int j = sy; j < sy + h; j++)
		for (int i = sx; i < sx + w; i++)
		{
			auto &data = world->ground(i, j);
			data.ground = false;
		}

}

const int timerSpeed = 60;

TestSandbox::TestSandbox(QWidget *parent)
	: 
		QMainWindow(parent)
{
	ui.setupUi(this);
    ui.mainToolBar->addAction(ui.actionWaterPressure);



	int w = 190;
	int h = 90;

	mFormicarium = std::make_shared<Formicarium::AFormicarium>(w, h);


	//рандомно создадим формикарий
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
		{
			auto &data = mFormicarium->world->ground(x, y);
			data.ground = true;
		}

	roomRect(mFormicarium->world, 50, 35, 20, 10);
	roomRect(mFormicarium->world, 30, 60, 10, 30);
    roomRect(mFormicarium->world, 50, 72, 40, 6);
    roomRect(mFormicarium->world, 20, 80, 15, 13);


	//ху€рим букашек
	auto actor = std::make_shared<Formicarium::AActor>();
	actor->setPosition({ 50, 35 });
	mFormicarium->world->append(actor);


	//ху€рим источник влаги
	auto aqua = std::make_shared<Formicarium::AActor>();
	aqua->append(std::make_shared<Formicarium::AWaterOrigin>());
	aqua->setPosition({ 30, 55 });
	aqua->setSize(2.0f);
	mFormicarium->world->append(aqua);


    //вода
    for (int i = 0; i < 8; i++)
    {
        auto &data1 = mFormicarium->world->water(27+i, 60);
        data1.makeWater();

        auto &data2 = mFormicarium->world->water(50 + i, 70);
        data2.makeWater();
    }

	startTimer(timerSpeed);
}






void TestSandbox::timerEvent(QTimerEvent * event)
{
	mFormicarium->update(timerSpeed);

	mRender.draw(mFormicarium);
	ui.canvas->setPixmap(mRender.pixmap);

}




void TestSandbox::on_actionWaterPressure_triggered(const bool value)
{
    mRender.setRenderWaterText(value);

}