// Copyright @Alexander Tereshin

#include "Player/AuraPlayerController.h"
#include "Engine/LocalPlayer.h"
#include "EnhancedInputSubsystems.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
    // checking if the context was set, otherwise crash 
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	// checking if susbsystem was initialized
	check(SubSystem);
	SubSystem->AddMappingContext(AuraContext, 0);

	// cursor configuration
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	// essential for handling widjets / extra windows / UI; 
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	
}
