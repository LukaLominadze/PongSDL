# PongSDL
A recreation of the classic game of Pong in C++ using SDL2.
![image](https://github.com/LukaLominadze/PongSDL/assets/142942110/b14683b6-e745-411d-93b3-ad4a78a62491)

This project is served as an exercise of developing applications with an OOP nature. The concept of a game is perfect for execises like these, since it requires a lot of different kinds of features to come together for the application to function.

## Getting Started
It is recommended to use Visual Studio 2020-2022 with this project, but you are free to use any IDE for this.

### 1. Download the repository:
Start by cloning the repository with 
```cmd
git clone https://github.com/LukaLominadze/PongSDL
```

### 2. Building with premake:
If you're unfamiliar with premake and don't know how to download it, refer to this link : https://premake.github.io/download/
'Premake is a small command line executable, delivered as a single file. Just unpack the download and place the executable on your system search path, or anywhere else convenient.' - https://premake.github.io/docs/Using-Premake

If you decide to not put the executable in the system, you can simply put it in the parent directory (where premake5.lua is located).

By running the cmd in the cloned repository, run the command:
```cmd
premake5 [action]
```
Where action specifies the IDE which this project file will be generated for, for example:
```cmd
premake5 vs2022
```
Refer to this link for a list of project files that can be created with premake: https://premake.github.io/docs/Using-Premake

if your IDE is not listed in the list, you can simply generate a makefile with premake:
```cmd
premake5 gmake
```
or
```cmd
premake5 gmake2
```

### 3. Dependencies
This project uses the SDL2 library, which is already provided in the repo, in the 'vendor' folder, but if you are having issues here is the download page: https://github.com/libsdl-org/SDL/releases
