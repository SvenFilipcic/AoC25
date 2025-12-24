#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

struct Tocka {
    int x, y, z;
};

struct Robovi {
    int u, v;
    double dist;
};

int najdi(vector<int>& sef, int i) {
    if (sef[i] == i) return i;
    return sef[i] = najdi(sef, sef[i]);
}

int main() {
    ifstream filename("input.txt");
    vector<Tocka> tocke;
    vector<Robovi> povezave;

    int x, y, z;
    char c;

    // c == ","
    while (filename >> x >> c >> y >> c >> z) {
        tocke.push_back({x, y, z});
    }

    // vektor povezav
    vector<int> sef(tocke.size());
    for (int i = 0; i < tocke.size(); i++){
        sef[i] = i;
    }


    for (int i = 0; i < tocke.size(); i++) {
        for (int j = i + 1; j < tocke.size(); j++) {
            double dx = tocke[i].x - tocke[j].x;
            double dy = tocke[i].y - tocke[j].y;
            double dz = tocke[i].z - tocke[j].z;
            double d = sqrt(dx*dx + dy*dy + dz*dz);
            povezave.push_back({i, j, d});
        }
    }

    // sort razdalje
    sort(povezave.begin(), povezave.end(), [](Robovi a, Robovi b) {
        return a.dist < b.dist;
    });


    for (int i = 0; i < 1000; i++) {
        int koren_u = najdi(sef, povezave[i].u);
        int koren_v = najdi(sef, povezave[i].v);
        if (koren_u != koren_v) {
            sef[koren_u] = koren_v;
        }
    }
    
    vector<int> stevec(tocke.size(), 0);

    for (int i = 0; i < tocke.size(); i++){
    stevec[najdi(stars, i)]++;
    }
    
    sort(stevec.rbegin(), stevec.rend());
    
    cout << (long long)stevec[0] * stevec[1] * stevec[2];

    return 0;
}