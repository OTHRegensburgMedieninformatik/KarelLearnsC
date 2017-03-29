# README - KarelC #

## What is this repository for? ###

* This is an implementation of Karel the Robot in the C programming language. Karel can be used in introductory programming courses in order to lower barriers of entry for beginners. Karel focuses on problem solving from the beginning, while hiding programming language specific complexities from students. At the same time, Karel attempts to "feel real" by including required header files and being integrated into an IDE.
* KarelC should be compiled as a static library. Students can then write their own Karel programs, which can then be linked against the static library.
* Currently, KarelC supports the following IDEs: CodeBlocks and CLion
* KarelC was built using [SDL (Simple Direct Media Layer)](https://www.libsdl.org/)
* Supported platforms: Windows
* 1.0
* Note: This is a very first rough and sketchy draft of the documentation


### How do I get set up (Windows only!)? ###
To build the Karel Library simply run make from the project's root folder:

```
make 
```

>The generated files are stored in the build directory

### Create starter projects for IDEs
The library comes with preconfigured starter projects for Clion and Codeblocks. These projects include the compiled library as well as a starter hello world file that can be compiled and linked against the library. Everything should already be set up correctly. Simple open the starter project with the respective IDE and hit compile and run.

>Hint Clion needed as separated build script. It is located in the StarterProject folder. 
>Please run "build.bat" befor you open it in Clion

The starter projects can be created with one of the following commands

>IDE = [ "clion", "codeblocks"] \
>PLATFORM = ["windows"] 
>
>make IDE_PLATFORM

So
```
make clion_windows
```
creates the starter project for Clion under Windows in the folder StartProject.

Additionally all starter projects can be built at once with

```
 make starterprojects
```

### Create server library for Praktomat
The library can also be builded as a gui-less server library for the web application 'Praktomat'. The KarelLearnsC project has to be built on the target server in order to run properly.
To build the Karel library simply run
```
make linux_server
```
from the project's root folder via commandline/terminal.
The command will also copy all relevant files into the usr/include/ folder from where it can be used from the praktomat scripts.

## TODO

* Bug fixing

