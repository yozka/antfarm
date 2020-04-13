#include "TestSandbox.h"


/*
void roomRect(const Anthill::PWorld &world, const int x, const int y, const int w, const int h)
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
*/

const int timerSpeed = 60;

TestSandbox::TestSandbox(QWidget *parent)
	: 
		QMainWindow(parent)
{
	ui.setupUi(this);
    ui.mainToolBar->addAction(ui.actionWaterPressure);



    const TPoint size = { 190, 90 };



    mWorld = std::make_shared<Anthill::AWorld>();


    auto ground = mWorld->container.append(std::make_shared<ecs::AActor>());
    ground->append(std::make_shared < Anthill::AComponentLayerGround > (size));
    ground->append(std::make_shared < Anthill::AComponentLayerWater > (size));
    ground->append(std::make_shared < Anthill::AComponentLayerTemperature > (size));
    

    




    /* fix
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
	auto actor = std::make_shared<Anthill::AActor>();
	actor->setPosition({ 50, 35 });
	mFormicarium->world->append(actor);


	//ху€рим источник влаги
	auto aqua = std::make_shared<Anthill::AActor>();
	aqua->append(std::make_shared<Anthill::AComponentWaterOrigin>());
	aqua->setPosition({ 30, 55 });
	aqua->setSize(2.0f);
	mFormicarium->world->append(aqua);


    //вода
    for (int i = 0; i < 8; i++)
    {
        auto &data1 = mFormicarium->world->water(27 + i, 60);
        data1.pourWater();

        auto &data2 = mFormicarium->world->water(50 + i, 70);
        data2.pourWater();
    }
    */


	startTimer(timerSpeed);
}






void TestSandbox::timerEvent(QTimerEvent * event)
{
	mWorld->update(timerSpeed / 1000.0f);

	mRender.draw(mWorld);
	ui.canvas->setPixmap(mRender.pixmap);

}




void TestSandbox::on_actionWaterPressure_triggered(const bool value)
{
    mRender.setRenderWaterText(value);

}