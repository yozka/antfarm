#pragma once
#include <memory>
#include <vector>

#include "aaPoint.h"
#include "aaActorComponent.h"

namespace Formicarium
{

	///-------------------------------------------------------------------------
	class AWorld;
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// Один элемент муровейника
	///
	///
	///-------------------------------------------------------------------------
	class AActor
		:
			public std::enable_shared_from_this < AActor >
	{
	public:

		AActor();
		virtual ~AActor();

		
		
		void setWorld(const std::weak_ptr<AWorld> &world); //установка текущего мира
		std::shared_ptr<AWorld> world()const; //возвратим мир, внимание не надо его удерживать!!! не сохроняйте ссылку на мир


	public:


		TPointF size()			const { return mSize; }
		TPointF position()		const { return mPosition; }
		float	angle()			const { return mAngle; }

		void setPosition	(const TPointF &pt);
		void setSize		(const TPointF &sz);
		void setAngle		(const float angle);

	public:


		void append(const PActorComponent &component);
		void remove(const PActorComponent &component);


		void update(const float timeSpan);


	///-------------------------------------------------------------------------
	///-------------------------------------------------------------------------
	private:


		std::weak_ptr<AWorld> mWorld;

		TPointF mSize		= { 1.0f};
		TPointF mPosition	= { 0.0f };
		float	mAngle		= { 0.0f };

		std::vector<PActorComponent> mComponents;
	};
	///-------------------------------------------------------------------------


	///-------------------------------------------------------------------------
	using PActor = std::shared_ptr<AActor>;
	///-------------------------------------------------------------------------



}
