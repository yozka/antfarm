#include "aaActorComponent.h"

using namespace Anthill;
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
///
/// Constructor
///
///
///-------------------------------------------------------------------------
AActorComponent::AActorComponent()
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
AActorComponent::~AActorComponent()
{


}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
/// 
/// ��������� ��������
///
///
///-------------------------------------------------------------------------
void AActorComponent::setActor(const std::weak_ptr<AActor> &parent)
{
	mParent = parent;
}
///-------------------------------------------------------------------------





 ///------------------------------------------------------------------------
///
///
/// 
/// ��������� ��������
/// �������� �� �� ������ ���������� ��������, 
/// � ���� �� �� ������ �������� ���������
///
///-------------------------------------------------------------------------
std::shared_ptr<AActor> AActorComponent :: actor() const
{
	return mParent.lock();
}