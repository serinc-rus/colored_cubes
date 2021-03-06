// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SenseVisualizerComponent.generated.h"

class UActorSensingComponent;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLOREDCUBES_API USenseVisualizerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	USenseVisualizerComponent();

protected:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnActorSee(AActor* InActor);

	UFUNCTION()
	void OnActorLost(AActor* InActor);

	UPROPERTY(EditAnywhere, Category = "Visualizer")
	TMap<float, FLinearColor> RangeColors;

	UPROPERTY(EditAnywhere, Category = "Visualizer")
	float AdditionalViewAngle = 20.0f;

	UPROPERTY(EditAnywhere, Category = "Visualizer")
	bool bVisualizeFOV = true;

	UPROPERTY(EditAnywhere, Category = "Visualizer", meta = (EditCondition = "bVisualizeFOV"))
	float VisualizeFOVRange = 1000.0f;
	
	UPROPERTY()
	UActorSensingComponent* SensingComponent;

	UPROPERTY()
	UCameraComponent* CameraComponent;
		
};
