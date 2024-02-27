#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HighlightEffectInterface.generated.h"

UINTERFACE(MinimalAPI)
class UHighlightEffectInterface : public UInterface
{
	GENERATED_BODY()
};

class AURA_API IHighlightEffectInterface
{
	GENERATED_BODY()
	
public:

	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};
