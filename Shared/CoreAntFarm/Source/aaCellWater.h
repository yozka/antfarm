#pragma once
#include <memory>


namespace Formicarium
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// Описание клетки с водой
	/// и влажностью
	///
	///-------------------------------------------------------------------------
	class ACellWater
	{
	public:

		ACellWater();
		virtual ~ACellWater();


	public:



        bool    isWater() const; //проверка вода есть или нет
        int     waterPressure() const; //возвратим давление воды

        bool    isHumidity() const; //есть влажность или нет
        float   humidityValue() const; //уровень влажности

	public:

		void makeWater(); //установка воды
        void takeWater(); //уберание воды
        
        void makePressure(const int pressure); //установка давление воды

    private:

        bool	mWater          = { false };	//признак того что здесь находится вода
        int     mWaterPressure = { 0 };         //давление воды

        bool    mHumidity       = { false };    //влажность 
        float   mHumidityValue  = { 0.0f };     //уровень влажности
	



	};
	///-------------------------------------------------------------------------




}
