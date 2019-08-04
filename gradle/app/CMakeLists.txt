# Sets the minimum version of CMake required to build the native
# library. You should either keep the default value or only pass a
# value of 3.4.0 or lower.

cmake_minimum_required(VERSION 3.6)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds it for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
             native

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             # Associated headers in the same location as their source
             # file are automatically included.
             src/main/cpp/c/all.c
             src/main/cpp/c/allefant.c
             src/main/cpp/c/allefant.h
             src/main/cpp/c/all.h
             src/main/cpp/c/barrel.c
             src/main/cpp/c/barrel.h
             src/main/cpp/c/block.c
             src/main/cpp/c/block.h
             src/main/cpp/c/block_type.c
             src/main/cpp/c/block_type.h
             src/main/cpp/c/cart.c
             src/main/cpp/c/cart.h
             src/main/cpp/c/common.c
             src/main/cpp/c/common.h
             src/main/cpp/c/config.c
             src/main/cpp/c/config.h
             src/main/cpp/c/conveyor.c
             src/main/cpp/c/conveyor.h
             src/main/cpp/c/cube.c
             src/main/cpp/c/cube.h
             src/main/cpp/c/debug.c
             src/main/cpp/c/debug.h
             src/main/cpp/c/editor.c
             src/main/cpp/c/editor.h
             src/main/cpp/c/event.c
             src/main/cpp/c/event.h
             src/main/cpp/c/eye.c
             src/main/cpp/c/eye.h
             src/main/cpp/c/game.c
             src/main/cpp/c/game.h
             src/main/cpp/c/gremlin.c
             src/main/cpp/c/gremlin.h
             src/main/cpp/c/input.c
             src/main/cpp/c/input.h
             src/main/cpp/c/intro.c
             src/main/cpp/c/intro.h
             src/main/cpp/c/isometric.c
             src/main/cpp/c/isometric.h
             src/main/cpp/c/main.c
             src/main/cpp/c/main.h
             src/main/cpp/c/map.c
             src/main/cpp/c/map.h
             src/main/cpp/c/menu.c
             src/main/cpp/c/menu.h
             src/main/cpp/c/overview.c
             src/main/cpp/c/overview.h
             src/main/cpp/c/platform.c
             src/main/cpp/c/platform.h
             src/main/cpp/c/player.c
             src/main/cpp/c/player.h
             src/main/cpp/c/record.c
             src/main/cpp/c/record.h
             src/main/cpp/c/render.c
             src/main/cpp/c/render.h
             src/main/cpp/c/save.c
             src/main/cpp/c/save.h
             src/main/cpp/c/test.c
             src/main/cpp/c/test.h
             src/main/cpp/c/testtube.c
             src/main/cpp/c/testtube.h
             src/main/cpp/c/title.c
             src/main/cpp/c/title.h
             src/main/cpp/c/vent.c
             src/main/cpp/c/vent.h

             src/main/cpp/land/land.c)

include_directories(
    src/main/cpp
    )

set(NATIVE_LIB native)
set(JNI_FOLDER ${PROJECT_SOURCE_DIR}/src/main/allegro_jni_includes) # or wherever you put it
include(${JNI_FOLDER}/allegro.cmake)
