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

UENUM()
enum class EInputTags
{
	LMB,
	RMB,
	Key_1,
	Key_2,
	Key_3,
	Key_4,
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

	FGameplayTag GetInputTag(EInputTags TagName) const;

private:
	static FAuraGameplayTags GameplayTags;

	TMap<EAttributeTags, FGameplayTag> AttributeTagContainer;
	TMap<EInputTags, FGameplayTag> InputTagContainer;
};