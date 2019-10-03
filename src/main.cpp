/**
 * @file main.cpp
 * @author Ranna Raabe e Frankleiton Levy
 */ 

#include <iostream>
#include "abb.h"
using namespace std;

// g++ -std=c++11 -I include/ src/main.cpp -o out
// ./out < data/teste.txt

int main(){
    // TODO
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
    cout << "" << endl;
    cout << "" << endl;


    cout << arvore.nth_element(0)->chave << endl;   // 10
    cout << arvore.nth_element(2)->chave << endl;
    cout << arvore.nth_element(9)->chave << endl;

    arvore.insert(6);   // Novo valor
    arvore.insert(40);  // Valor repetido

    arvore.remove(40);  // Removendo uma folha
    arvore.insert(40);

    arvore.remove(25);  // Removendo um nó com uma subarvore vazia
    arvore.remove(15);  // Removendo uma arvore q possui duas subarvores

    cout << "" << endl;
    cout << "árvore final: " << endl;
    arvore.print();
    cout << "" << endl;    
    return 0;

}