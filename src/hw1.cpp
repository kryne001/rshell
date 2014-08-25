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

void changeDirectory(string input) {
	char* dir = new char[1024];
	if (NULL == getcwd(dir, 1024))
		perror("getcwd failed");
	
}


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
		string filename;
		bool right = false, left = false, twoRight = false;
		for (int i = 0; commandStream >> commandName; ++i) {
			if (commandName == "exit")
				exit(0);
			if (commandName == ">") 
				right = true;
			else if (commandName == "<")
				left = true;
			else if (commandName == ">>")
				twoRight = true;
			else if (commandName != "&") {
				if (!right && !left && !twoRight)
					newLine.push_back(commandName);
				else
					filename = commandName;
			}
		}

		char *x;
		if (NULL == (x = getenv("PATH"))) {
			perror("getenv failed");
			continue;
		}
		vector<string> paths;
		string path;
		path.append(x);
		unsigned index = 0;
		for (unsigned i = 0; i < path.size(); ++i) {
			if (path.at(i) == ':') {
				string temp = path.substr(index, i - index);
				paths.push_back(temp);
				index = i + 1;
			}
		}

		for (unsigned i = 0; i < paths.size(); ++i) {
			if (paths.at(i).at(paths.at(i).size() -1 ) != '/')
				paths.at(i).append("/");
		}
		int pid;
		if (-1 == (pid = fork())) {
			perror("fork failed");
			exit(1);
		}
		if (pid == 0) {
			
			if (right) {
				int fd;
				if (-1 == (fd = open(filename.c_str(), O_RDWR | O_CREAT, 0777)))
					perror("open failed");
				if (-1 == (close(1)))
					perror("close failed");
				if (-1 == (dup(fd)))
					perror("dup failed");
			}
			for (unsigned i = 0; i < paths.size(); ++i) {
				string temp = paths.at(i);
				temp.append(newLine.at(0));
				vector<string> x;
				x.push_back(temp);
				unsigned x_size = newLine.at(0).size() + 1;
				for (unsigned j = 1; j < newLine.size(); ++j) {
					x_size += newLine.at(j).size() + 1;
					x.push_back(newLine.at(j));
				}

				char **commands = (char**)malloc(x_size * sizeof (char*));
				int a = 0;
				for (unsigned j = 0; j < x.size(); ++j) {
					commands[j] = (char*)malloc((x.at(j).size() + 1) * sizeof (char*));
					strcpy(commands[j], x.at(j).c_str());
					++a;
				}
				commands[a] = NULL;
				execv(commands[0], commands);
			}
				perror("execv failed");
		}
		else if (pid > 0)
			wait(0);
		
		
		
	}
}
