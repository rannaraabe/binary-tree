/**
 * @file main.cpp
 * @author Ranna Raabe e Frankleiton Levy
 */ 

#include <iostream>
#include "abb.h"
using namespace std;


int main(){
    // TODO
    // ler os valores da arvore ok
    // ler os comandos para executar (dá p fazer um switch case, eh pratico)
    // identificar cada comando e executar
    
    abb arvore; // Objeto da arvore
    
    int no;
    cin >> no;  // Lendo o primeiro nó (nó raiz)
    arvore.insert(no);

    while(cin >> no){
        arvore.insert(no);  // Adicionando os demais nós na arvore
    }

    cout << "árvore lida: " << endl;
    arvore.print();

    arvore.insert(6);   // Novo valor
    arvore.insert(40);  // Valor repetido

    arvore.remove(40);  // Removendo uma folha
    arvore.insert(40);

    arvore.remove(25);  // Removendo um nó com uma subarvore vazia
    arvore.remove(15);  // Removendo uma arvore q possui duas subarvores

    cout << "árvore modificada: " << endl;
    arvore.print();

    cout << "" << endl;    
    return 0;
}