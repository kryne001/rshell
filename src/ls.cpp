#include <iostream>
#include <vector>
#include <sstream>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
using namespace std;

int main() {
	
	char host[128];
	gethostname(host, sizeof host);
	string commandInput;

	cout << getlogin() << "@" << host << "$ ";
	cin >> commandInput;
	cout << endl;

	istringstream commandStream(commandInput);
	string currentCommand;
	vector<string> flags;
	vector<string> directories;

	unsigned i;
	while (commandStream >> currentCommand) {
		if (currentCommand.at(0) == '-') {

			flags.push_back(currentCommand);		
		}
		else if (currentCommand != "ls") {
			directories.push_back(currentCommand);
		}
	}
	
	if (directories.size() > 0) {
		char* commandLine = new char[(commandline.size() + 1) * sizeof(char*)];
		strcpy(commandLine, commandInput);

		char const *dirName = ;
		DIR *dirp;
		if (!(dirp = opendir(dirName))) {
			cerr << "Error(" << errno << ") opening " << dirName << endl;
			return errno;
		}

		dirent *direntp;
		while ((direntp = readdir(dirp)))
			cout << direntp->d_name << endl; // use stat here to find attributes of a file
	
		closedir(dirp);
	}
}


