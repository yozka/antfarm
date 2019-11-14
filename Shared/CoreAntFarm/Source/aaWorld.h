#pragma once
#include <memory>
#include <list>

#include "aaPoint.h"
#include "aaLayer.h"
#include "aaCellGround.h"


namespace Formicarium
{





	class AWorld
	{
	public:

		using AGround = ALayer< ACellGround >;



	public:

		AWorld(const TPoint &size);
		virtual ~AWorld();


	public:


		AGround& ground;


	


	private:




		AGround mGround;

	};




}
