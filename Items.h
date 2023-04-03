// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class SPLASH_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//UPROPERTY(EditAnyWhere,BlueprintReadOnly) // ��ͼ�����ɶ�
	UPROPERTY(EditAnyWhere,BlueprintReadWrite, Category = "Sine Parameters") // ��ͼ�����ɶ���д,������"Sine Parameters"
		float Amplitude = 1.f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters") // ��ͼ�����ɶ���д,������"Sine Parameters"
		float TimeConstant = 5.f;

	/*UFUNCTION(BlueprintCallable)   //���ܴ�����  .cpp ���ͼ�ڹ��ܿɵ��� 
		float TransformedSin(float Value);*/
	UFUNCTION(BlueprintPure)   //���һ�ֵ�������ģ����ú���
		float TransformedSin();

	UFUNCTION(BlueprintPure)   //���һ�ֵ�������ģ����ú���
		float TransformedCos();

	template<typename T> //�������ģ�幦�ܣ����԰�������Ϊ�����ģ��� .cpp ����, ���ǲ�֧�ֳ��� "/"��rotator
	T Avg(T First, T Second);

private:
	//UPROPERTY(VisibleDefaultsOnly) //Ĭ������ͼ�ڿɼ��������޸�
	//UPROPERTY(VisibleInstanceOnly) //Ĭ���������пɼ��������޸�
	//UPROPERTY(EditDefaultsOnly) //Ĭ������ͼ�ڿ��޸ģ�ʵ����ȫ��ͬ��������ͼ
	//UPROPERTY(EditInstanceOnly) //����������޸ģ�ʵ����ͬ
	//UPROPERTY(EditAnyWhere) // ���еط����޸ģ�������ͼ�޸ĵ���Ĭ��ֵ������ʵ�����޸Ŀ��Ը���Ĭ��ֵ
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		//��ͼ����Կɼ��������޸�, ����meta�����ǹ��������
		float RunningTime;

};

template<typename T>
inline T AItems::Avg(T First, T Second)
{
	return (First + Second)/2;
}
