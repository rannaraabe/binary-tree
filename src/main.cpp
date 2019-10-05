/**
 * @file main.cpp
 * @author Ranna Raabe e Frankleiton Levy
 */ 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "abb.h"

using namespace std;

// g++ -std=c++11 -I include/ src/main.cpp -o out
// ./out < data/teste.txt

enum cod_funcoes{
    BUSCA,
    INSIRA,
    REMOVA,
    ENESIMO,
    POSICAO,
    MEDIANA,
    CHEIA,
    COMPLETA,
    IMPRIMA
};

map<string, cod_funcoes> map_funcoes;

int main(){    
    abb arvore; // Objeto da arvore
    int no;

    cin >> no;  // Lendo o primeiro nó (considerando o primeiro nó como a raiz)
    arvore.insert(no);

    // Criando a árvore com todos os valores passados
    while(cin >> no){
        arvore.insert(no);  // Adicionando os demais nós na arvore
    }

    // Printando a árvore inicial, sem nenhuma modificação
    cout << ">>> Árvore inicial: " << endl;
    arvore.print();
    cout << "\n" << endl;

    // Lendo arquivo de comandos
    fstream arquivo;
	arquivo.open("./data/comandos.txt");
	
    string comando_linha; // Para salvar o comando da linha do arquivo

    // Enquanto tiver comandos para ler
	while(getline(arquivo, comando_linha)){
        stringstream ler(comando_linha);
		
        string funcao;  // Salvar a funcao que está na linha de comando
		int parametro;  // Salvar o valor que está na linha de comando
        
        ler >> funcao;
        
        // Chamando a função para cada uma das funções
		switch(map_funcoes[funcao]){
            case BUSCA:
                ler >> parametro;
                arvore.search(parametro);
                break;            
            case INSIRA:
                ler >> parametro;
                arvore.insert(parametro);
                cout << ">> Inserindo elemento " << parametro << endl;
				break;
			case REMOVA:
                ler >> parametro;
                arvore.remove(parametro);
                cout << ">> Removendo elemento " << parametro << endl;
				break;
			case ENESIMO:
                ler >> parametro;
                cout << ">> N-ésimo: " << arvore.nth_element(parametro) << endl;
				break;
            case POSICAO:
                ler >> parametro;
                cout << ">> Posição: " << arvore.position(parametro) << endl;
                break;
            case MEDIANA:
                cout << ">> Mediana: " << arvore.mediana() << endl;
                break;
            case CHEIA:
                if(arvore.is_full())
                    cout << ">> Árvore eh cheia" << endl;
                cout << ">> Árvore não eh cheia" << endl;
                break;
            case COMPLETA:
                if(arvore.is_complete())
                    cout << ">> Árvore eh completa" << endl;
                cout << ">> Árvore não eh completa" << endl;
                break;
            case IMPRIMA:
                cout << ">>> Imprimindo árvore: " << arvore.to_string() << endl;
                break;
            default:
                cout << "" << endl;
                cout << ">> Comando não encontrado! " << endl;
                break;
		}
	}

    arquivo.close();  

    // Só pra testar mesmo
    cout << "" << endl;
    cout << ">>> Árvore final: " << endl;
    arvore.print();
    cout << "" << endl;   

    return 0;
}