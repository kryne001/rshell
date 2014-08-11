all: rshell ls

rshell:
	
	g++ -Wall -Werror -ansi -pedantic src/hw1.cpp -o bin/rshell
ls:
	g++ -Wall -Werror -ansi -pedantic src/ls.cpp -o bin/ls
