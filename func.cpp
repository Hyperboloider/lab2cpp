#include <iostream>
#include <direct.h>
#include <unistd.h>
#include <io.h>
#include <iostream>
#include <vector>

using namespace std;

string get_directory_name() {
    string name;
    cout << "Insert the directory name: ";
    cin >> name;
    return name;
}

string get_current_dir() {
   char buff[FILENAME_MAX];
   getcwd( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}