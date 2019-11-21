#pragma once
#include <memory>


namespace Formicarium
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// �������� ������ � �����
	/// � ����������
	///
	///-------------------------------------------------------------------------
	class ACellWater
	{
	public:

		ACellWater();
		virtual ~ACellWater();


	public:



        bool    isWater() const; //�������� ���� ���� ��� ���
        int     waterPressure() const; //��������� �������� ����

        bool    isHumidity() const; //���� ��������� ��� ���
        float   humidityValue() const; //������� ���������

	public:

		void makeWater(); //��������� ����
        void takeWater(); //�������� ����
        
        void makePressure(const int pressure); //��������� �������� ����

    private:

        bool	mWater          = { false };	//������� ���� ��� ����� ��������� ����
        int     mWaterPressure = { 0 };         //�������� ����

        bool    mHumidity       = { false };    //��������� 
        float   mHumidityValue  = { 0.0f };     //������� ���������
	



	};
	///-------------------------------------------------------------------------




}
