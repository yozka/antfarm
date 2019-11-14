#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestSandbox.h"

#include <memory>
#include "CoreAntFarm.h"
#include "ssRender.h"

class TestSandbox : public QMainWindow
{
	Q_OBJECT

public:
	TestSandbox(QWidget *parent = Q_NULLPTR);


protected:

	void timerEvent(QTimerEvent * event) override;



private:
	Ui::TestSandboxClass ui;

	Formicarium::PFormicarium mFormicarium;



private:

	ARender mRender;

};
