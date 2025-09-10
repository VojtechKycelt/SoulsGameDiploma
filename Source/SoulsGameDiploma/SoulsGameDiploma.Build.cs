// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SoulsGameDiploma : ModuleRules
{
	public SoulsGameDiploma(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"SoulsGameDiploma",
			"SoulsGameDiploma/Variant_Platforming",
			"SoulsGameDiploma/Variant_Platforming/Animation",
			"SoulsGameDiploma/Variant_Combat",
			"SoulsGameDiploma/Variant_Combat/AI",
			"SoulsGameDiploma/Variant_Combat/Animation",
			"SoulsGameDiploma/Variant_Combat/Gameplay",
			"SoulsGameDiploma/Variant_Combat/Interfaces",
			"SoulsGameDiploma/Variant_Combat/UI",
			"SoulsGameDiploma/Variant_SideScrolling",
			"SoulsGameDiploma/Variant_SideScrolling/AI",
			"SoulsGameDiploma/Variant_SideScrolling/Gameplay",
			"SoulsGameDiploma/Variant_SideScrolling/Interfaces",
			"SoulsGameDiploma/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
