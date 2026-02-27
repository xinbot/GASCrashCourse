// Copyright


#include "Utils/CC_BlueprintLibrary.h"

EHitDirection UCC_BlueprintLibrary::GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator)
{
	const float Dot = FVector::DotProduct(TargetForward, ToInstigator);

	if (Dot < -0.5f)
	{
		return EHitDirection::Back;
	}

	if (Dot < 0.5f)
	{
		const FVector Cross = FVector::CrossProduct(TargetForward, ToInstigator);
		return Cross.Z < 0.0f ? EHitDirection::Left : EHitDirection::Right;
	}

	return EHitDirection::Forward;
}

FName UCC_BlueprintLibrary::GetHitDirectionName(const EHitDirection& HitDirection)
{
	switch (HitDirection)
	{
	case EHitDirection::Left: 
		return FName("Left");

	case EHitDirection::Right:
		return FName("Right");

	case EHitDirection::Forward:
		return FName("Forward");

	case EHitDirection::Back:
		return FName("Back");

	default:
		return FName("None");
	}
}
