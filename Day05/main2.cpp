#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm> 

using namespace std;

int main() {
    ifstream file("input.txt");
    string line;
    vector<pair<long long, long long>> vsi_razponi;

    while (getline(file, line) && !line.empty() && line != "\r") {
        stringstream ss(line);
        long long spodnja, zgornja;
        char crtica;
        if (ss >> spodnja >> crtica >> zgornja) {
            vsi_razponi.push_back({spodnja, zgornja});
        }
    }

    sort(vsi_razponi.begin(), vsi_razponi.end());

    long long skupno = 0;

    long long start = vsi_razponi[0].first;
    long long end = vsi_razponi[0].second;

    for (size_t i = 1; i < vsi_razponi.size(); i++) {
        if (vsi_razponi[i].first <= end + 1) { 
                end = max(end, vsi_razponi[i].second);
            } else {
                skupno += (end - startz + 1);
                startz = vsi_razponi[i].first;
                end = vsi_razponi[i].second;
        }
    }
    skupno += (end - startz + 1); 

    cout << skupno << endl;
    return 0;
}