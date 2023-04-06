// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class Splash : ModuleRules
{
	public Splash(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
																											//ͷ��ģ��, ������ȥ��Ŀ��ɾ��Binaries, Intermediate, Saved��������Ҽ����*.uproject����������Visual Studio Project File,֮����˫����   
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore","HairStrandsCore", "Niagara" });//"Niagara"��Ϊ���벻�ɹ�������ӵ�,����ҪȥUE5�ļ�·��UE_5.1\Engine\Plugins\Runtime\HairStrands���޸�HairStrands.uplugin�ļ�����13������Ϊtrue��"EnabledByDefault": true, 

        PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
