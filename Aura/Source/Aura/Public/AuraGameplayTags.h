#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */

class AuraGameplayTags
{
public:
	static const AuraGameplayTags& Get() 
	{
		return GameplayTags;
	}

	static void InitializeNativeGameplayTags();

private:
	static AuraGameplayTags GameplayTags;
};