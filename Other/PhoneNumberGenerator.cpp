#include <bits/stdc++.h>

using namespace std;

int main(){
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution <int> distribution(1000000, 9999999);

    unordered_set <int> numbers;
    while (numbers.size() < 375001){
        int num = distribution (generator);
        numbers.insert(num);
    }

    ofstream outputFile("PhoneNumberInput.txt");
    for (const auto& num : numbers){
        outputFile << num << "\n";
    }
    return 0;
}
