// Copyright

#pragma once

#include "CoreMinimal.h"
#include "Characters/CC_BaseCharacter.h"
#include "CC_EnemyCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class GASCRASHCOURSE_API ACC_EnemyCharacter : public ACC_BaseCharacter
{
	GENERATED_BODY()
	
public:
	ACC_EnemyCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual UAttributeSet* GetAttributeSet() const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|AI")
	float AcceptanceRadius{ 500.0f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|AI")
	float MinAttackDelay{ 0.5f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|AI")
	float MaxAttackDelay{ 0.5f };

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
