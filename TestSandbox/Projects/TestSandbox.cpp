#include "TestSandbox.h"



void roomRect(const Formicarium::PFormicarium &form, const int x, const int y, const int w, const int h)
{
	int sx = x - w * 0.5f;
	int sy = y - h * 0.5f;
	for (int j = sy; j < sy + h; j++)
		for (int i = sx; i < sx + w; i++)
		{
			auto &data = form->world.ground(i, j);
			data.ground = false;
		}

}


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
			auto &data = mFormicarium->world.ground(x, y);
			data.ground = true;
		}

	roomRect(mFormicarium, 50, 35, 20, 10);


	//ху€рим букашек
	auto actor = std::make_shared<Formicarium::AActor>();
	actor->setPosition({ 50, 35 });
	mFormicarium->append(actor);


	//ху€рим источник влаги
	auto aqua = std::make_shared<Formicarium::AActor>();
	aqua->append(std::make_shared<Formicarium::AWaterOrigin>());
	aqua->setPosition({ 30, 60 });
	mFormicarium->append(aqua);


	startTimer(100);
}






void TestSandbox::timerEvent(QTimerEvent * event)
{
	mFormicarium->update(100);

	mRender.draw(mFormicarium);
	ui.canvas->setPixmap(mRender.pixmap);

}