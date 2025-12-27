#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

struct Tocka {
    int x, y;
};

int main() {
    ifstream file("input.txt");

    vector<Tocka> kvadrat;
    int x, y;
    char c; // vejica

    while (file >> x >> c >> y) {
        kvadrat.push_back({x, y});
    }

    long long max = 0;
    // brute force vseh kvadratov
    for (int i = 0; i < kvadrat.size(); i++) {
        for (int j = i + 1; j < kvadrat.size(); j++) {
            
            long long sirina = abs(kvadrat[i].x - kvadrat[j].x) + 1;
            long long visina = abs(kvadrat[i].y - kvadrat[j].y) + 1;
            
            long long trenutna = sirina * visina;

            if (trenutna > max) {
                max = trenutna;
            }
        }
    }

    cout  << max;

    return 0;
}