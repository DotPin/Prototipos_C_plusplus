#include <cstdlib>  
#include <stdlib.h>     /* srand, rand */
#include "Aleatorio.h"
#include <iostream>
#include <time.h>       /*permite ocupar otro tiempo para la memoria */
#include <list>

using namespace std;


//Ejercicio:
//Dada una lista1 enlazada donde genera "n" elementos, mediante una funcion aleatoria
//recorrer la lista enlazada y aleatoriamente seleccionar elementos a una lista2.

int main(int argc, char *argv[]){

    list<int> lista1,lista2,aux;
    list<int>::iterator it;

    //en caso de usar alguna semilla cambiar el time(NULL) por algún valor
    Aleatorio *rnd = new Aleatorio(time(NULL));

    for(int i=0;i<10;i++){
        lista1.push_back(i);
    }
    for(int i=12;i<20;i++){
        lista2.push_back(i*2);        
    }
    cout<<"\nLista inicial 1: ";
    for(it=lista1.begin();it!=lista1.end();++it){
        cout<<" "<<*it;
    }

    cout<<"\nLista inicial 2: ";
    for(it=lista2.begin();it!=lista2.end();++it){
        cout<<" "<<*it;
    }

    //restaurador de lista enlazada
    aux = lista1;


    for(short j=0;j<lista1.size();j++){
        for(it=lista1.begin();it!=lista1.end();it++){

            if(*it> rnd->int_uniform(0,10)) ){
                //lista1.splice(it,lista2);

                //obtiene nodo buscado y lo enlaza en lista2, destruyendo la lista1
                lista2.splice(lista2.end(),lista1,it);

                //restauro lista1 para continuar con los parámetros del for
                lista1 = aux;

                break;

            }

        }
    }

    cout<<"\n Lista final 1: ";
    for(it=lista1.begin();it!=lista1.end();++it){
        cout<<" "<<*it;
    }
    cout<<"\n";

    cout<<"\n Lista final 2: ";
    for(it=lista2.begin();it!=lista2.end();++it){
        cout<<" "<<*it;
    }
    cout<<"\n";

    cout<<"\nexit";

    return 0;
}