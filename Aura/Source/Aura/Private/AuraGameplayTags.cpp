#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

AuraGameplayTags AuraGameplayTags::GameplayTags;

void AuraGameplayTags::InitializeNativeGameplayTags()
{
	UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));
}
