#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

string največja_st(string& vrstica){
    string najvecja = "";
    int najvecja_trenutna = 0; 

    for (int k = 0; k < 12; ++k) {
        char best_digit = '0' - 1; 
        int najbolsi = najvecja_trenutna; 
        
        int limit = vrstica.length() - (12 - k); 

        for (int i = najvecja_trenutna; i <= limit; ++i) {
            
            if (vrstica[i] > best_digit) {
                best_digit = vrstica[i];
                najbolsi = i;
            }
        }
        
        if (best_digit >= '0') {
             najvecja += best_digit; 
        } else {
             return najvecja;
        }

        najvecja_trenutna = najbolsi + 1;
    }
    
    return najvecja;
}

int main(){

    string line;
    long long skupno = 0; 
    string seznam = "seznam.txt";

    ifstream input(seznam);

    while(getline(input, line)){
        
        string najvecja_string = največja_st(line); 
        
        long long najvecja_vrednost = stoll(najvecja_string); 
        
        skupno += najvecja_vrednost;    

    }

    input.close();

    cout << skupno << endl;

    return 0;
}
