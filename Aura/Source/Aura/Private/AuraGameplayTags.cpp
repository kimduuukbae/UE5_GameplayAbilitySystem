#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

// ex : Container.Add(AttributeTags::Armor, UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance")));
#define ADD_ATTRIBUTE_TAGS(TagEnumName, TagName, TagDevComment) \
AttContainer.Add(EAttributeTags::##TagEnumName##, UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TagDevComment)))

#define ADD_INPUT_TAGS(TagEnumName, TagName, TagDevComment) \
InputContainer.Add(EInputTags::##TagEnumName##, UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TagDevComment)))


void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	TMap<EAttributeTags, FGameplayTag>& AttContainer = GameplayTags.AttributeTagContainer;
	AttContainer.Empty();

	/*
	*	 Primary Attributes
	*/
	ADD_ATTRIBUTE_TAGS(Strength, "Attributes.Primary.Strength", "Increases physical damage");
	ADD_ATTRIBUTE_TAGS(Intelligence, "Attributes.Primary.Intelligence", "Increases magical damage");
	ADD_ATTRIBUTE_TAGS(Resilience, "Attributes.Primary.Resilience", "Increases Armor and Armor Penetration");
	ADD_ATTRIBUTE_TAGS(Vigor, "Attributes.Primary.Vigor", "Increases Health");

	/*
	*	Secondary Attributes
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

	/*
	*	Input Tags
	*/

	TMap<EInputTags, FGameplayTag>& InputContainer = GameplayTags.InputTagContainer;
	InputContainer.Empty();

	ADD_INPUT_TAGS(LMB, "InputTag.LMB", "Input Tag for Left Mouse Button");
	ADD_INPUT_TAGS(RMB, "InputTag.RMB", "Input Tag for Right Mouse Button");
	ADD_INPUT_TAGS(Key_1, "InputTag.Key1", "Input Tag for 1 Key");
	ADD_INPUT_TAGS(Key_2, "InputTag.Key2", "Input Tag for 2 Key");
	ADD_INPUT_TAGS(Key_3, "InputTag.Key3", "Input Tag for 3 Key");
	ADD_INPUT_TAGS(Key_4, "InputTag.Key4", "Input Tag for 4 Key");
}

FGameplayTag FAuraGameplayTags::GetGameplayTag(EAttributeTags TagName) const
{
	const FGameplayTag* Value = FAuraGameplayTags::Get().AttributeTagContainer.Find(TagName);
	if (Value == nullptr)
	{
		return FGameplayTag();
	}
	
	return *Value;
}

FGameplayTag FAuraGameplayTags::GetInputTag(EInputTags TagName) const
{
	const FGameplayTag* Value = FAuraGameplayTags::Get().InputTagContainer.Find(TagName);
	if (Value == nullptr)
	{
		return FGameplayTag();
	}

	return *Value;
}
