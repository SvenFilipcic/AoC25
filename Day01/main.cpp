#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;

    int polozaj = 50; 
    int skupno = 0;

    while (getline(file, line)) {
        char smer = line[0]; 
        int kolicina = stoi(line.substr(1));

        if (smer == 'R') {
            polozaj = (polozaj + kolicina) % 100; // %100 da negre nad 100
        } 
        else() {
            polozaj = (polozaj - kolicina) % 100;
            
            if (polozaj < 0) { // če gremo v minus
                polozaj += 100;
            }
        }

        if (polozaj == 0) {
            skupno++;
        }
    }

    cout << skupno << endl;

    return 0;
}