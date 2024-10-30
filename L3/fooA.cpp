#include <bits/stdc++.h>

using namespace std;


string juego(string jugador, int tamano,vector<bool> primos){

    if (tamano==1 or tamano==2){
        return jugador;
    
    } else{

        for(int i=0;i<tamano;i++){
            if(primos[i]){
                int temp=tamano-i;
                for (int j=0;j<temp;j++){
                    if(primos[j]){
                        if(temp-j)
                    }

                }
            }

        }

    }

   
}


vector<bool> criba(int n){
    vector<bool> es_primo(n + 1, true);

    es_primo[0] = es_primo[1] = false;
    
    
    for (int i = 2; i * i <= n; ++i) {
        if (es_primo[i]) {
            for (int j = i * i; j <= n; j += i) {
                es_primo[j] = false;  
            }
        }
    }


    return es_primo;
}


int main(){

    int n;

    cin >> n;
    vector<int> tamanos(n);

    for(int i=0;i<n;i++){
        cin >> tamanos[i];
    }
    cout << endl;

    

    auto numero = max_element(tamanos.begin(),tamanos.end());

    auto primos=criba(*numero);


    for(int i=0;i<n;i++){
        cout << juego("Alice",tamanos[i],primos) <<endl;
    }

    return 0;
}