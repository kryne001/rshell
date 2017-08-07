Tutorial series 
======

My Partner and I created a tutorial series centered around vim and github for this class. It goes over the basics of vim and github to serve as a starting point for beginners.

https://izbicki.me/blog/videoguide-for-github-vim-bash.html

Assignment 1: rshell
======

In this assignment, I attempted to make a simple command shell comprising of all the commands avaiable to me in the /usr/bin folder. This program is able to execute not only the commands availabe in the folder, but also the flags associated to the commands.

The way the program works is the user is prompted a line that consists of the users login info, their host name, and the '$' symbol, which is immediately followed by the area for user input. The user then enters the command, and the command is executed and printed to the terminal. The process is intended to continue as such until the user inputs 'exit', which then causes the program to exit.

For example, if the user enters 'ls', the program will print to the terminal all the contents in the current directory. If the user then enters 'ls -a', the program will print all the files in the current directory including the hidden files.

Assignment 2: ls
======

In this assignment, the `ls` command is implemened. When executed without any arguments, the program will print the contents of the current directory. The name of the executable is `bin/ls`.

The program takes in two types of arguments, which are optional: directory or file names, and flags.

If the user adds the names of directories or files into the command line after the executable, the program will execute the ls command on those directories or files.

The program also implements the `-l`, `-a`, and `-R` flags. 

The `-l` flag print the contents of the current directory with stats for each item. These stats, from left to write, print the read, write, and executable permissions for each user in the computer; the number of hard links; the user and group IDs of the owner of the file; the size of the file; the last time it was modified; and finally, the name of the file itself.

The `-a` flag prints all contents that start with a '.'

the `-R` flag not only prints the contents in the current directory, but also recursively prints all the contents in all the directories in the current directory, along with the contents of directories in those directories.

The combination of all the three flags also works, in any order, as long as the command is prepended with the `-` symbol. Any directories or files passed in will execute according to the flags passed in as well.

BUGS
======
Assignment 1:

The program will only execute one iteration and then fail due to being unable to free the memory properly. All commands in the '/usr/bin' folder (along with their flags) will execute properly, but just fail after the whole iteration ends.

Assignment 2: 

-R will only go into one folder then stop. When running -l, all files will have 'l' for symbolically linked file. 
the program will only work for contents in directories accessible in the current directory and the current directory


