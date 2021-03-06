# Snake Game

This project is start from the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>


## How to play
The playing of this snake game is pretty like the traditional one, but be careful with the Asteriod.
Asteriod is comming randomly from left top corner, whenever your tiny beauty is hit by it, the game ends.


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## structure


## rubic points addressed  

1. README  
- [x] A README with instructions is included with the project  
- [x] The README indicates which project is chosen  
- [x] The README includes information about each rubric point addressed  
- [x] The submission must compile and run  

2. Loops, Functions, I/O  
- [x] The project demonstrates an understanding of C++ functions and control structures  
    * ***main.cpp** -- line 29*
- [x] The project reads data from a file and process the data, or the program writes data to a file  
    * ***main.cpp** -- line 28*  
- [x] The project accepts user input and processes the input  
    * ***main.cpp** -- line 18*  

3. Object Oriented Programming  
- [x] The project uses Object Oriented Programming techniques  
- [x] Classes use appropriate access specifiers for class members  
- [x] Class constructors utilize member initialization list 
    * ***game_object.h** -- line 13* 
- [x] Classes abstract implementation details from their interfaces  
- [x] Classes encapsulate behavior  
    * ***game_object.h** -- line 35-38*
    * ***snake.h** -- line 14-18*
- [x] Classes follow an appropriate inheritance hierarchy  
    * ***game_object.h, snake.h, asteriod.h***  
- [x] Overloaded functions allow the same function to operate on different parameters 
    * ***snake.h** -- line 21-23*  
- [x] Derived class functions override virtual base class function 
    * ***game_object.h** -- line 41* 
- [x] Templates generalize functions in the project  
    * ***game.h** -- line 17, 68*

4. Memory Management  
- [x] The project makes use of references in function declarations  
    * ***snake.h** -- line 23*
    * ***asteriod** -- line 26*
- [x] The project uses destructors approprately  
    * ***game.cpp** -- line 21-27*
- [x] The project uses scope Resource Acquisition Is Initialization (RAII) where appropriate  
    * ***game.cpp***
- [x] The project follows the Rule of 5  
    * ***asteriod.h** --  line 10-17*
- [x] The project uses move semantics to move data, instead of copying it, where possible
    * ***asteriod.cpp** -- line 37*
    * ***game.h** -- line50*
- [x] The project uses smart pointers instead of raw pointers
    * ***game.h** -- line 76, 77*
    * ***game_object.h** -- line 48*
    * ***snake.h** -- line 38*

5. Concurrency  
- [x] The project uses multithreading  
    * ***game.cpp** -- line 92*
- [x] Promise and future is used in the project  
    * ***game.cpp** -- line 92*
- [x] A mutex or lock is used in the project
    * ***game.h** -- line 33, 46*
- [x] A condition variable is used in the project  
    * ***game.h** -- line 22, 35, 51*