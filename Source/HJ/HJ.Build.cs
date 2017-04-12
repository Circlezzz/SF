using UnrealBuildTool;

public class HJ : ModuleRules
{
	public HJ(TargetInfo Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine" });

		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}
