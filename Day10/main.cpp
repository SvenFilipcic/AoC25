#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

int pritiski(string vrstica) {

    int start = vrstica.find('[') + 1;
    int konec = vrstica.find(']');
    string konfig_str = vrstica.substr(start, konec - start);
    
    //vektor želenih stanj lučk
    vector<int> konfig;

    for (int i = 0; i < konfig_str.length(); ++i) {
        if (konfig_str[i] == '#') {
            konfig.push_back(1); 
        }
        else{
            konfig.push_back(0);
        }
    }

    vector<vector<int>> vsi_gumbi;
    
    size_t oklepaj = 0;
    
    while ((oklepaj = vrstica.find('(', oklepaj)) != string::npos) {

        size_t zaklepaj = vrstica.find(')', oklepaj);
        string gumbi = vrstica.substr(oklepaj + 1, zaklepaj - oklepaj - 1);
    
    
        vector<int> trenutni_gumb;
        stringstream ss(gumbi);
        string stevilo_gumba;
    
        while (getline(ss, stevilo_gumba, ',')) {
            int stevilka = stoi(stevilo_gumba);
            trenutni_gumb.push_back(stevilka);
        }
    
        vsi_gumbi.push_back(trenutni_gumb);
    
        oklepaj = zaklepaj;
    }

    //BFS
    queue<vector<int>> stanje_que;
    queue<int> vrsta_que;
    set<vector<int>> obdelani;

    vector<int> trenutno_stanje(konfig.size(), 0); 
    stanje_que.push(trenutno_stanje);
    vrsta_que.push(0);
    obdelani.insert(trenutno_stanje);

    while (!stanje_que.empty()) {
    
        vector<int> trenutno = stanje_que.front();
        int koraki = vrsta_que.front();
    

        stanje_que.pop();
        vrsta_que.pop();

        if (trenutno == konfig) {
            return koraki;
        }

        for (int g = 0; g < vsi_gumbi.size(); g++) {
            vector<int> gumb = vsi_gumbi[g];
            vector<int> novo_stanje = trenutno;

            for (int i = 0; i < gumb.size(); i++) {
                int i_lucke = gumb[i];
            
                if (novo_stanje[i_lucke] == 0) {
                    novo_stanje[i_lucke] = 1;
                } else {
                   novo_stanje[i_lucke] = 0;
                }
            }

 
            if (obdelani.count(novo_stanje) == 0) {
                obdelani.insert(novo_stanje);
                stanje_que.push(novo_stanje);
                vrsta_que.push(koraki + 1);
            }
        }
    }
    return 0;
}

int main() {
    ifstream datoteka("input.txt");

    string vrstica;
    int skupno = 0;

    while (getline(datoteka, vrstica)){
        skupno += pritiski(vrstica);
    }

    cout << skupno << endl;

    return 0;
}