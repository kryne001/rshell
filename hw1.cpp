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
		
		char** commands = (char**)malloc(commandLine.size() + 8);

		string tD = "/bin/";
		int size = 0;
		for (int i = 0; commandStream >> commandName; ++i) {
			if (i == 0) {
				tD.append(commandName);
				commands[i] = (char*)malloc(tD.size() + 8);
				commands[i] = (char*)tD.c_str();
			}
			else {	
				commands[i] = (char*)malloc(commandLine.size() + 8);
				commands[i] = (char*)commandName.c_str();
			}
			++size;
		}
		if (commands[0] == "exit") 
			exit(1);

		int pid = fork();
		if (pid == 0) {

			if (-1 == (execv(commands[0], commands))) {
				perror("execv failed");
				exit(1);
			}
			exit(0);
		}
		else if (pid > 0 && !isAmp) {
			wait(0);
		}
		free(commands);
	}	
}
