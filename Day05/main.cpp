#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> 

using namespace std;

int main() {
    ifstream file("input.txt");

    string line;
    vector<pair<long long, long long>> vsi_razponi;
    vector<long long> sestavine;

    while (getline(file, line)){
        if (line.empty() || line == "\r") break;
        
        stringstream ss(line);
        long long spodnja, zgornja;
        char crtica;

        if (ss >> spodnja >> crtica >> zgornja) {
            vsi_razponi.push_back({spodnja, zgornja});
        }
    }


    long long n;
    while (file >> n) {
        sestavine.push_back(n);
    }


    int sveze = 0;
    
    for (long long j : sestavine) {
        for (auto& k : vsi_razponi) {
            if (j >= k.first && j <= k.second) {
                sveze++;
                break; //če najde 
            }
        }
    }

    cout << sveze << endl;

    return 0;
}