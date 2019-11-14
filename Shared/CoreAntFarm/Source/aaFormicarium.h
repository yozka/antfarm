#pragma once
#include <memory>
#include <list>

#include "aaPoint.h"
#include "aaWorld.h"
#include "aaActor.h"

namespace Formicarium
{





	class AFormicarium
	{
	public:

		

		AFormicarium(const int width, const int height);
		virtual ~AFormicarium();


	public:


		AWorld& world;

		std::list<PActor>& actors() { return mActors; }

	public:


		int width()		const { return mSize.x; };
		int height()	const { return mSize.y; };

		void append(const PActor &actor); //добавление 


		void update(const float timeSpan);


	private:


		const TPoint		mSize;

		AWorld				mWorld;
		

		std::list<PActor>	mActors;

	};



	using PFormicarium = std::shared_ptr< AFormicarium >;

}
