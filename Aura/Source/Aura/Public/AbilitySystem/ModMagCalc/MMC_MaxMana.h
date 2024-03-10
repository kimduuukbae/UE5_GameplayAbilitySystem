#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_MaxMana.generated.h"

UCLASS()
class AURA_API UMMC_MaxMana : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()
	
public:
	UMMC_MaxMana();

	float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const;
	
private:
	FGameplayEffectAttributeCaptureDefinition IntelligenceDef;

	UPROPERTY(EditAnywhere)
	float BaseMana = 50.0f;
};
