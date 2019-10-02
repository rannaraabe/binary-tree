/**
 * @file main.cpp
 * @author Ranna Raabe e Frankleiton Levy
 */ 

#include <iostream>
#include "abb.h"
using namespace std;


int main(){
    // TODO
    // ler os valores da arvore
    // ler os comandos para executar
    // identificar cada comando e executar

    abb *arvore = new abb;
    int n;
    cin >> n;

    while(cin >> n){
        cout << n;
    }

    return 0;
}