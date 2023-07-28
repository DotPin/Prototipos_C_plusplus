#include <cstdlib>  
#include <iostream>
#include <time.h>       /*permite ocupar otro tiempo para la memoria */
#include <list>
#include "Aleatorio.h"
#include "prueba.h"

using namespace std;

//Genera una lista con 60 elementos iniciales, y realiza 60 veces un recorrido con selección aleatoria, 
//traspasando cada elemento seleccionado por criterio aleatorio a una segunda lista.

int main(int argc, char *argv[]){

    //en caso de usar alguna semilla cambiar el time(NULL) por algún valor
    Aleatorio *al = new Aleatorio(time(NULL));

    prueba variable;
    list<prueba> lista1, lista2,aux;
    list<prueba>::iterator it;

    for(short i=0;i<60;i++){
        variable.ingresa((char)al->int_uniform(0,50),al->int_uniform(0,50));
        lista1.push_back(variable);
    }

    aux = lista1;

    for(it=lista1.begin();it!=lista1.end();it++){
        cout<<"\n[C]: "<<it->name<<" [V]: "<<it->valor;
    }
    cout<<"\n";
    int rnd=0;
    for(short j=0;j<lista1.size();j++){
        for(it=lista1.begin();it!=lista1.end();it++){
            rnd = al->int_uniform(0,50);
            if(it->valor < rnd ){

                cout<<"\nValor: "<<it->valor<<" CMP:"<<rnd;

                //obtiene nodo buscado y lo enlaza en lista2, destruyendo la lista1
                lista2.splice(lista2.end(),lista1,it);

                break;

            }

        }

    }

    cout<<"\nSalida\n";
    cout<<"\nLista 1\n";
    for(it=lista1.begin();it!=lista1.end();it++){
        cout<<"\n[C]: "<<it->name<<" [V]: "<<it->valor;
    }
    cout<<"\n";

    cout<<"\nLista 2\n";
    for(it=lista2.begin();it!=lista2.end();it++){
        cout<<"\n[C]: "<<it->name<<" [V]: "<<it->valor;
    }
    cout<<"\n";


    
    return 0;
}
