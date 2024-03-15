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

class AuraGameplayTags
{
public:
	static const AuraGameplayTags& Get() 
	{
		return GameplayTags;
	}

	static void InitializeNativeGameplayTags();
	
	FGameplayTag GetGameplayTag(EAttributeTags TagName) const;

private:
	static AuraGameplayTags GameplayTags;

	TMap<EAttributeTags, FGameplayTag> AttributeTagContainer;
};