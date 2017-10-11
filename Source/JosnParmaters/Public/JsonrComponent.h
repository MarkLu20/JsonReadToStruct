// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Json.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Private/HttpTests.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Misc/Paths.h"
#include "JsonrComponent.generated.h"


USTRUCT(BlueprintType)
struct FJonsStruct
{
	GENERATED_USTRUCT_BODY()
public:
	////virtual ~FJonsStruct(FString name, FString SkillId, FString SkillName);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTestData")
		FString     Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTestData")
		FString      SkillId;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTestData")
		FString     SkillName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FTestData")
		FString SkillImage;

};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class JOSNPARMATERS_API UJsonrComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UJsonrComponent();
	FString JsonStr;
	FJonsStruct Jstruct;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Json")
		void GetJson();
	UFUNCTION(BlueprintCallable, Category = "Josn")
		bool ReadJson(FString FileName);
	UPROPERTY(BlueprintReadOnly, Category = "JosnArray")
		TArray<FString> JonsArray;
	UPROPERTY(BlueprintReadOnly, Category = "JosnArray")
		TArray<FJonsStruct> StructJsonPramaters;

};
