// Copyright @Alexander Tereshin

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraCharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraCharacterBase();

protected:
	virtual void BeginPlay() override;

	// TObjectPtr - "lazy" pointer, init. / access stored object when it is being in use 
	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;
};
