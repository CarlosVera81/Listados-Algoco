#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

int sum(list <int> a){
    int suma=0;
    for(auto it=a.begin();it!=a.end();it++){
        suma+=*it;
    }
    return suma;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int t;
    cin >> t;

    while(t--){
        int n,s;
        cin >> n >> s;
        list <int> lista;
        for(int i=0;i<n;i++){
            int valor;
            cin >> valor;
            lista.push_back(valor);
        }
        int suma=sum(lista);
        if(suma<s){
            cout << -1 << endl;
        } else {
            int contador=-1;
            if(suma==s){
                cout << 0 << endl;
            } else {
                while(!lista.empty()){
                    if(lista.front()==1 and lista.back()==1){
                        lista.pop_front();
                        contador++;
                        suma-=1;
                        if(suma==s){
                            break;
                        } else {
                            lista.pop_back();
                            contador++;
                            suma-=1;
                            if(suma==s){
                                break;
                            }
                        }
                    } else if (lista.front()==1 and lista.back()==0){
                        lista.pop_front();
                        contador++;
                        suma-=1;
                        if(suma==s){
                            break;
                        }
                    } else if (lista.front()==0 and lista.back()==1){
                        lista.pop_back();
                        contador++;
                        suma-=1;
                        if(suma==s){
                            break;
                        }
                    } else {
                        auto it1=find(lista.begin(),lista.end(),1);
                        auto it2=find(lista.rbegin(),lista.rend(),1);
                        int i1=0;
                        int i2=0;
                        i1=distance(lista.begin(),it1);
                        i2=distance(lista.begin(),it2.base())-1;

                        if(i1<i2){
                            while(i1--){
                            lista.pop_front();
                            contador++;
                            }
                            suma-=1;
                            if(suma==s){
                            break;
                            }
                        } else {
                            while(i2--){
                                lista.pop_back();
                                contador++;
                            }
                            suma-=1;
                            if(suma==s){
                            break;
                            }
                        }
                    }
    
                }
                if(lista.empty()){
                    cout << -1 << endl;
                } else {
                    cout << contador << endl;
                }
            }
    
            

        }
        



    }


    return 0;
}