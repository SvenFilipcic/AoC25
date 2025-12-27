#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool Neveljaven(long long n) {

    string s = to_string(n);
    int dolzina = s.length();

    for (int L = 1; L <= dolzina / 2; ++L) {
        if (dolzina % L == 0) {
            string vzorec = s.substr(0, L);
            string sestavljen = "";
            
            for (int j = 0; j < dolzina / L; ++j) { //sestavi vzorec
                sestavljen += vzorec;
            }
            
            if (sestavljen == s) return true;
        }
    }
    return false;
}

int main() {
    ifstream file("dejanski.txt");
    string line;
    getline(file, line); 

    stringstream ss(line);
    string vrednost;
    long long skupno = 0;

    
    while (getline(ss, vrednost, ',')) { 
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