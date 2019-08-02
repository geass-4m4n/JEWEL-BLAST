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
## IMAGES USED 
THESE ARE DOWNLOADED IMAGES USED TO MAKE GAME. These were imported to the game using Simple and Fast Multimedia Library.
the images were manipulated to form the smooth running game


![alt tag](https://github.com/geass-4m4n/JEWEL-BLAST/blob/master/images/background.png)
![alt tag](https://github.com/geass-4m4n/JEWEL-BLAST/blob/master/images/gems.png)
## RUNNING CODE
1. download the project from github
2. apply the commands
```sh
$ g++ -c main.cpp
$ g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
```
3. Run the file 
```sh
$ ./sfml-app
```
## SCREENSHOTS
SCREENSHOTS OF GAME - 

![alt tag](https://github.com/geass-4m4n/JEWEL-BLAST/blob/master/ScreenShots/1s.png)
