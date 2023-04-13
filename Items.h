// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

class USphereComponent;

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class SPLASH_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AItems();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters") // 蓝图变量可读可写,分类于"Sine Parameters"
		float Amplitude = 1.f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters") // 蓝图变量可读可写,分类于"Sine Parameters"
		float TimeConstant = 5.f;

	/*UFUNCTION(BlueprintCallable)   //功能创建在  .cpp 里，蓝图内功能可调动
		float TransformedSin(float Value);*/
	UFUNCTION(BlueprintPure)   //变成一种单纯计算的，调用函数
		float TransformedSin();

	UFUNCTION(BlueprintPure)   //变成一种单纯计算的，调用函数
		float TransformedCos();

	template<typename T> //这个属于模板功能，可以把他定义为其他的，看 .cpp 例子, 但是不支持除法 "/"在rotator
	T Avg(T First, T Second);

	UFUNCTION()
		//PrimitiveComponent.h   的 继承， 查找 OnComponentBeginOverlap 
		virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// 只有void 子类会直接父类， 加virtual 和 子类末尾 override 覆盖则可以分开功能
	//void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		//PrimitiveComponent.h   的 继承， 查找 OnSphereEndOverlap
		virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		UStaticMeshComponent* ItemMesh;

	EItemState ItemState = EItemState::EIS_Hovering;

private:
	//UPROPERTY(VisibleDefaultsOnly) //默认在蓝图内可见，不可修改
	//UPROPERTY(VisibleInstanceOnly) //默认在世界中可见，不可修改
	//UPROPERTY(EditDefaultsOnly) //默认在蓝图内可修改，实例完全相同，基于蓝图
	//UPROPERTY(EditInstanceOnly) //在世界里可修改，实例不同
	//UPROPERTY(EditAnyWhere) // 所有地方可修改，但是蓝图修改的是默认值，世界实例的修改可以覆盖默认值
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float RunningTime;	//蓝图世界皆可见，不可修改, 但是meta设置是公开其变量

	

	UPROPERTY(VisibleAnywhere)
		USphereComponent* Sphere;

};

template<typename T>
inline T AItems::Avg(T First, T Second)
{
	return (First + Second) / 2;
}

