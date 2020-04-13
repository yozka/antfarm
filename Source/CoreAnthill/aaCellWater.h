#pragma once
#include <memory>


namespace Anthill
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



        bool const &isWater() const; //�������� ���� ���� ��� ���
        int     waterPressure() const; //��������� �������� ����

        bool    isHumidity() const; //���� ��������� ��� ���
        float   humidityValue() const; //������� ���������



	public:



        void    pourWater(); //������ ����
        void    moveWaterTo(ACellWater &dest); //����������� ���� � ��������� �����
        
        void    makePressure(const int pressure); //��������� �������� ����



    private:



        bool	mWater          = { false };	//������� ���� ��� ����� ��������� ����
        int     mWaterPressure  = { 0 };        //�������� ����

        bool    mHumidity       = { false };    //��������� 
        float   mHumidityValue  = { 0.0f };     //������� ���������
	



	};
	///-------------------------------------------------------------------------




}
