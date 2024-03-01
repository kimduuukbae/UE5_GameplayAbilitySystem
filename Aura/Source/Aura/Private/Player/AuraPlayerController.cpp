#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interface/HighlightEffectInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	TraceCursor();
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	const FVector ForwardDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDir, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDir, InputAxisVector.X);
	}
}

void AAuraPlayerController::TraceCursor()
{
	FHitResult CursorHit;

	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);

	if (CursorHit.bBlockingHit == false)
	{
		return;
	}

	LastHittedActor = CurrentHitActor;
	CurrentHitActor = Cast<IHighlightEffectInterface>(CursorHit.GetActor());

	/**
	*	Line trace from cursor. There are several scenarios:
	*	A. LastHittedActor is null && CurrentHitActor is null
	*		- Do nothing
	* 
	*	B. LastHittedActor is null && CurrentHitActor is valid
	*		- Highlight CurrentHitActor
	* 
	*	C. LastHittedActor is valid && CurrentHitActor is null
	*		- UnHighlight LastHittedActor
	* 
	*	D. Both actors are valid, but LastHittedActor != CurrentHitActor
	*		- UnHighlight LastHittedActor, and Highlight CurrentHitActor
	* 
	*	E. Both actors are valid, and are the same actor
	*		- Do nothing
	*/

	if (LastHittedActor == nullptr)
	{
		if (CurrentHitActor != nullptr)
		{
			// Case B
			CurrentHitActor->HighlightActor();
		}
		else 
		{
			// Case A, Do nothing
		}
	}
	else
	{
		if (CurrentHitActor != nullptr)
		{
			if (LastHittedActor != CurrentHitActor)
			{
				// Case D
				LastHittedActor->UnHighlightActor();
				CurrentHitActor->HighlightActor();
			}
			else
			{
				// Case E, Do nothing
			}
		}
		else
		{
			// Case C
			LastHittedActor->UnHighlightActor();
		}
	}

}

