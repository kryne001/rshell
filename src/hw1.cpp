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
		vector<string> newLine;
		bool isCmd = false;
		unsigned index = 0;
		int newLineSize = 0;
		vector<vector<string> > x;
		for (int i = 0; commandStream >> commandName; ++i) {
			
			if (commandName == "exit") {
				exit(1);
			}
			if (commandName != "&") {
				string temp1;
				string temp2;
				string exeTemp;
				for (unsigned j = 0; j < commandName.size(); ++j) {
					if (commandName.at(j) == '>' || commandName.at(j) == '<') {
						 
						if ((j + 1) < commandName.size()) {
							if (commandName.at(j + 1) == '>') 
								exeTemp.push_back(commandName.at(j));
						}
						exeTemp.push_back(commandName.at(j));
						isCmd = true;
					}
					
					else if(!isCmd) 
						temp1.push_back(commandName.at(j));
						
					else if (isCmd) 
						temp2.push_back(commandName.at(j));
					
				}
				if (temp1.size() > 0) {
					++index;	
					if ((index - 1) > 0 && (index - 1) < newLine.size()) { 
						if (newLine.at(index - 1) != ">" || newLine.at(index - 1) != "<" 
							/* || newLine.at(index - 1) != ">>"*/) {
							newLine.push_back(temp1);
							newLineSize += temp1.size() + 1;
						}
					}
					else if (newLine.size() == 0) {
						temp1.insert(0, "/bin/");
						newLine.push_back(temp1);
						newLineSize += temp1.size() + 1;
					}		
					else 
						newLine.push_back(temp1);
				}

				if (exeTemp.size() > 0 && exeTemp != "|") {
					++index;
					newLine.push_back(exeTemp);
					newLineSize += exeTemp.size() + 1;
				}
				else if (exeTemp.size() > 0 && exeTemp == "|") {
					x.push_back(newLine);
					newLine.clear();
				}	

				
				if (temp2.size() > 0) {
					++index;
					if ((index - 1) > 0 && newLine.at(index - 1) != ">" ||
						  newLine.at(index - 1) != "<" || newLine.at(index - 1) != ">>") {
						newLine.push_back(temp2);
						newLineSize += temp2.size() + 1;
					}
					else {
						newLine.push_back(temp2);
					}
				}


				isCmd = false;

			}
		}
		if (newLine.size() > 0)
			x.push_back(newLine);

		int pfd[2];
		vector<int> numOfPid;
		char** commands; 
		int fd;
		for (unsigned i = 0; i < x.size(); ++i) {
			int pid;

			if (-1 == (pid = fork())) 
				perror("fork failed");

			numOfPid.push_back(pid);
			if (pid == 0) {
				if (i != 0) {
					if (-1 == close(pfd[0])) 
						perror("close failed");
					if (-1 == dup(pfd[0])) 
						perror("dup failed");
				}
				if (i != x.size() -1) {
					if (-1 == pipe(pfd)) 
						perror("pipe failed");
					if (-1 == close(1))
						perror("close failed");
					if (-1 == dup(pfd[1]))
						perror("dup failed");
				}
				if (i == 0) {
					if (x.at(i).size() > 1) {
						if (x.at(i).at(1) == "<" || x.at(i).at(1) == ">") {
						
							if (-1 == (fd = open(x.at(i).at(2).c_str(), O_RDWR | O_CREAT))) 
								perror("open failed");
							if (-1 == close(0))
								perror("close failed");
							if (-1 == dup(fd))
								perror("close failed");
						}

						else if (x.at(i).at(1) == ">>") {
							
							if (-1 == (fd = open(x.at(i).at(2).c_str(), O_RDWR | O_CREAT))) 
								perror("open failed");
							if (-1 == close(0))
								perror("close failed");
							if (-1 == dup(fd))
								perror("close failed");
						
						}	
					}
					//else {
						
				
				}
				if (i == x.size() - 1) {
					if (-1 == close(1))
						perror("close failed");
					if (-1 == dup(fd))
						perror("dup failed");
				}
				commands = (char**)malloc((x.at(i).at(0).size() + 1) * sizeof(char*));
				commands[0] = (char*)malloc((x.at(i).at(0).size() + 1) * sizeof(char*));
				strcpy(commands[0], x.at(i).at(0).c_str());
				if (-1 == execv(commands[0], commands)) 
					perror("exec failed");
			}
		}
		for (unsigned i = 0; i < numOfPid.size(); ++i) 
			if (-1 == wait(&numOfPid.at(i)))
				perror("wait failed");

	}


}
