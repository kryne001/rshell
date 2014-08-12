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
	
	struct directoryInCurrent;
	int errorCheck;
	if (-1 == (errorCheck = stat(directoryName, directoryInCurrent))) {

		perror("stat failed");
		exit(0);
	}
}


int main(int argc, char** argv[]) {
	
	if (argc == 1) {
		
		char const *dirName = ".";
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
	
	else {
		
		vector<string> directories;
		vector<string> flags;
		for (unsigned i = 1; i < argc; ++i) {
			
			if (argv[i][0] == '-') {
				flags.push_back(argv[i]);
			}
			else {
				
			}
		}
	}
	


}


