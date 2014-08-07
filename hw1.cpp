#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int main() {
	string commandLine;
	while (1) {
		
		cout << "$ ";
		getline(cin, commandLine);
		
		bool isComment = false;
		int commentIndex = 0;
		for (int i = 0; i < commandLine.size(); ++i) {
			if (commandLine.at(i) == '#') {
				commentIndex = i;
				isComment = true;
			} 
		}

		if (isComment) {
			commandLine.erase(commentIndex, commandLine.size() - commentIndex);
		}

		bool isAmp = false;

		for (int i = 0; i < commandLine.size(); ++i) {
			if (commandLine.at(i) == '&') {
				isAmp = true;
			}
		}

		istringstream commandStream(commandLine);
		string commandName;
		
		char** commands = (char**)malloc(commandLine.size());

		for (int i = 0; commandStream >> commandName; ++i) {
			commands[i] = (char*)malloc(commandName.size());
			commands[i] = (char*)commandName.c_str();
		}
		
		if (commands[0] == "exit") 
			exit(1);

		char* targetDirectory = (char*)malloc(commandLine.size());
		targetDirectory = "/usr/bin";	
		//strncat (targetDirectory, commands[0], 20);

		int pid = fork();
		if (pid == 0) {

			if (-1 == (execv(targetDirectory, commands))) {
				perror("execv failed");
				exit(1);
			}
			exit(0);
		}
		else if (pid > 0 && !isAmp) {
			wait(0);
		}
		for (int i = 0; i < commandLine.size(); ++i) {
			free(commands[i]);
		}
		free(commands);
	}	
}
