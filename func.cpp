#include "func.h"
#include <iostream>
#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;



string get_directory_name() {
    string name;
    cout << "Insert the directory name: ";
    cin >> name;
    return name;
}

string get_current_dir() {
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}

vector<string> get_csv_names(string path) {
    vector <string> csvs;
    _finddata_t files;
    intptr_t process = _findfirst(path.c_str(), &files);
    do {
        csvs.push_back(files.name);
    } while (_findnext(process, &files) == 0);
    _findclose(process);
    return csvs;
}

void output_vector(vector<string> vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << endl;
    }
}


vector<string> parse_line(string line) {
    vector<string> games;
    string game = "";
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != ',' && line[i] != ';') {
            game += line[i];
        }
        else {
            games.push_back(game);
            game = "";
        }
    }
    if (game != "") {
        games.push_back(game);
    }
    return games;
}

Team process_games(vector<string> games) {
    Team current_team;
    current_team.nametag = games[0];
    int points_total = 0;
    for (int i = 1; i < games.size(); i++) {
        string game = games[i];
        int points_team = stoi(game.substr(0, game.find(":")));
        int points_enemy = stoi(game.substr(game.find(":") + 1, string::npos));
        if (points_team > points_enemy) {
            points_total += 3;
        }
        else if (points_team == points_enemy) {
            points_total++;
        }
    }
    current_team.points = points_total;
    return current_team;
}

void record_file(vector<Team> teams_table, string dir_name) {
    string path = get_current_dir() + "\\" + dir_name + "\\results.csv";
    ofstream results(path, ios::trunc);
    for (int i = 0; i < teams_table.size(); i++) {
        results << teams_table[i].nametag << "," << teams_table[i].points << "\n";
    }
    results.close();
}

vector<Team> parse_csv_files(string path, vector<string> csvs) {
    string line;
    vector<Team> parsed_team_lines;

    for (int i = 0; i < csvs.size(); i++) {
        ifstream in(path + "\\" + csvs[i]);
        if (in.is_open()) {
            int number_of_lines;
            in >> number_of_lines;
            string tmp;
            getline(in, tmp);

            for (int j = 0; j < number_of_lines; j++) {
                string raw_line;
                getline(in, raw_line);
                vector<string> parsed_line = parse_line(raw_line);
                parsed_team_lines.push_back(process_games(parsed_line));
            }
        }
        else {
            cout << "not open" << endl;
        }
        in.close();
    }
    return parsed_team_lines;
}

void sort_team_list(vector<Team>& teams) {
    Team temp;
    for (int i = 0; i < teams.size() - 1; i++)
        for (int j = 0; j < teams.size() - 1 - i; j++) {
            if (teams[j].points < teams[j + 1].points) {
                temp = teams[j + 1];
                teams[j + 1] = teams[j];
                teams[j] = temp;
            }
        }
}