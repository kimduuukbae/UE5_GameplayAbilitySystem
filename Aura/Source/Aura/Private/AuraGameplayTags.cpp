#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

AuraGameplayTags AuraGameplayTags::GameplayTags;

// ex : Container.Add(AttributeTags::Armor, UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance")));
#define ADD_ATTRIBUTE_TAGS(TagEnumName, TagName, TagDevComment) \
Container.Add(AttributeTags::##TagEnumName##, UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TagDevComment)))


void AuraGameplayTags::InitializeNativeGameplayTags()
{
	TMap<AttributeTags, FGameplayTag>& Container = GameplayTags.AttributeTagContainer;
	Container.Empty();

	/*
	* Primary Attributes
	*/
	ADD_ATTRIBUTE_TAGS(Strength, "Attributes.Primary.Strength", "Increases physical damage");
	ADD_ATTRIBUTE_TAGS(Intelligence, "Attributes.Primary.Intelligence", "Increases magical damage");
	ADD_ATTRIBUTE_TAGS(Resilience, "Attributes.Primary.Resilience", "Increases Armor and Armor Penetration");
	ADD_ATTRIBUTE_TAGS(Vigor, "Attributes.Primary.Vigor", "Increases Health");

	/*
	* Secondary Attributes
	*/
	ADD_ATTRIBUTE_TAGS(Armor, "Attributes.Secondary.Armor", "Reduces damage taken, improves Block Chance");
	ADD_ATTRIBUTE_TAGS(ArmorPenetration, "Attributes.Secondary.ArmorPenetration", "Ignored Percentage of enemy Armor, increases Critical Hit Chance");
	ADD_ATTRIBUTE_TAGS(BlockChance, "Attributes.Secondary.BlockChance", "Chance to cut incoming damage in half");
	ADD_ATTRIBUTE_TAGS(CriticalHitChance, "Attributes.Secondary.CriticalHitChance", "Chance to double damange plus ciritical hit bonus");
	ADD_ATTRIBUTE_TAGS(CriticalHitDamage, "Attributes.Secondary.CriticalHitDamage", "Bonus damage added when a critical hit is scored");
	ADD_ATTRIBUTE_TAGS(CriticalHitResistance, "Attributes.Secondary.CriticalHitResistance", "Reduces Critical Hit Chance of attacking enemies");
	ADD_ATTRIBUTE_TAGS(HealthRegeneration, "Attributes.Secondary.HealthRegeneration", "Amount of Mana regenerated every 1 second");
	ADD_ATTRIBUTE_TAGS(ManaRegeneration, "Attributes.Secondary.ManaRegeneration", "Amount of Mana regenerated every 1 second");
	ADD_ATTRIBUTE_TAGS(MaxHealth, "Attributes.Secondary.MaxHealth", "Maximum amount of Health obtainable");
	ADD_ATTRIBUTE_TAGS(MaxMana, "Attributes.Secondary.MaxMana", "Maximum amount of Mana obtainable");
}

FGameplayTag AuraGameplayTags::GetGameplayTag(AttributeTags TagName)
{
	return *AuraGameplayTags::Get().AttributeTagContainer.Find(TagName);
}
