// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;


public class test_blur_two : ModuleRules
{
    //PublicDefinitions.Add("MY_MODULE_VAR=0")
	public test_blur_two(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        //added to supress warnings from opencv plugin
        bEnableUndefinedIdentifierWarnings = false;
        DefaultBuildSettings = BuildSettingsVersion.V4;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "OpenCV", "OpenCVHelper","InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] { 
                                        "Core",
                                        "CoreUObject",
                                        "Engine",
                                        "Renderer",
                                        "RenderCore",
                                        "RHI",
                                        "RHICore",
                                        "D3D12RHI",
                                        "OpenCV",
                                        "OpenCVHelper"  
        });

		
	}
}
