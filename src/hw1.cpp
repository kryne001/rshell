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
						 
						if ((j + 1) <= commandName.size() && commandName.at(j + 1) == '>') 
							exeTemp.push_back(commandName.at(j));

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
					if ((index - 1) > 0) { 
						if (newLine.at(index - 1) != ">" || newLine.at(index - 1) != "<" 
							 || newLine.at(index - 1) != ">>") {
							newLine.push_back(temp1);
							newLineSize += temp1.size() + 1;
						}
					}
					else {
						temp1.insert(0, "bin/");
						newLine.push_back(temp1);
						newLineSize += temp1.size() + 1;
					}		
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
						temp1.insert(0, "bin/");
						newLine.push_back(temp2);
						newLineSize += temp2.size() + 1;
					}
				}


				isCmd = false;

			}
		}
		if (newLine.size() > 0)
			x.push_back(newLine);
		cout << "x[0][0]: " << x[0][0] << endl;
	}


}
