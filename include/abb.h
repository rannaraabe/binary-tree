/**
 * @file abb.h
 * @author Ranna Raabe
 */ 

#include <iostream>

/**
 * Struct que representa o nó
 */
struct node
{
    int chave;
    int conteudo;
    struct node *esq;
    struct node *dir;      
};

class abb
{
private:
    /* data */
public:
    typedef struct node no;     // Definindo um nó do tipo node
    typedef no *pont_no;        // Definindo um ponteiro para o nó

    /**
     * Função de busca por um valor em árvore binária
     */ 
    void search(pont_no pt, int value, int f){
        if(pt != nullptr){
            if(pt.chave = value)
                f = 1;
            else
            {
                if(value < pt.chave){
                    if(pt.esq = nullptr)
                        f = 2;
                    else 
                        pt = pt.esq;
                } else {
                    if(pt.dir = nullptr)
                        f = 3;
                    else
                        pt = pt.dir;
                }
                if(f < 1)
                    search(pt, value, f);
            } 
        }
    }

    /**
     * Função de inserção de um nó em uma árvore binária
     */ 
    void insert(){

    }

    /**
     * Função de remoção de um nó em uma árvore binária
     */ 
    void remove(){

    }
};