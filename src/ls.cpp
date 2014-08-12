#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
using namespace std;

bool isDirectory(char* directoryName) {
	
	struct stat directoryInCurrent;

	if (-1 == (stat(directoryName, &directoryInCurrent))) {

		perror("stat failed");
		return false;
	}

	if (directoryInCurrent.st_mode & S_IFDIR) {
		return true;
	}
	else {
		return false;
	}
}

int ls(char* directoryName) {

	
		char const *dirName = ".";
		DIR *dirp;
		if (!(dirp = opendir(dirName))) {
			cerr << "Error(" << errno << ") opening " << dirName << endl;
		}

		dirent *direntp;
		while ((direntp = readdir(dirp))) {
			if (direntp->d_name[0] != '.') {
					
				//cout << direntp->d_name << endl; // use stat here to find attributes of a file
				printf(direntp->d_name, 8);
				cout << " ";
			}
		}
		cout << endl;
		closedir(dirp);
		return 0;
}
bool lsWithFlags(char* directoryName, vector<string> flags) {

	bool isA = false;
	bool isL = false;
	bool isR = false;
	for (unsigned i = 0; i < flags.size(); ++i) {
	
		if (flags.at(i) == "a") 
			isA = true;
		else if (flags.at(i) == "l") 
			isL = true;
		else if (flags.at(i) == "R")
			isR = true;

	}
	char const *dirName = directoryName;
	DIR *dirp;
	if (!(dirp = opendir(dirName))) {
		cerr << "Error(" << errno << ") opening " << dirName << endl;
		return errno;
	}

	dirent *direntp;
	while ((direntp = readdir(dirp))) {
		if (direntp->d_name[0] != '.') {
					
			//cout << direntp->d_name << endl; // use stat here to find attributes of a file
			printf(direntp->d_name, 8);
			cout << " ";
		}
	}
	cout << endl;
	closedir(dirp);
}

int main(int argc, char* argv[]) {
	
	if (argc == 1) {
		
		if (errno == ls(".")) {
		
			return errno;
		}
	}	
	
	/*else {
		
		vector<string> directories;
		vector<string> flags;
		for (int i = 1; i < argc; ++i) {
			
			if (argv[i][0] == '-') {
				flags.push_back(argv[i]);
			}
			else {

				if (isDirectory(	
			}
		}
	}*/
	


}


