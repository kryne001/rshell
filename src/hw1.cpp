#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <string.h>
using namespace std;

int main() {
	string commandLine;
	while (1){
		char host[128];
		if (-1 == (gethostname(host, sizeof host))) {
			perror("get host name failed");
			exit(1);
		}
		char login[128];
		if (getlogin_r(login, sizeof(login) -1)) {
			perror("login failed");
			exit(1);
		}
		cout << login <<  "@" << host << "$ ";
		getline(cin, commandLine);
		
		bool isComment = false;
		int commentIndex = 0;
		for (unsigned int i = 0; i < commandLine.size(); ++i) {
			if (commandLine.at(i) == '#') {
				commentIndex = i;
				isComment = true;
			} 
		}

		if (isComment) {
			commandLine.erase(commentIndex, commandLine.size() - commentIndex);
		}

		bool isAmp = false;

		for (unsigned int i = 0; i < commandLine.size(); ++i) {
			if (commandLine.at(i) == '&') {
				isAmp = true;
			}
		}

		istringstream commandStream(commandLine);
		string commandName;
		string tempHolder;
		vector<string> newLine;
		for (int i = 0; commandStream >> commandName; ++i) {
			if (commandName == "exit")
				exit(0);
			if (commandName == ">") 
				right = true;
			else if (commandName == "<")
				left = true;
			else if (commandName == ">>")
				twoRight = true;
			else if (commandName != "&")
				newLine.push_back(commandName);
		}

		for (unsigned i = 0; i < newLine.size(); ++i) {
			if (newLine.at(i).at(0) == '-') 
				newLine.at(i - 1).insert(newLine.at(i).size() - 1, newLine.at(i));
		}
		
		for (unsigned i = 0; i < newLine.size(); ++i)
			cout << "newLine at " << i << " = " << newLine.at(i) << endl;
	}
}
