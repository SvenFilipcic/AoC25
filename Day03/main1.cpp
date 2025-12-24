#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int največja_st(string& vrstica){
        int max_vrednost = 0;
        int max_joltage = 0;

        for(int i = 0; i < vrstica.lenght() - 1; ++i){
            char x_c = vrstica[i];

            int x = x_c - '0';

            for(int j = i + 1; j < vrstica.length(); ++j){
                char y_c = vrstica[j];
                int y = y_c - '0';

                int joltage = 10 * (int)x + y;
                
                if(joltage > max_joltage){
                    max_joltage = joltage;
                }

            }

        }
        return max_joltage;
}

int main(){

   string line;
   int skupno = 0;
   string seznam = "seznam.txt";

   ifstream input(seznam);

   while(getline(input, line)){

    int najvecja = največja_st(line);

    skupno += najvecja;
   }

   input.close();

   cout << skupno;

    return 0;
}


