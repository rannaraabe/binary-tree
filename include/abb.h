/**
 * @file abb.h
 * @author Ranna Raabe e Frankleiton Levy
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
     * Construtor padrão
     */ 
    abb(){

    }

    /**
     * Destrutor
     */ 
    ~abb(){ }

    /**
     * Função de busca por um valor em árvore binária
     */ 
    node search(pont_no pt, int value){
        if(pt != nullptr){
            if(pt->chave == value)
                return *pt;      // Chave encontrada e pt aponta para nó onde a chave se encontra
            else
            {
                if(value < pt->chave)
                    return search(pt->esq, value);  // Busca a chave na subarvore esquerda
                else
                    return search(pt->dir, value);  // Busca a chave na subárvore direita
            } 
        }

        pt = nullptr;   // Caso não encontre a chave na ávore, retorna null
        return *pt;
    }

    /**
     * Função de inserção de um nó em uma árvore binária
     */ 
    void insert(pont_no pt, int value){
        pont_no pt_aux = nullptr; // Ponteiro auxiliar

        if(search(pt, value).chave != NULL)       // Busca o valor na árvore, antes de adicionar
            cout << "Valor já está na árvore";
        else {
            if (pt->chave > value){     // Inserir a esquerda
                if(pt->esq != nullptr)
                    insert(pt->esq, value);
                else {
                    pt_aux->chave = value;
                    pt_aux->esq = nullptr;
                    pt_aux->dir = nullptr;
                }
            }
            else if (pt->chave <= value){   // Inserir a direita
                if(pt->dir != nullptr)
                    insert(pt->dir, value);
                else {
                    pt_aux->chave = value;
                    pt_aux->esq = nullptr;
                    pt_aux->dir = nullptr;
                }
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