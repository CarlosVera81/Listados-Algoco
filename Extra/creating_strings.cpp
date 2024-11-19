#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

string recursion(string actual,string restantes,int n){
    if(size(actual)==n){
        return actual;
    }

    actual+=restantes[0];
    auto resultado= recursion(actual,restantes.substr(1,size(restantes)),n);

    return resultado;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    string input;
    cin >> input;
    int contador=0;
    list <string> lista;

    int n=size(input)-1;

    if()
    cout << recursion()


    return 0;
}