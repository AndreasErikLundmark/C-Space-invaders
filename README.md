# C-Space-invaders

Space Wing // Andreas Lundmark
Notes

The game was built to represent a small game engine and is an example of what can be build with it. The game is playable but not completely finished

SDL2 must be installed!!!
The game is built in VSCode.
See the project's makefile that the program is built with and uncomment library paths as needed.


 LIBRARY FILES – compiled object code
# Mac INTEL LIBRARY_PATHS!
LIBRARY_PATHS = -Llib -L/usr/local/lib
# Mac ARM LIBRARY_PATHS!
#LIBRARY_PATHS = -Llib -L/sr/local/Cellar/sdl2_ttf
# Windows LIBRARY_PATHS
#LIBRARY_PATHS = -Llib -LC:/msys64/ucrt64/lib


Associated images, music and font can be found in the resources folder in each folder.
Build the game through “make” in the terminal.
Then "./build/debug/play"


Classes:
Game engine
GameEngine.h - containing run()
System.h
Sprite.h - Base class for all 2d components
Button.h - Subclass to sprite with support for building your own buttons


Game
Shot.h
Player.h
Enemy.h
VolumeButtonDown.h
VolumeUpButton.h
NextSongButton.h
Label.h


Main.cpp - see main to easily modify the appearance and behavior of game components. Here Player must be created and Enemy must be created, as well as optional button classes.


Game instructions


The player moves his spaceship using the right and left arrow keys on the keyboard.
The player fires a shot by pressing the UP arrow key on the keyboard
Buttons are mouse clickable. Try changing the song!
The game is primarily an ambient space experience. Therefore, points are not counted.

