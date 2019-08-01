# JEWEL-BLAST





## ABOUT!
JEWEL - BLAST is a free-to-play match-three puzzle video game 

## CONTRIBUTORS
* Aman Agrawal

## ADDING REQUIRED LIBRARIES

### Add GLFW and GL library to your /usr/include folder

1. Download GLFW source files from http://www.glfw.org/download.html
2. Install Build Dependencies by running 
```sh
$ sudo apt-get install cmake xorg-dev libglu1-mesa-dev
```
3. cd in GLFW directory downloaded in step 1
4. Run the command  in terminal 
```sh
$ cmake -G "Unix Makefiles"
$ sudo make
$ sudo make install
```
### Next step is to add glad libraries
1. Copy the glad and KHR folder into /usr/include/
2. Make sure to keep glad.c in the same directory as main.cpp

### Add Simple and Fast Multimedia Library to your SYSYTEM
```sh
$ sudo apt-get install libsfml-dev
```
