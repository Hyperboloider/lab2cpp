#include "func.h"

int main(int argc, char *argv[]) {
    string dir_name = get_directory_name(),
    path = get_current_dir() + "\\" + dir_name + "\\*.csv";
    vector <string> csvs = get_csv_names(path);
    return 0;
}