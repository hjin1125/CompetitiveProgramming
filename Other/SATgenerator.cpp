#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 gen(rd());

int getRandom(int low, int high){
    if (low <= 0 && high >= 0){
        uniform_int_distribution<> dis(low, high-1);
        int num = dis(gen);
        return num >= 0 ? num + 1 : num;
    }
    uniform_int_distribution<> dis(low, high);
    return dis(gen);
}

int main(){
    ofstream file("SATinput.txt");
    int n = 30; // clauses
    int m = 30; // literals

    vector<vector<int>> formula;
    for (int i = 0; i < n; i++){
        int literals = getRandom(1, m);
        vector <int> clause;
        set <int> s; 
        for (int j = 0; j < literals; j++){
            int literal;
            do {
                literal = getRandom(-m, m);
            } 
            while (s.count(abs(literal)) > 0); 
            clause.push_back(literal);
            s.insert(abs(literal));
        }
        formula.push_back(clause);
    }

    file << "p cnf " << m << " " << n << "\n";
    for (auto clause: formula){
        for (int literal: clause){
            file << literal << " ";
        }
        file << "0\n";
    }
    file.close();
}
