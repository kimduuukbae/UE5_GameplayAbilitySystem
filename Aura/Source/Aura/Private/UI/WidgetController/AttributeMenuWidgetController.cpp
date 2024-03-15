#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AuraGameplayTags::Get().GetGameplayTag(EAttributeTags::Strength));
	Info.AttributeValue = AS->GetStrength();
	
	AttributeInfoDelegate.Broadcast(Info);
}