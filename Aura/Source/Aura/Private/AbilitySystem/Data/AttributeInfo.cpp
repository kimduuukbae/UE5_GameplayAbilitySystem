// Default


#include "AbilitySystem/Data/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogNotFound) const
{
	for (const FAuraAttributeInfo& Info : AttributeInformation)
	{
		if (Info.AttributeTag == AttributeTag)
		{
			return Info;
		}
	}

	if (bLogNotFound == true)
	{
		UE_LOG(LogTemp, Error, TEXT("FindAttributeInfoForTag : Not Found. Class : %s"), *GetNameSafe(this));
	}

	return FAuraAttributeInfo();
}
