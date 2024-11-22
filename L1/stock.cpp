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

    

    int n;
    cin >> n;
    
    for(int i=0;i<n;i++){
        
        int k;
        cin >> k;
        string linea;
        cin.ignore();
        int last=-1;
        map<int,int> venta;
        map<int,int,greater<int>> compra;
        for(int j=0;j<k;j++){
            
            getline(cin,linea);

            string num;

            if(linea[2]=='y'){
                vector<int> valores;
                for (char c : linea) {
                        if (isdigit(c)) {
                            num += c;  
                        } else if (!num.empty()) {
                            
                            valores.push_back(stoi(num));  
                            num.clear();
                        }
                }
                if (!num.empty()) {
                    valores.push_back(stoi(num));
                    num.clear();
                }
               // cout << valores[1] <<" "<<valores[0]<< endl;
                compra[valores[1]]+=valores[0];


            } else {
                vector<int> valores;
                for (char c : linea) {
                        if (isdigit(c)) {
                            num += c;  
                        } else if (!num.empty()) {
                            valores.push_back(stoi(num));  
                            num.clear();
                        }
                }
                if (!num.empty()) {
                    valores.push_back(stoi(num));
                    num.clear();
                }
               // cout << valores[1] <<" "<<valores[0]<< endl;
                venta[valores[1]]+=valores[0];
            }

            while (!compra.empty() && !venta.empty() &&
                   compra.begin()->first >= venta.begin()->first) {
                    int key1=compra.begin()->first;
                    int valor1=compra.begin()->second;
                    int key2=venta.begin()->first;
                    int valor2=venta.begin()->second;

                    if(valor1>valor2){
                        compra[key1]-=valor2;
                        venta.erase(key2);
                        last=key2;
                    } else if (valor1<valor2){
                        venta[key2]-=valor1;
                        compra.erase(key1);
                        last=key2;
                    } else {
                        venta.erase(key2);
                        compra.erase(key1);
                        last=key2;
                    }
            }
            

            string salida="";

            if(venta.empty()){
                salida+="- ";
            } else{
                salida+=to_string(venta.begin()->first);
                salida+=" ";
            }

            if(compra.empty()){
                salida+="- ";
            } else{
                salida+=to_string(compra.begin()->first);
                salida+=" ";
            }

            if(last==-1){
                salida+="-";
            } else {
                salida+=to_string(last);
            }
            cout << salida << endl;

        }


    }


    return 0;
}