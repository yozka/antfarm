#pragma once
#include <memory>

#include "aaPoint.h"
#include "aaWorld.h"


namespace Formicarium
{
	///-------------------------------------------------------------------------





	 ///------------------------------------------------------------------------
	///
	///
	///
	/// Муровейник со всеми штуками
	///
	///
	///-------------------------------------------------------------------------
	class AFormicarium
	{
	public:

		

		AFormicarium(const int width, const int height);
		virtual ~AFormicarium();


	public:


		const PWorld world;



	public:




		void update(const float timeSpan);


	private:



		



	};
	///-------------------------------------------------------------------------



	using PFormicarium = std::shared_ptr< AFormicarium >;


	///-------------------------------------------------------------------------


}
