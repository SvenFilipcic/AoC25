#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool Neveljaven(long long n) {
    string s = to_string(n);
    int len = s.length();
    if (len % 2 != 0){
        return false;
    } 
    return s.substr(0, len / 2) == s.substr(len / 2);
}

int main() {
    ifstream file("dejanski.txt");
    string line;
    getline(file, line); 

    stringstream ss(line);
    string vrednost;
    long long skupno = 0;

    
    while (getline(ss, vrednost, ',')) { // "," getline loči po vejici
        size_t vezaj = vrednost.find('-');

        long long prva = stoll(vrednost.substr(0, vezaj));
        long long druga = stoll(vrednost.substr(vezaj + 1));

        for (long long i = prva; i <= druga; i++) {
            if (Neveljaven(i)) {
                skupno += i;
            }
        }
    }


    cout << skupno << endl;

    return 0;
}