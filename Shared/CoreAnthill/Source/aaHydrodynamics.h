#pragma once
#include <memory>

#include "aaWorld.h"
#include "aaCellWater.h"
#include "aaCellGround.h"

namespace Anthill
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// �������������
	///
	///
	///-------------------------------------------------------------------------
	class AHydrodynamics
	{
	public:



		AHydrodynamics(const PWorld &world);
		virtual ~AHydrodynamics();


	public:


	


	public:




		void update(const float timeSpan);


	private:



		PWorld mWorld;

		float mSpeedFluidVertical   = { 50 }; //�������� �������������� ����
        float mSpeedHumidity        = { 100 }; //�������� �������������� ���������
    private:


        //��������� ����
        void fallWater(); //������� ����
        void pressureCalc();//������� ��������
        bool spreadingWater(); //���������� ����
        bool spreadingWaterCell(const int x, const int y, const int direct, const AWorld::ALayerGround &ground, AWorld::ALayerWater &water);


        //���������
        void humidityEmitting(const float volume); //�������� ���������
        void humidityMoveTo(ACellWater &water, ACellWater &waterDest); //������������� ����� �� ����
	};
	///-------------------------------------------------------------------------



	using PHydrodynamics = std::shared_ptr< AHydrodynamics >;


	///-------------------------------------------------------------------------


}
