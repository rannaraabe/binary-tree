/**
 * @file main.cpp
 * @author Ranna Raabe e Frankleiton Levy
 */ 

#include <iostream>
#include <fstream>
#include "include/abb.h"

int main(){
    
    abb *arvore = new abb();    // Árvore
    int value;      // Valor que será lido

    ifstream arq;
    arq.open("../data/arvore.txt");

    if(!arq)
    {
        cerr << "Não foi possivel abrir o arquivo";
        exit(1);
    } else {
        while (arq >> value) {

        }
    }
    arq.close();

    return 0;
}