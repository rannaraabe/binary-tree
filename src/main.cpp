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

    // cout << arvore.nth_element(0)->chave << endl;   // 10
    // cout << arvore.nth_element(2)->chave << endl;
    // cout << arvore.nth_element(9)->chave << endl;

    arvore.insert(6);   // Novo valor
    arvore.insert(40);  // Valor repetido
    arvore.insert(4);

    arvore.remove(40);  // Removendo uma folha
    arvore.insert(40);

    arvore.remove(25);  // Removendo um nó com uma subarvore vazia
    arvore.remove(15);  // Removendo o nó raiz
    arvore.remove(10);  // Removendo um nó q possui duas subarvores

    cout << arvore.position(15) << endl;    // null
    cout << arvore.position(6) << endl;     // 1
    cout << arvore.position(20) << endl;    // 4
    cout << arvore.position(10) << endl;    // 2
    cout << arvore.position(12) << endl;    // 3
    cout << arvore.position(40) << endl;    // 5

    arvore.insert(15);

    cout << "-------" << endl;
    cout << arvore.position(15) << endl;    // 4
    cout << arvore.position(10) << endl;    // 2
    cout << arvore.position(6) << endl;     // 1
    cout << arvore.position(12) << endl;    // 3
    cout << arvore.position(20) << endl;    // 5
    cout << arvore.position(40) << endl;    // 6


    cout << "" << endl;
    cout << "árvore final: " << endl;
    arvore.print();
    cout << "" << endl;    
    return 0;

}