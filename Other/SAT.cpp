#include <bits/stdc++.h>

using namespace std;

int n;
map <int, bool> assignment;
vector <vector<int>> formula;

bool SATclause (vector <int> literals){
    for (int literal: literals){
        int var = abs (literal);
        bool value = (literal > 0);
        if (assignment.at (var) == value) return true;
    }
    return false;
}

bool SATformula (){
    if (assignment.size() != n) return false;
    for (auto clause: formula){
        if (!SATclause(clause)) return false;
    }
    return true;
}

int getNext(){
    for (int var = 1; var <= n; var++) if (!assignment.count(var)) return var;
    return -1;
}

bool SAT (){
    if (SATformula()) return true; 
    int var = getNext(); 
    if (var == -1) return false;

    assignment[var] = true;
    if (SAT()) return true; 
    assignment.erase(var);

    assignment[var] = false;
    if (SAT()) return true;
    assignment.erase(var);

    return false; 
}

int main(){
    ifstream file ("SATinput.txt");
    string line;
    while (getline(file, line)){
        if (line.empty() || line[0] == 'c') continue;
        if (line[0] == 'p') {
            int m;
            sscanf(line.c_str(), "p cnf%d%d", &n, &m);
        } 
        else {
            vector<int> literals;
            int literal;
            stringstream ss (line);
            while (ss >> literal && literal != 0) literals.push_back(literal);
            formula.push_back(literals);
        }
    }
    file.close();

    ofstream outputFile ("SAToutput.txt"); 
    if (SAT()){
        for (auto i: assignment) outputFile << i.first << ": " << (i.second ? "T" : "F") << "\n";
    }
    else outputFile << "Not satisfiable\n";
    outputFile.close();
}