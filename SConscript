# -*- mode:python;indent-tabs-mode:nil;show-trailing-whitespace:t; -*-
#
# Main build script for all librosetta projects.
# Schedules all the directories which contain build targets of their own.

import os, sys
import subprocess

# Bring in the shared build state
Import("build")

Decider('MD5-timestamp')
SetOption('implicit_cache', 1)

# Generate .cc file with svn revision number/range.
# Provide empty dictionaries so local environment is not modified.
AddOption('--nover',
          dest='nover',
          action="store_true", default=False,
          help="Don't run the versioning script.")

if not GetOption("help"):
    if GetOption("nover"):
        print "Skipping versioning script. (Hopefully src/core/svn_version.cc is already up-to-date.)"
    else:
        import version
        version.main()
    subprocess.check_call(["./update_options.sh"])
    subprocess.check_call(["./update_ResidueType_enum_files.sh"])

for kind in build.options.cat:
    for project in build.projects[kind]:
        # Sources and test are further broken down by platform
        if kind in ("src", "test","external"):
          if kind == "src" and project in ("apps", "pilot_apps", "demo") :
            #These sconscript files lead to executables
            if project in ( "apps", "pilot_apps" ) :
              build_path = "build/%s/%s" % (kind, build.platform)
              script = "src/SConscript.apps"
            else :
              #This will be going away once everyone is comfortable with compiling
              #executables in the apps framework
              build_path = "build/demo/%s" % (build.platform)
              script = "demo/SConscript.demo"
          else:
            build_path = "build/%s/%s" % (kind, build.platform)
            script = "%s/SConscript.%s"% (kind, kind)
        # Documentation is built once regardless of platform
        else:
          build_path = "build/%s" % (kind)
          script = "%s/SConscript.%s" % (kind, kind)
        SConscript(script, exports = ["build", "project"],
          variant_dir = build_path, duplicate = False)

#if "my" in map(str, BUILD_TARGETS) :
#  BUILD_TARGETS.remove("my")
#if "my_pilot_apps" in map(str, BUILD_TARGETS) :
#  BUILD_TARGETS.remove("my_pilot_apps")
#if "pilot_apps_all" in map(str, BUILD_TARGETS) :
#  BUILD_TARGETS.remove("pilot_apps_all")
