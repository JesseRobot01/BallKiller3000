# **BallKiller3000**

- You can download the newest version [here](https://github.com/JesseRobot01/BallKiller3000/releases).
- Or you can download the newest beta build
  on [GitHub actions](https://github.com/JesseRobot01/BallKiller3000/actions).
  <br><br>
- You can play the stable online version [here](https://jesserobot01.github.io/BallKiller3000/).
- Or you can play the newest beta version online [here](https://jesserobot01.github.io/BallKiller3000/beta).

## Building

### Requirement

- CMake
- [Emscripten SDK](https://emscripten.org/docs/getting_started/downloads.html) (for building for the web) (optional)

The build progress is only tested on windows with mingw and Ninja. but it should work fine with other build systems.

### Building

Run these commands:

```
mkdir build
cmake -B build -G Ninja
cmake --Build build
```

#### For the web

Run the following commands:

``` 
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3" -DCMAKE_EXECUTABLE_SUFFIX=".html" -G Ninja
ninja
```


#### For Ubuntu

Run the following commands:

``` 
sudo apt install ninja-build libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev
mkdir build
cmake -B build
cmake --build build
```

## Tools

It's only tested with Clion.

### Clion

The default settings work fine for windows.
If you want to build it for web there is some additional configuration needed

#### Configurations for building for the web.

- Go to `settings -> Build, Execution, Deployment -> CMake`
- Make a new profile and set this as CMake
  option: `-DPLATFORM=Web "-DCMAKE_TOOLCHAIN_FILE=<PATH TO EMISCRIPTEN HERE>/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake"`
