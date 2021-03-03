#include <string>
#include <vector>
#include <iostream>


using namespace std;

struct Team {
    string nametag;
    int points;
};

string get_directory_name();
string get_current_dir();
vector<string> get_csv_names(string&);
vector<string> parse_line(string);
Team process_games(vector<string>);
void record_file(vector<Team>, string);
vector<Team> parse_csv_files(string, vector<string>);
void sort_team_list(vector<Team>&);