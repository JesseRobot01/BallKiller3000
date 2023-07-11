# **Ball Killer 3000**

- You can download the newest version [here](https://github.com/JesseRobot01/Ball_Killer_3000/releases).
- Or you can download the newest nightly build
  on [GitHub actions](https://github.com/JesseRobot01/Ball_Killer_3000/actions).

## Building

### Requirement

- CMake
- [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) (for building for the web) (optional)

The build progress is only tested on windows with mingw and Ninja. but it should work fine with other build systems.

### Building

Run ```CMake -B build -G Ninja``` && ```CMake --Build build```.

#### For the web

Run the following commands:
```mkdir build```. <br>
```cd build```.<br>
``` emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3" -DCMAKE_EXECUTABLE_SUFFIX=".html" -G Ninja```.<br>
```ninja```.

## Tools

It's only tested with Clion.

### Clion

The default settings work fine for windows.
If you want to build it for web there is some additional configuration needed

#### Configurations for building for the web.

Go to `settings -> Build, Execution, Deployment -> CMake`
Make a new profile and set this as CMake
option: `-DPLATFORM=Web "-DCMAKE_TOOLCHAIN_FILE=<PATH TO EMISCRIPTEN HERE>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"`
