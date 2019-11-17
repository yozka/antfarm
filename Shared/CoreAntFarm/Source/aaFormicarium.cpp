#include "aaFormicarium.h"



///-------------------------------------------------------------------------
using namespace Formicarium;
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Constructor
///
///
///-------------------------------------------------------------------------
AFormicarium :: AFormicarium(const int width, const int height)
	:
	world(std::make_shared < Formicarium::AWorld > (TPoint(width, height))),


	mHydrodynamics(world)

{




}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Destructor
///
///
///-------------------------------------------------------------------------
AFormicarium :: ~AFormicarium()
{


}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Update 
///
///
///-------------------------------------------------------------------------
void AFormicarium :: update(const float timeSpan)
{
	world->update(timeSpan);

	mHydrodynamics.update(timeSpan);

}