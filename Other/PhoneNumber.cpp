#include <bits/stdc++.h>

using namespace std;

bool numbers[10000000];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream inputFile("PhoneNumberInput.txt");
    int num;
    while (inputFile >> num) {
        numbers[num] = 1;
    }
    inputFile.close();
    
    ofstream outputFile("PhoneNumberOutput.txt");
    for (int i = 1000000; i <= 9999999; i++){
        if (numbers[i]){
            outputFile << i << "\n"; 
        }
    }
    outputFile.close();
}