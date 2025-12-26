#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

const vector<pair<int, int>> sosedi = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1},  {1, 0},  {1, 1}
};

int main() {
    ifstream file("input.txt");

    vector<string> grid;
    string line;

    while (getline(file, line)) {
        grid.push_back(line);
    }

    int odstranjeni = 0;
    bool odstranitev = true;


    while (odstranitev) {
        
        odstranitev = false;
        vector<pair<int, int>> za_odstrant;

        for (int i = 0; i < grid.size(); ++i) { 
        for (int j = 0; j < grid[0].size(); ++j) { 
            
            if (grid[i][j] == '@') {
                int sosednja_rollica = 0;
                
                for (const auto& offset : sosedi) {
                    int ni = i + offset.first;
                    int nj = j + offset.second;

                    if (ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size()) {
                        if (grid[ni][nj] == '@') {
                            sosednja_rollica++;
                        }
                    }
                }

                    if (sosednja_rollica < 4) {
                        za_odstrant.push_back({i, j});
                    }
                }
            }
        }

        if (!za_odstrant.empty()) {
            odstranitev = true;
            odstranjeni += za_odstrant.size();
            for (auto& p : za_odstrant) {
                grid[p.first][p.second] = '.'; 
            }
        }
    }

    cout << odstranjeni << endl;

    return 0;
}