#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("input.txt");

    string line;
    char smer;
    int kolicina;
    int polozaj = 50;
    long long skupno = 0; 

    while (getline(file, line)) {
        char smer = line[0]; 
        int kolicina = stoi(line.substr(1));
        // brute force (preveri vsak premik kota)
        for (int i = 0; i < kolicina; i++) { //korak po korak (iterira po 1)
            if (smer == 'R') {
                polozaj++;
                if (polozaj > 99) polozaj = 0; 
            } 
            else if (smer == 'L') {
                polozaj--;
                if (polozaj < 0) polozaj = 99; 
            }

            if (polozaj == 0) {
                skupno++;
            }
        }
    }

    cout << skupno << endl;

    return 0;
}