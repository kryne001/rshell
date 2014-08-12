#include <pwd.h>
#include <grp.h>
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

void printDashL(char* directoryName, vector<string> flags);
bool isDirectory(char* directoryName) {
	
	struct stat directoryInCurrent;

	if (-1 == (stat(directoryName, &directoryInCurrent))) {

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
	if (!isDirectory(directoryName)) {
		cout << directoryName << endl;
		return 1;
	}
	
		
	
		char const *dirName = directoryName;
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
		if (-1 == closedir(dirp)) {
			perror("close directory failed");
			exit(1);
		}
		return 0;
}

void printDashL(char* directoryName, vector<string> flags) {

	
		bool isA = false;
		bool isL = false;
		bool isR = false;
		for (unsigned i = 0; i < flags.size(); ++i) {
			for (unsigned k = 0; k < flags.at(i).size(); ++k) {
				if (flags.at(i).at(k) == 'a') 
					isA = true; // there's an -a flag
				else if (flags.at(i).at(k) == 'l') 
					isL = true; // there's an -l flag
				else if (flags.at(i).at(k) == 'R')
					isR = true; // there's an -R flag
			}

		}	
		struct stat current;
		struct passwd *x;
		struct group *y;
		if (-1 == (stat(directoryName, &current))) {
			perror("stat failed");
			return;
		}
				if (current.st_mode & S_IFDIR) 
					cout << "d";
				
				if (current.st_mode & S_IFLNK)
					cout << "l";
				
				if (!(current.st_mode & S_IFDIR) && !(current.st_mode & S_IFLNK))
					cout << "-";

				if (current.st_mode & S_IRUSR)
					cout << "r";
				else
					cout << "-";

				if (current.st_mode & S_IWUSR)
					cout << "w";
				else
					cout << "-";
				
				if (current.st_mode & S_IXUSR)
					cout << "x";
				else
					cout << "-";

				if (current.st_mode & S_IRGRP)
					cout << "r";
				else
					cout << "-";

				if (current.st_mode & S_IWGRP)
					cout << "w";
				else
					cout << "-";

				if (current.st_mode & S_IXGRP)
					cout << "x";
				else
					cout << "-";

				if (current.st_mode & S_IROTH)
					cout << "r";
				else
					cout << "-";

				if (current.st_mode & S_IWOTH)
					cout << "w";
				else
					cout << "-";

				if (current.st_mode & S_IXOTH)
					cout << "x";
				else
					cout << "-";

				cout << " ";

				cout << current.st_nlink << " ";

				if ((x = getpwuid(current.st_uid)) != NULL) 
					cout << x->pw_name << " ";
				else {
					cerr << "error: " << errno << endl;
					exit(0);
				}

				if ((y = getgrgid(current.st_gid)) != NULL)
					cout << y->gr_name << " ";
				else {
					cerr << "error: " << errno << endl;
					exit(0);	
				}
				cout << current.st_size << " ";
				
				char buff[20];
				struct tm * timeinfo;
				timeinfo = localtime(&(current.st_mtime));
				strftime(buff, 20, "%b %d %H:%M", timeinfo);
				printf("%s",buff);
				
				cout << " " << directoryName << endl;
}
int lsWithFlags(char* directoryName, vector<string> flags) {
	if (!isDirectory(directoryName)) {
	
		bool isA = false;
		bool isL = false;
		bool isR = false;
		for (unsigned i = 0; i < flags.size(); ++i) {
			for (unsigned k = 0; k < flags.at(i).size(); ++k) {
				if (flags.at(i).at(k) == 'a') 
					isA = true; // there's an -a flag
				else if (flags.at(i).at(k) == 'l') 
					isL = true; // there's an -l flag
				else if (flags.at(i).at(k) == 'R')
					isR = true; // there's an -R flag
			}

		}	
		if (isL) {
			printDashL(directoryName, flags);	
		}
		else {
			cout << directoryName << endl;
		}
		return 1;
		
	}


	char const *dirName = directoryName;
	DIR *dirp;
	if (!(dirp = opendir(dirName))) {
		cerr << "Error(" << errno << ") opening " << dirName << endl;
		return errno;
	}
	
	bool isA = false;
	bool isL = false;
	bool isR = false;
	for (unsigned i = 0; i < flags.size(); ++i) {
		for (unsigned k = 0; k < flags.at(i).size(); ++k) {
			if (flags.at(i).at(k) == 'a') 
				isA = true; // there's an -a flag
			else if (flags.at(i).at(k) == 'l') 
				isL = true; // there's an -l flag
			else if (flags.at(i).at(k) == 'R')
				isR = true; // there's an -R flag
		}

	}


	dirent *direntp;

	if (isR && isDirectory(directoryName)) {
		vector<char*> dirsInCurdir;
		int i = 0;
		while ((direntp = readdir(dirp))) {
			string test = direntp->d_name;			
			if (test == "." || test == "..")
				continue;
			string path = directoryName;
			path.append("/");
			path.append(direntp->d_name);
			char *x;
			x = new char[path.size() + 1];
			strcpy(x, path.c_str());
			dirsInCurdir.push_back(x);
			++i;
		} 
		
		for (int j = 0; j < i; ++i) {
			cout << dirsInCurdir[j] << ":\n\t";
			return lsWithFlags(dirsInCurdir[j], flags);
			cout << endl;
		}
		for (int j = 0; j < i; ++j)
			delete [] dirsInCurdir[j];
	}

	if (!isL && !isA)
		return ls(directoryName);
		
	if (isL) { //run -l flag
	
		struct stat current;

		struct passwd *x;
		struct group *y;
		while ((direntp = readdir(dirp))) {
			string temp = directoryName;
			temp.append("/");
			temp.append(direntp->d_name);
			//cout << "direntp: " << direntp->d_name << endl;
			char* curdir = new char[temp.size() + 1];
			strcpy(curdir, temp.c_str());
			
			//cout << curdir << endl;
			if (-1 == (stat(curdir, &current))) {
		
				perror("stat failed");
				return -1;
			}
			if (direntp->d_name[0] == '.' && !isA)	{ // if there's no -a flag, don't print files 
															   // starting with .
				continue; 
			}
			else {
			
				if (current.st_mode & S_IFDIR) 
					cout << "d";
				
				if (current.st_mode & S_IFLNK)
					cout << "l";
				
				if (!(current.st_mode & S_IFDIR) && !(current.st_mode & S_IFLNK))
					cout << "-";

				if (current.st_mode & S_IRUSR)
					cout << "r";
				else
					cout << "-";

				if (current.st_mode & S_IWUSR)
					cout << "w";
				else
					cout << "-";
				
				if (current.st_mode & S_IXUSR)
					cout << "x";
				else
					cout << "-";

				if (current.st_mode & S_IRGRP)
					cout << "r";
				else
					cout << "-";

				if (current.st_mode & S_IWGRP)
					cout << "w";
				else
					cout << "-";

				if (current.st_mode & S_IXGRP)
					cout << "x";
				else
					cout << "-";

				if (current.st_mode & S_IROTH)
					cout << "r";
				else
					cout << "-";

				if (current.st_mode & S_IWOTH)
					cout << "w";
				else
					cout << "-";

				if (current.st_mode & S_IXOTH)
					cout << "x";
				else
					cout << "-";

				cout << " ";

				cout << current.st_nlink << " ";

				if ((x = getpwuid(current.st_uid)) != NULL) 
					cout << x->pw_name << " ";
				else {
					cerr << "error: " << errno << endl;
					exit(0);
				}

				if ((y = getgrgid(current.st_gid)) != NULL)
					cout << y->gr_name << " ";
				else {
					cerr << "error: " << errno << endl;
					exit(0);	
				}
				cout << current.st_size << " ";
				
				char buff[20];
				struct tm * timeinfo;
				timeinfo = localtime(&(current.st_mtime));
				strftime(buff, 20, "%b %d %H:%M", timeinfo);
				printf("%s",buff);
				
				cout << " " << direntp->d_name;
			}
			cout << endl;
			delete [] curdir;
				
		}
		closedir(dirp);
		
	}

	else if (isA) {
		while ((direntp = readdir(dirp))) {
	
					
			//cout << direntp->d_name << endl; // use stat here to find attributes of a file
			printf(direntp->d_name, 8);
			cout << " ";

		}
		if (-1 == (closedir(dirp))) {
			perror("closedir failed");
		}
		cout << endl;
	}
	return 0;
}

int main(int argc, char* argv[]) {
	
	if (argc == 1) {
		
		if (errno == ls(".")) {
		
			return errno;
		}
	}	
	
	else {
		
		vector<string> directories;
		vector<string> flags;
		string toInsert = "./";
		for (int i = 1; i < argc; ++i) {
			
			if (argv[i][0] == '-') {
				
				flags.push_back(argv[i]);
			} else {
			
				directories.push_back(argv[i]);
			}
		}

		for (unsigned i = 0; i < directories.size(); ++i) {
		
			directories.at(i).insert(0, toInsert);
		}
		if (flags.size() == 0) {
					
			for (unsigned i = 0; i < directories.size(); ++i) {
			
				char* directoryName = new char[directories.at(i).size() + 1];
				strcpy(directoryName, directories.at(i).c_str());
				
				ls(directoryName);
				
				delete [] directoryName;
			}
		}
		else if (directories.size() == 0) {
		
			lsWithFlags(".", flags);
		}
		else {
			//cout << "directories: ";
			//for (unsigned i = 0; i < directories.size(); ++i) 
				//cout << directories.at(i) << " ";
			//cout << endl;

			if (directories.size() == 1) {
				
				char* directoryName = new char[directories.at(0).size() + 1];
				strcpy(directoryName, directories.at(0).c_str());
				
				lsWithFlags(directoryName, flags);
				
				delete [] directoryName;
			}

			else {
				for (unsigned int i = 0; i < directories.size(); ++i) {
					//cout << 145 << endl;
				
					char* directoryName = new char[directories.at(i).size() + 1];
					strcpy(directoryName, directories.at(i).c_str());
					cout << directoryName << ":" << endl;	
					lsWithFlags(directoryName, flags);	
					delete [] directoryName;
					cout << endl;
				}
			}
		}
	}
	

}

