using UnrealBuildTool;

public class RL : ModuleRules
{
	public RL(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore"});

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
