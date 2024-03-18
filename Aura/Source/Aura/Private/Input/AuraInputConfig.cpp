// Default


#include "Input/AuraInputConfig.h"

const UInputAction* UAuraInputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogNotFound) const
{
    for (const FAuraInputAction& Action : AbilityInputActions)
    {
        if (Action.InputAction != nullptr && Action.InputTag == InputTag)
        {
            return Action.InputAction;
        }
    }

    if (bLogNotFound)
    {
        UE_LOG(LogTemp, Error, TEXT("FindAbilityInputActionForTag is Not Found Tag : %s"), *InputTag.GetTagName().ToString());
    }

    return nullptr;
}
