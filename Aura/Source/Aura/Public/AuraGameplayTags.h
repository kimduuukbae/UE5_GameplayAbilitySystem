#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 * 
 * Singleton containing native Gameplay Tags
 */

UENUM()
enum class AttributeTags
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

class AuraGameplayTags
{
public:
	static const AuraGameplayTags& Get() 
	{
		return GameplayTags;
	}

	static void InitializeNativeGameplayTags();
	
	FGameplayTag GetGameplayTag(AttributeTags TagName);

private:
	static AuraGameplayTags GameplayTags;

	TMap<AttributeTags, FGameplayTag> AttributeTagContainer;
};