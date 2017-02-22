# README - KarelC #

## What is this repository for? ###

* This is an implementation of Karel the Robot in the C programming language. Karel can be used in introductory programming courses in order to lower barriers of entry for beginners. Karel focuses on problem solving from the beginning, while hiding programming language specific complexities from students. At the same time, Karel attempts to "feel real" by including required header files and being integrated into an IDE.
* KarelC should be compiled as a static library. Students can then write their own Karel programs, which can then be linked against the static library.
* Currently, KarelC supports the following IDEs: CodeBlocks (more tba)
* KarelC was built using [SDL (Simple Direct Media Layer)](https://www.libsdl.org/)
* Supported platforms: Windows
* 1.0
* Note: This is a very first rough and sketchy draft of the documentation


## Old Section
All information below ist for the folder old

### How do I get set up? ###
To compile the static library, carry out the following steps:

* Run batch file (karel_codeblocks_windows/Karel/buildscript/buildkarel.bat) to compile, link and pack the static library into the file libkarel.a
* Create your own Karel file (helloWorldKarel):

```
#include "karel.h"

void setup()
{
    loadWorld("LivingRoom");
}

void run()
{
    turnLeft();
    turnLeft();
    turnLeft();
}

```

* Compile the source file:
```
gcc -I"Z:\Documents\workspace\karelc\ideprojects\codeblocks_win\karel_starter_project\include" -c helloWorldKarel.c -o helloWorldKarel.o
```
* Link the source file against the previously compiled static library and against SDL:
```
gcc -o karel damagedpillartest.o buildscript\lib\libkarel.a -L"Z:\Documents\workspace\karelc\karel_codeblocks_windows\mingw\SDL-1.2.15\lib" -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf
```
Note: SDL dlls are required for linking

### Quickstart with Codeblocks ###
For Codeblocks, there is already a prebuilt and configured version of KarelC available. Carry out the following steps to get going.

* Checkout repository
* Copy folder ideprojects/codeblocks_win/karel_starter_project to a known location on your harddrive
* Start Codeblocks
* Open Codeblocks Project File (Karel.cbp)
* Compile, Run
* Edit your program and have fun

## New Section

### Build the Karrel Library
to bild the Karrel Library simply run:

```
make 
```

>The generated files are stored in the build directory

### Create StartProject
The library comes with a StartProject for Clion that have all needed files included.

The StartProject can be created with one of the following commands

>IDE = [ "clion", "codeblocks"] \
>PLATFORM = ["windows"] 
>
>make IDE_PLATFORM

```
make clion_windows
```
>And is located in StartProject

Additional you can also build all StarterProjects with

```
 make starterprojects
```
## TODO

* Bug fixing

