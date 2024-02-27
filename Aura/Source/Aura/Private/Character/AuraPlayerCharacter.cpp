#include "Character/AuraPlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringarmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AAuraPlayerCharacter::AAuraPlayerCharacter()
{
	// SpringArm and Camera do not need to be written in C++.
	// There are no performance benefits compared to blueprints.

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 750.0f;
	SpringArm->SetWorldRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bEnableCameraLag = true;
	
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	UCharacterMovementComponent* MovementComponent = GetCharacterMovement();
	
	MovementComponent->bOrientRotationToMovement = true;
	MovementComponent->RotationRate = FRotator(0.0f, 400.0f, 0.0f);
	MovementComponent->bConstrainToPlane = true;
	MovementComponent->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}
