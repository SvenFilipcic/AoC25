#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::ifstream file("input.txt");
    std::vector<std::vector<long long>> grid(4);
    std::vector<char> operatorji;
    
    std::string line;

    // stevke
    for (int i = 0; i < 4; ++i) {
        if (std::getline(file, line)) {
            std::stringstream ss(line);
            long long num;
            while (ss >> num) {
                grid[i].push_back(num);
            }
        }
    }

    // operatorji (5 vrstica)
    if (std::getline(file, line)) {
        std::stringstream ss(line);
        char op;
        while (ss >> op) {
            operatorji.push_back(op);
        }
    }

    long long skupno = 0;
    
    //stolpci iteracija
    for (int j = 0; j < operatorji.size(); ++j) {

        long long stolpec = grid[0][j];
        char op = operatorji[j];

        // poračun
        for (int i = 1; i < 4; ++i) {
            if (op == '+') stolpec += grid[i][j];
            else if (op == '*') stolpec *= grid[i][j];
        }
        
        skupno += stolpec;
    }

    std::cout << skupno;

    return 0;
}