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

		istringstream commandStream(commandLine);
		char* commandName;
		vector<char*> commands;
		int i = 0;
		
		while (commandStream >> commandName)
			commands.push_back(commandName);
		
		if (commands.at(0) == "exit") 
			exit(1);

		char* directory = "/usr/bin/";
		strncat (directory, commandName, 20);

		char** argc = new char*[commands.size()];

		for (i = 0; i < commands.size(); ++i) {
			argc[i] = commands.at(i);
		}	
		int pid = fork();
		if (pid == 0) {

			if (-1 == (execv(directory, (char *const*)argc))) {
				perror("execv failed");
				exit(1);
			}
			exit(0);
		}
		else if (pid > 0) {
			wait(0);
		}
	}	
}
