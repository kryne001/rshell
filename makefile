all:
	g++ -Wall -Werror -ansi -pedantic -g --debug  src/hw1.cpp -o bin/rshell
rshell:
	
	g++ -Wall -Werror -ansi -pedantic src/hw1.cpp -o bin/rshell
