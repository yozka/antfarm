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

const int timerSpeed = 100;

TestSandbox::TestSandbox(QWidget *parent)
	: 
		QMainWindow(parent)
{
	ui.setupUi(this);




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

	//ху€рим букашек
	auto actor = std::make_shared<Formicarium::AActor>();
	actor->setPosition({ 50, 35 });
	mFormicarium->world->append(actor);


	//ху€рим источник влаги
	auto aqua = std::make_shared<Formicarium::AActor>();
	aqua->append(std::make_shared<Formicarium::AWaterOrigin>());
	aqua->setPosition({ 30, 55 });
	aqua->setSize(0.5f);
	mFormicarium->world->append(aqua);


	startTimer(timerSpeed);
}






void TestSandbox::timerEvent(QTimerEvent * event)
{
	mFormicarium->update(timerSpeed);

	mRender.draw(mFormicarium);
	ui.canvas->setPixmap(mRender.pixmap);

}