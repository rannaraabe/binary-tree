/**
 * @file abb.h
 * @author Ranna Raabe
 */ 

#include <iostream>
#include <string>
#include <queue>
using namespace std;

/**
 * Struct que representa o nó
 */
struct node
{
    int chave;
    struct node *esq;
    struct node *dir;      
};

class abb
{
private:
    typedef struct node no;     // Definindo um nó do tipo node
    typedef no *pont_no;        // Definindo um ponteiro para o nó
    no *raiz;    // Nó raiz

public:
    /**
     * Função de busca por um valor em árvore binária
     */ 
    void search(pont_no pt, int value, int f){
        if(pt != nullptr){
            if(pt->chave = value)
                f = 1;      // Chave encontrada e pt aponta para nó onde a chave se encontra
            else
            {
                if(value < pt->chave){
                    if(pt->esq = nullptr)
                        f = 2;      // Chave não encontrada e pt aponta para nó cuja árvore esquerda é vazia
                    else 
                        pt = pt->esq;
                } else {
                    if(pt->dir = nullptr)
                        f = 3;      // Chave não encontrada e pt aponta para nó cuja árvore direita é vazia
                    else
                        pt = pt->dir;
                }
                if(f < 1)
                    search(pt, value, f);
            } 
        } else 
            f = 0;      // Árvore vazia
    }

    /**
     * Função de inserção de um nó em uma árvore binária
     */ 
    void insert(pont_no pt, int value, int f){
        pont_no pt_aux = nullptr; // Ponteiro auxiliar
        search(pt, value, f);   // Busca o valor na árvore, antes de adicionar

        if(f == 1)
            cout << "Valor já está na árvore";
        else {
            // ocupar(pt_aux);
            pt_aux->chave = value;
            pt_aux->esq = nullptr;
            pt_aux->dir = nullptr;

            if(f == 0)
                this->raiz = nullptr;   // Árvore vazia
            else {
                if(f == 2)
                    pt->esq = pt_aux;   // Chave na esquerda
                else 
                    pt->dir = pt_aux;   // Chave na direita
            }
        }
            
    }

    /**
     * Função de remoção de um nó em uma árvore binária
     */ 
    node* remove(pont_no pt, int value, int f){
        pont_no pt_aux = nullptr; // Ponteiro auxiliar

        if(pt == nullptr)
            return nullptr;   

        if(pt->esq == nullptr && pt->dir == nullptr){
            if(pt->chave == value)
                return nullptr;
            else
                return pt;
        } 

        queue<node*> fila;
        fila.push(pt);

        // else {
        //     pt_aux->chave = pt->chave;
        //     pt_aux->esq = pt->esq;
        //     pt_aux->dir = pt->dir;

        //     if(pt_aux->chave == value){
        //         if (pt_aux->esq == nullptr)
        //             pt_aux->dir;
        //         else if(pt_aux->dir == nullptr)
        //             pt_aux->esq;
        //         else {
                    
        //         }
        //     }
        // }

    }

    /**
     * Função imprime a árvore
     */ 
    void print(){

    }

    /**
     * Função retorna o n-ésimo elemento da árvore
     */ 
    int nth_element(int n){

    }

    /**
     * Função retorna a posição da árvore do elemento passado por parâmetro
     */ 
    int position(int n){

    }

    /**
     * Função retorna o elemento que contém a mediana da árvore 
     */  
    int mediana(){

    }

    /**
     * Função retorna true se a árvore binária for cheia
     */ 
    bool is_full(){

    }

    /**
     * Função retorna true se a árvore binária for completa
     */ 
    bool is_complete(){

    }

    /**
     * Função retorna uma string com a sequência de visitação da árvore por nível
     */  
    string to_string(){

    }
};