#pragma once
#include <memory>
#include <vector>

#include "aaPoint.h"
#include "aaLayer.h"
#include "aaCellGround.h"
#include "aaActor.h"


namespace Formicarium
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// ��� ��������
	///
	///
	///-------------------------------------------------------------------------
	class AWorld
		:
			public std::enable_shared_from_this<AWorld>

	{
	public:
	///-------------------------------------------------------------------------
		using ALayerGround = ALayer< ACellGround >;


	///-------------------------------------------------------------------------
	public:

		AWorld(const TPoint &size);
		virtual ~AWorld();


	///-------------------------------------------------------------------------
	public:


		const TPoint size;


		ALayerGround& ground; //������ � �����



	///-------------------------------------------------------------------------
	public:


		void update(const float timeSpan);



	///-------------------------------------------------------------------------
	public:


		std::vector<PActor>& actors() { return mActors; }

		void append(const PActor &actor); //���������� 
		void remove(const PActor &actor); //��������


	///-------------------------------------------------------------------------
	///-------------------------------------------------------------------------
	private:


		ALayerGround mGround;	//�����


		std::vector<PActor>	mActors;

	};
	///-------------------------------------------------------------------------


	using PWorld = std::shared_ptr< AWorld >;

	///-------------------------------------------------------------------------

}
