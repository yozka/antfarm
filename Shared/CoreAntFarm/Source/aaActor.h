#pragma once
#include <memory>
#include <vector>

#include "aaPoint.h"
#include "aaActorComponent.h"

namespace Formicarium
{


	class AActor
	{
	public:

		AActor();
		virtual ~AActor();


	public:


		TPointF size() const { return mSize; }
		TPointF position() const { return mPosition; }
		float angle()const { return mAngle; }

		void setPosition(const TPointF &pt);


	public:

		void append(const PActorComponent &component);
		void remove(const PActorComponent &component);


		void update(const float timeSpan);

	private:

		TPointF mSize		= { 1.0f};
		TPointF mPosition	= { 0.0f };
		float	mAngle		= { 0.0f };

		std::vector<PActorComponent> mComponents;
	};


	using PActor = std::shared_ptr<AActor>;


}
