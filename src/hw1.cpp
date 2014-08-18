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
		gethostname(host, sizeof host);
		cout << getlogin()  << "@" << host << "$ ";
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
		vector<string> newLine;
<<<<<<< HEAD
		vector<string> files;
		vector<string> exe;
		bool isRight = false;
		for (int i = 0; commandStream >> commandName; ++i) {
			
			if (commandName != "&") {
				string temp1;
				string temp2;
				string exeTemp;
				for (unsigned i = 0; i < commandName.size(); ++i) {
					if (commandName.at(i) == '>') {
					
						exeTemp.push_back(commandName.at(i));
						isRight = true;
						continue;
					}
					else if(!isRight) 
						temp1.push_back(commandName.at(i));
						
					else if (isRight) 
						temp2.push_back(commandName.at(i));
					
				}
				newLine.push_back(temp1);
				if (temp2.size() > 0)
					newLine.push_back(temp2);
				if (exeTemp.size() > 0)
					exe.push_back(exeTemp);
=======
<<<<<<< HEAD

		for (int i = 0; commandStream >> commandName; ++i) {
			
			if (commandName != "&") {
				newLine.push_back(commandName);
=======
		vector<string> type;
		vector<string> files;
		for (int i = 0; commandStream >> commandName; ++i) {
			
			if (commandName != "&") {
				for (unsigned i = 0; i < commandName.size(); ++i) {
					if (commandName.at(i) != ">" && commandName.at(i) != "
					
>>>>>>> 9f815b25d0fec28ea931123b80e49a35da9da361
>>>>>>> 0ddda4caec51e9aa4fae5d68768f8f79236a6252
			}
		}


		int commandLineSize = newLine.size() + 1;	
		char** commands = (char**)malloc(commandLineSize * sizeof(char*));
		
		string tD = "/bin/";
		int size = 0;
		for (unsigned i = 0; i < newLine.size(); ++i) {
			if (i == 0) {
				tD.append(newLine.at(i));
				commands[i] = (char*)malloc((tD.size() + 1) * sizeof(char*));
				strcpy(commands[i], tD.c_str());
			}
			else if (newLine.at(i) != "&") {	
				commands[i] = (char*)malloc((newLine.at(i).size() + 1) * sizeof(char*));
				strcpy(commands[i], newLine.at(i).c_str());
			}
			++size;
		}
		if (size == 0) {
			continue;
		}
		if (tD == "/bin/exit") 
			exit(1);

		

		int pid = fork();
		if (pid == 0) {
			if (isRight == true) {	
				int x = open("test.txt", O_RDWR | O_CREAT, 0777);
				if (x == -1) {
			
<<<<<<< HEAD
					perror("open failed");
					exit(1);
				}
=======
			int x = open("test.txt", O_RDWR | O_CREAT, 0777);
			if (x == -1) {
			
				perror("open failed");
				exit(1);
			}
<<<<<<< HEAD

			if (-1 == (close(1))) {

				perror("close failed");
				exit(1);
			}

=======
>>>>>>> 0ddda4caec51e9aa4fae5d68768f8f79236a6252

				if (-1 == (close(1))) {

					perror("close failed");
					exit(1);
				}	

<<<<<<< HEAD
				if (-1 == (dup(x))) {
=======
>>>>>>> 9f815b25d0fec28ea931123b80e49a35da9da361
			if (-1 == (dup(x))) {
>>>>>>> 0ddda4caec51e9aa4fae5d68768f8f79236a6252
			
					perror("dup failed");
					exit(1);
				}		
			}
			if (-1 == (execv(commands[0], commands))) {
				
				perror("execv failed");
				exit(1);
			}
		
		}
		else if (pid > 0 && !isAmp) {

				wait(NULL);
				for (int i = 0; i < size; ++i) {
					free(commands[i]);
				}
				
				free(commands);
		}
		else if (pid > 0 && isAmp) {

				for (int i = 0; i < size; ++i) {
					free(commands[i]);
				}
				
				free(commands);
				continue;
		}
	}	
}
