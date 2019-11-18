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




		bool	water			= { false };	//������� ���� ��� ����� ��������� ����
		
		bool	waterFull		= { false };	//������� ������ ������������� �����
		float	waterVolumeUp	= { 0.0f };		//���������� ���� ������ �� 0..1
		float	waterVolumeDown = { 0.0f };		//���������� ���� �����


	public:

		void appendWaterUp		(const float volume); //���������� ���������� ���� ������ �� 0..1
		void appendWaterDown	(const float volume); //���������� ���������� ���� �����

		float takeWaterDown		(const float volume); //��������� ���� �����

	
	private:

		void normalizeWater(); //������������ ����


	};
	///-------------------------------------------------------------------------




}
