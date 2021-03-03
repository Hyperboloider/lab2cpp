#include "func.cpp"


int main(int argc, char* argv[]) {
    string dir_name = get_directory_name(),
        path = get_current_dir() + "\\" + dir_name + "\\*.csv";
    vector<string> csvs = get_csv_names(path);
    path = get_current_dir() + "\\" + dir_name;
    vector<Team> teams_table = parse_csv_files(path, csvs);
    sort_team_list(teams_table);
    record_file(teams_table, "csvs");
    return 0;
}