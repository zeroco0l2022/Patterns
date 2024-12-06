// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Patterns : ModuleRules
{
	public Patterns(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new[] { "Niagara" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}