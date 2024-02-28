#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interface/HighlightEffectInterface.h"
#include "AuraEnemy.generated.h"

UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IHighlightEffectInterface
{
	GENERATED_BODY()

public:
	AAuraEnemy();

	/** HighlightEffect Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** end HighlightEffect Interface */

protected:
	virtual void BeginPlay() override;
};
