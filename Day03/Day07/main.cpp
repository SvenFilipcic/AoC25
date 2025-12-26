#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    ifstream file("input.txt");
    vector<string> line;
    string n;
    while (getline(file, n)) line.push_back(n);

    int start;
    for (int j = 0; j < line[0].size(); j++){
        if (line[0][j] == 'S') start = j;
    } 

    vector<pair<int, int>> queue;
    queue.push_back({0, start});
    
    vector<pair<int, int>> splits; //split "^"

    for (int i = 0; i < queue.size(); i++) {
        int row = queue[i].first; //trenutna vrstica
        int column = queue[i].second; //trenutni stolpec

        for (int vrstica = row + 1; vrstica < line.size(); vrstica++) {
            if (line[vrstica][column] == '^') {
                
                //ce ze obstaja split
                bool ze_obstaja = false;
                for (auto p : splits){
                    if (p.first == vrstica && p.second == column){
                        ze_obstaja = true;
                    }
                }

                if (!ze_obstaja) {
                    splits.push_back({vrstica, column});
                    //nova žarka
                    queue.push_back({vrstica, column - 1}); 
                    queue.push_back({vrstica, column + 1});
                }
                break; 
            }
        }
    }

    cout << splits.size() << endl;
    return 0;
}