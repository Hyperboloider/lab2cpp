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

vector<string> get_csv_names(string path) {
    vector <string> csvs;
    _finddata_t files;
    intptr_t process = _findfirst(path.c_str(), &files);
    do {
        csvs.push_back(files.name);
    }while(_findnext(process, &files) == 0);
    _findclose(process);
    return csvs;
}