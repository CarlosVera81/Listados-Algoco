#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int n,m,k;
    ll r=0;
    cin >> n >> m >> k;
    int entrada;

    priority_queue <int,vector<int>,greater<int>> q1;
    priority_queue <int,vector<int>,greater<int>> q2;
    priority_queue <int,vector<int>,greater<int>> q3;
    for(int i=0;i<n;i++){
        cin >> entrada;
        q1.push(entrada);
    }
    for(int i=0;i<m;i++){
        cin >> entrada;
        q2.push(entrada);
    }
    for(int i=0;i<k;i++){
        cin >> entrada;
        q3.push(entrada);
    }
    while(true){
        if (q1.empty()){
            break;
        }else{
            if (q1.top()>q2.top() && !q2.empty()){
                q1.pop();
                q2.pop();
                r++;
            } else if (q1.top()*sqrt(2) > (q3.top()) && !q3.empty()){
                q1.pop();
                q3.pop();
                r++;
            }
            else{
                q1.pop();
            }
        }
    }
    cout << r << endl;
    return 0;
    // O((n+m+k)log max(n,m,k))
    // O( n + m + k)
}

