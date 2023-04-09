// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapon/Weapon.h"

void AWeapon::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	//父类item 的 函数调用
	Super::OnSphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}

void AWeapon::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{	//父类item 的 函数调用
	Super::OnSphereEndOverlap(OverlappedComponent, OtherActor,OtherComp, OtherBodyIndex);
}
