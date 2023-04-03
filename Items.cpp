// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Items.h"


#define THIRTY 30
//定义的东西也可以写在 "项目名.h" 里面,但是这里要include进来
#include "Splash/DebugMarco.h"


// Sets default values
AItems::AItems() //: Amplitude(0.25f) //初始化数值方法1
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//float Amplitude = 0.25f;//初始化数值方法2,赋值

}

// Called when the game starts or when spawned
void AItems::BeginPlay()
{
	Super::BeginPlay();

	// 模板函数在此，不同定义
	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3 : %d"), AvgInt);

	float AvgFloat = Avg<float>(3.14, 6.14);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 3.14 and 6.14 : %f"), AvgFloat);

	/*在log输出
	UE_LOG(LogTemp, Warning, TEXT("begin play called !"));
	//在游戏内输出
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
	}
	*/

	/*
	查找世界是否存在这个物体, 写法1
	UWorld* World = GetWorld();
	if (World)
	{
		FVector Location = GetActorLocation();
		DrawDebugSphere(World,Location,25.f, THIRTY,FColor::Red,false,30.f);
	}*/

	//写法2
	//UWorld* World = GetWorld();
	

//	SetActorLocation(FVector(0.f, 0.f, 50.f));
	//SetActorRotation(FRotator(0.f,45.f,0.f));
	/*
	FVector Location = GetActorLocation();
	DRAW_SPHERE(Location);
	FVector Forward = GetActorForwardVector();*/
	//DRAW_LINE(Location, Location + Forward * 100.f);

	/*
	if (World)
	{
		FVector Forward = GetActorForwardVector();
		DrawDebugLine(World,Location,Forward*100,FColor::Red,true,-1.f,0,1.f);//0优先值最高
	}*/
	

	//DRAW_POINT(Location + Forward * 100.f);
	//DRAW_VECTOR(Location,Location + Forward * 100.f);

}

float AItems::TransformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}
float AItems::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}
/*float AItems::TransformedSin(float Value)
{
	return Amplitude * FMath::Sin(Value * TimeConstant);
}*/

// Called every frame
void AItems::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*实时输出deltaTime
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);

	if (GEngine)
	{
		FString Name = GetName();
		FString Message = FString::Printf(TEXT("DeltaTime : %f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

		UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %s"), *Name);
	}
	*/
	//每帧都会加一位置，并画出圆体
	/*
	float MovementeRate = 50.f;
	float RotationRate = 45.f;

	AddActorWorldOffset(FVector(MovementeRate * DeltaTime,0.f,0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));*/

	RunningTime += DeltaTime;
	//				 时长							振幅
	//float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant);
	//AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	FVector AvgVector = Avg<FVector>(GetActorLocation(),FVector::ZeroVector);
	DRAW_POINT_SingleFrame(AvgVector);

	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation()+GetActorForwardVector()*100.f);


}

