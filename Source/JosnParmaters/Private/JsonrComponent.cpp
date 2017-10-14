// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonrComponent.h"
#include "Engine.h"


// Sets default values for this component's properties
UJsonrComponent::UJsonrComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UJsonrComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UJsonrComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
#pragma region open json file get json file;
bool UJsonrComponent::ReadJson(FString FileName)
{
	return FFileHelper::LoadFileToString(JsonStr, *(FPaths::GameDir() + FileName));
}
#pragma endregion
#pragma region get json pass zi di yi de struct  de rong qi zhong  ;
void UJsonrComponent::GetJson()
{
	TArray<TSharedPtr<FJsonValue>> JsonParsed;

	//��ȡJson
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonStr);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))

	{
		//FJonsStruct Jstruct;

		for (int32 i = 0; i < JsonParsed.Num(); i++)
		{   //ʵ�����ṹ��
			//FJonsStruct Jstruct;
			Jstruct.Name = JsonParsed[i]->AsObject()->GetStringField("Name");
			//��ĳ������ֵ��ӵ������string������
			JonsArray.Add(Jstruct.Name);

			Jstruct.SkillId = JsonParsed[i]->AsObject()->GetStringField("SkillId");
			Jstruct.SkillName = JsonParsed[i]->AsObject()->GetStringField("SkillName");
			Jstruct.SkillImage = JsonParsed[i]->AsObject()->GetStringField("SkillImage");
			//������ӵ��Ǹ����ʵ��
			StructJsonPramaters.Add(Jstruct);
		
			//FString tempString = "Name= " + Name + " ,SkillId = " + FStringSkillId + ",SkillName=" + FStringSkillName + ",SkillImage" + FstrinngSkillImage;
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, tempString);


		}
		
	}

}
#pragma endregion



