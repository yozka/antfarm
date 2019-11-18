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




		bool	water			= { false };	//признак того что здесь находится вода
		
		bool	waterFull		= { false };	//признак полной заполненности водой
		float	waterVolumeUp	= { 0.0f };		//количество воды сверху от 0..1
		float	waterVolumeDown = { 0.0f };		//количество воды снизу


	public:

		void appendWaterUp		(const float volume); //увелечение количества воды вверху от 0..1
		void appendWaterDown	(const float volume); //увелечение количества воды снизу

		float takeWaterDown		(const float volume); //уменьшить воду снизу

	
	private:

		void normalizeWater(); //нормализация воды


	};
	///-------------------------------------------------------------------------




}
