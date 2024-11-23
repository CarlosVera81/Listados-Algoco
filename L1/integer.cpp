#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
const ll inf = 1e12;
const ld pi = acos(-1);

vector<string> splitString(const string& str, char delimiter) {
    vector<string> tokens;
    istringstream stream(str);
    string token;
    while (getline(stream, token, delimiter)) {
        tokens.push_back(token); 
    }
    return tokens;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(9);

    int n;
    cin >> n;
    for(int k=0;k<n;k++){

        string op;
        int largo;
        string input;
        vector<string> lista1;
        cin >> op >> largo >> input;
        
        if(largo!=0){
            list<int> lista;
            string num;
            for (char c : input) {
                if (isdigit(c)) {
                    num += c;  
                } else if (!num.empty()) {
                    lista.push_back(stoi(num));  
                    num.clear();
                }
            }
            int flag=0;
            int reversa=0;
            for(int i=0;i<int(op.length());i++){
                if(op[i]=='R' and !lista.empty()){
                    if(reversa==0){
                        reversa=1;
                    } else if(reversa==1){
                        reversa=0;
                    }
                }
                else{
                    if(lista.empty()){
                        cout << "error" << endl;
                        flag=1;
                        break;
                    }
                    else {
                        if(reversa==1){
                            lista.pop_back();
                        } else {
                            lista.pop_front();
                        }
                        
                    }
                }
            }
            if(lista.empty() and flag==0){
                cout << "[]" << endl;
            }else {
                if(!lista.empty()){
                    cout << "[";
                    int aa=0;
                    if(reversa==1){
                        reverse(lista.begin(),lista.end());
                    }
                    for(auto i:lista){
                        if(aa==int(lista.size())-1){
                            cout << i;
                        } else {
                            cout << i << ',';
                            aa++;
                        }
                    }
                    cout << "]" << endl;
                }
            }
        }
        else {
            int flag=0;
            for(int i=0;i<int(op.length());i++){
                if(op[i]=='D'){
                    flag=1;
                    break;
                }
            }
            if (flag==0){
                cout <<"[]" << endl;
            } else {
                cout << "error"<< endl;
            }

        }
    }
    return 0;

    // Complejidad temporal: O(n*(m+k)), donde m es la longitud de 
    //las operaciones y k el tramaño maximo de la lista inicial;
    // Complejidad Espacial O(k), por caso de prueba, donde
    // k es el tamaño de la lista en peor caso.


}



   
