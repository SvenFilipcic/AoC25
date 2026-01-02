#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <algorithm>

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

    // inicializacija vektora povezav
    vector<int> sef(tocke.size());
    for (int i = 0; i < tocke.size(); i++) {
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

    sort(povezave.begin(), povezave.end(), [](Robovi a, Robovi b) {
        return a.dist < b.dist;
    });

    int st_vezij = tocke.size();
    long long rezultat = 0;

    // Kruskalov algoritem

    for (int i = 0; i < povezave.size(); i++) {
        int koren_u = najdi(sef, povezave[i].u);
        int koren_v = najdi(sef, povezave[i].v);

        if (koren_u != koren_v) {
            sef[koren_u] = koren_v; 
            st_vezij--;

            if (st_vezij == 1) {
                rezultat = (long long)tocke[povezave[i].u].x * tocke[povezave[i].v].x;
                break;
            }
        }
    }

    cout << << rezultat << endl;

    return 0;
}