#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
using namespace std;

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
	


}


