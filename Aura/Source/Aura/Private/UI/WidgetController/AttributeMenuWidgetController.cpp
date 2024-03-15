#include "UI/WidgetController/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/Data/AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	for (auto& Elem : AS->TagsToAttributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Elem.Value()).AddLambda
		(
			[this, Elem, AS](const FOnAttributeChangeData& Data)
			{
				FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Elem.Key);
				Info.AttributeValue = Elem.Value().GetNumericValue(AS);

				AttributeInfoDelegate.Broadcast(Info);
			}
		);
	}


}

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	UAuraAttributeSet* AS = CastChecked<UAuraAttributeSet>(AttributeSet);

	// TODO : Delete Remain garbage : AttributeInfoDelegate (Blueprints)
	for (auto& Elem : AS->TagsToAttributes)
	{
		FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Elem.Key);
		FGameplayAttribute Attribute = Elem.Value();
		Info.AttributeValue = Attribute.GetNumericValue(AS);

		AttributeInfoDelegate.Broadcast(Info);
	}
}