#pragma once
#include <memory>


namespace Anthill
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



        bool const &isWater() const; //проверка вода есть или нет
        int     waterPressure() const; //возвратим давление воды

        bool    isHumidity() const; //есть влажность или нет
        float   humidityValue() const; //уровень влажности



	public:



        void    pourWater(); //налить воду
        void    moveWaterTo(ACellWater &dest); //переливание воды в указанную точку
        
        void    makePressure(const int pressure); //установка давление воды



    private:



        bool	mWater          = { false };	//признак того что здесь находится вода
        int     mWaterPressure  = { 0 };        //давление воды

        bool    mHumidity       = { false };    //влажность 
        float   mHumidityValue  = { 0.0f };     //уровень влажности
	



	};
	///-------------------------------------------------------------------------




}
