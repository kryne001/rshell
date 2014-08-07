Assignment 1: rshell
======

In this assignment, I attempted to make a simple command shell comprising of all the commands avaiable to me in the /usr/bin folder. This program is able to execute not only the commands availabe in the folder, but also the flags associated to the commands.

The way the program works is the user is prompted a line that consists of the users login info, their host name, and the '$' symbol, which is immediately followed by the area for user input. The user then enters the command, and the command is executed and printed to the terminal. The process is intended to continue as such until the user inputs 'exit', which then causes the program to exit.

For example, if the user enters 'ls', the program will print to the terminal all the contents in the current directory. If the user then enters 'ls -a', the program will print to the terminal all the contents in the current directory and also execute the '-a' flag, which includes the contents in the directory that starts with a '.'. 

BUGS
======
The program will only execute one iteration and then fail due to being unable to free the memory properly. All commands in the '/usr/bin' folder (along with their flags) will execute properly, but just fail after the whole iteration ends.
