#include "func.h"
#include <string>
#include <iostream>


int main(int argc, char *argv[]) {
    string dir_name = get_directory_name(),
    path = get_current_dir() + "\\" + dir_name + "\\*.csv";
    return 0;
}
