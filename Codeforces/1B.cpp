#include <bits/stdc++.h>

using namespace std;

string toSpreadsheet (string s){
    int row, col;
    stringstream ss(s);
    ss.ignore(1);
    ss >> row;
    ss.ignore(1);
    ss >> col;
    string result;
    while (col > 0) {
        col--;
        char letter = 'A' + col%26;
        result += letter;
        col /= 26;
    }
    reverse (result.begin(), result.end());
    return result + to_string (row);
}

string toRxCy (string s){
    int row;
    string column;
    int i = 0; 
    while ((int) s[i] >= 65) column += s[i++]; 
    stringstream ss (s.substr(i));
    ss >> row; 
    int columnNumber = 0;
    for (char c: column) columnNumber = columnNumber * 26 + (c - 'A' + 1);
    return "R" + to_string(row) + "C" + to_string(columnNumber);
}

bool isRxCy (string s){
    bool hasC = false;
    for (char c: s) if (c == 'C') hasC = true;
    return (s[0] == 'R' && (int) s[1] < 65 && hasC); 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (isRxCy(s)) cout << toSpreadsheet(s) << "\n";
        else cout << toRxCy (s) << "\n"; 
    }
}
