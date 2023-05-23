#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m, a;
    cin >> n >> m >> a;
    ll x = (n-1)/a + 1;
    ll y = (m-1)/a + 1;
    cout << x*y << "\n";  
}