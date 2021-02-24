#include <iostream>
#include <direct.h>
#include <io.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct Team {
    string nametag;
    int points;
};

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

