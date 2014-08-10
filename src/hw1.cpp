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
		char* loginName = (char*)malloc(100);
		loginName = getlogin();
		char* getHost = new char[100];:
		gethostname(getHost, 100);
		gethostname(getHost, 100);
		cout << loginName << "@" << getHost << "$ ";
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
		
		char** commands = (char**)malloc(commandLine.size() + 100);

		string tD = "/bin/";
		int size = 0;
		for (int i = 0; commandStream >> commandName; ++i) {
			if (i == 0) {
				tD.append(commandName);
				commands[i] = new char[tD.size() + 1];
				commands[i] = (char*)tD.c_str();
			}
			else if (commandName != "&") {	
				commands[i] = new char[commandName.size() + 1];
				commands[i] = (char*)commandName.c_str();
			}
			++size;
		}
		if (tD == "/bin/exit") 
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
		else if (pid > 0 && isAmp) {
			continue;
		}
		
		for (int i = 0; i < size; ++i) {
			delete [] (&commands[i]);
		}

		free(&commands);
		delete [] loginName;
		delete [] getHost;
	}	
}
