// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Splash : ModuleRules
{
	public Splash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
																											//头发模块, 添加完后去项目中删除Binaries, Intermediate, Saved，并鼠标右键虚幻*.uproject，重新生成Visual Studio Project File,之后再双击打开   
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","HairStrandsCore", "Niagara" });//"Niagara"因为编译不成功后来添加的,并且要去UE5文件路径UE_5.1\Engine\Plugins\Runtime\HairStrands，修改HairStrands.uplugin文件，第13行设置为true，"EnabledByDefault": true, 

        PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
