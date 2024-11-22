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

    int t;
    cin >> t;

    while(t--){

        string cadena;
        cin >> cadena;
        int q;
        cin >> q;

        for(int i=0;i<q;i++){
            int y;
            char v;
            cin >> y >> v;
            string salida="NO";
            if(int(cadena.size())>=4){
                cadena[y-1]=v;

                for(auto a: cadena){
                    cout << a << " ";
                }
                
                int it=0;
                while(it<int(cadena.size())){
                    if(cadena[it]=='1'){
                        if(cadena[it+1]=='1'){
                            if(cadena[it+2]=='0'){
                                if(cadena[it+3]=='0'){
                                    salida="YES";
                                    break;
                                }else{
                                    it+=3;
                                }
                            }else{
                                it+=2;
                            }
                        } else {
                            it++;
                        }
                    } else {
                        it++;
                    }

                }
            }
            
            cout << salida << endl;

          //  cout << y << " " << v << endl;

        }

        
    }



    return 0;
}