#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

using Graph = map<string, vector<string>>;
using st_poti = map<string, long long>; 

long long DFS_DP(
    const string& trenutni, 
    const string& cilj,
    const Graph& graf,
    st_poti& memory
) {
    if (memory.count(trenutni)) {
        return memory.at(trenutni);
    }

    if (trenutni == cilj) {
        return 1;
    }
    
    if (graf.find(trenutni) == graf.end()) {
        return 0;
    }
    
    long long st_poti = 0;
    
    for (const string& sosed : graf.at(trenutni)) {
        st_poti += DFS_DP(sosed, cilj, graf, memory);
    }
    
    memory[trenutni] = st_poti;
    
    return st_poti;
}

int main(){

    string n;
    string kljuc;
    string povezave_s;
    vector<string> povezave;
    string sosed;
    
    Graph graf;
    st_poti memory;

    ifstream input("seznam.txt");

    while(getline(input, n)){
        povezave.clear();

        size_t dvopicje = n.find(":");

        kljuc = n.substr(0, dvopicje);
        povezave_s = n.substr(dvopicje + 2);

        stringstream ss(povezave_s);

        while(ss >> sosed){
            povezave.push_back(sosed);
        }

        graf[kljuc] = povezave;
    }
    input.close();

    //1: svr -> dac -> fft -> out
    memory.clear();
    long long svr_dac = DFS_DP("svr", "dac", graf, memory);
    
    memory.clear();
    long long dac_fft = DFS_DP("dac", "fft", graf, memory);
    
    memory.clear();
    long long fft_out = DFS_DP("fft", "out", graf, memory);
    
    long long N1 = svr_dac * dac_fft * fft_out;

    // 2: svr -> fft -> dac -> out
    memory.clear();
    long long svr_fft = DFS_DP("svr", "fft", graf, memory);
    
    memory.clear();
    long long fft_dac = DFS_DP("fft", "dac", graf, memory);
    
    memory.clear();
    long long dac_out = DFS_DP("dac", "out", graf, memory);
    
    long long N2 = svr_fft * fft_dac * dac_out;
    
    long long skupno = N1 + N2;

    cout << skupno << endl;

    return 0;
}