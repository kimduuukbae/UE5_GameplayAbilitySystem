#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */

UENUM()
enum class EAttributeTags
{
	Strength,
	Intelligence,
	Resilience,
	Vigor,
	Armor,
	ArmorPenetration,
	BlockChance,
	CriticalHitChance,
	CriticalHitDamage,
	CriticalHitResistance,
	HealthRegeneration,
	ManaRegeneration,
	MaxHealth,
	MaxMana,
};

class FAuraGameplayTags
{
public:
	static const FAuraGameplayTags& Get() 
	{
		return GameplayTags;
	}

	static void InitializeNativeGameplayTags();
	
	FGameplayTag GetGameplayTag(EAttributeTags TagName) const;

private:
	static FAuraGameplayTags GameplayTags;

	TMap<EAttributeTags, FGameplayTag> AttributeTagContainer;
};