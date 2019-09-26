#include <iostream>
#include <fstream>
#include "../include/abb.h"

using namespace std;

int main(){

    abb *arvore = new abb();

    int x;
    ifstream inFile;
    inFile.open("../data/arvore.txt");

    if(!inFile)
    {
        cerr << "Não foi possivel abrir o arquivo";
        exit(1);
    }

    while (inFile >> x) {
        arvore->inserir(x);
    }

    inFile.close();

    return 0;
}