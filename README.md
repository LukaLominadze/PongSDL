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
After cloning the repository, open the "premake5.bat" from the main directory. You will see the list of build options in the command prompt, input the one you need to proceed:
![image](https://github.com/LukaLominadze/PongSDL/assets/142942110/8b66d81b-ef8d-4ba9-9b10-f40a836fd2da)

if your IDE is not listed in the list, you can simply generate a makefile with premake:
```cmd
gmake
```
or
```cmd
gmake2
```

### 3. Dependencies
This project uses the SDL2 library, which is already provided in the repo, in the 'vendor' folder, but if you are having issues here is the download page: https://github.com/libsdl-org/SDL/releases
