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
    node *esq;
    node *dir;
    int tam;

    node(int value) : chave(value), esq(nullptr), dir(nullptr), tam(1) { }
};

class abb
{
private:
    node *pont_no;        // Definindo um ponteiro para o nó
    node *raiz;    // Nó raiz

public:
    /**
     * Construtor padrão
     */
    abb(){ }

    /**
     * Destrutor
     */
    ~abb(){ }


    /**
     * Função de busca por um valor em árvore binária
     */
    node* search(int value){
        return search_recursive(raiz, value);
    }

    node* search_recursive(node *pt, int value){
        if(pt != nullptr){
            if(pt->chave == value)
                return pt;      // Chave encontrada e pt aponta para nó onde a chave se encontra
            else
            {
                if(value < pt->chave)
                    return search_recursive(pt->esq, value);  // Busca a chave na subarvore esquerda
                else
                    return search_recursive(pt->dir, value);  // Busca a chave na subárvore direita
            }
        }

        pt = nullptr;   // Caso não encontre a chave na ávore, retorna null
        return pt;
    }

    void insert(int value){
        if(raiz == nullptr){
            raiz = new node(value);     // Atribui o valor passado para raiz
            return;
        }
        insert_recursive(raiz, value);
    }

    /**
     * Função de inserção de um nó em uma árvore binária
     */
    void insert_recursive(node *pt, int value){
        if(pt->chave == value){       // Busca o valor na árvore, antes de adicionar
            cout << "Valor [" << value << "] já está na árvore";
            return;
        } else if (pt->chave > value){     // Inserir a esquerda
            if(pt->esq != nullptr)
                insert_recursive(pt->esq, value);
            else {
                pt->esq = new node(value);
            }
        } else {   // Inserir a direita
            if(pt->dir != nullptr)
                insert_recursive(pt->dir, value);
            else {
                pt->dir = new node(value);
            }
        }
        int tam_esq = pt->esq != nullptr ? pt->esq->tam : 0;
        int tam_dir = pt->dir != nullptr ? pt->dir->tam : 0;
        pt->tam = tam_esq + tam_dir;
    }

    /**
     * Função de remoção de um nó em uma árvore binária
     */
    void remove(int value){
        bool esquerdo = false;  // Esquerdo é verdadeiro sse pai->esq == no
        node *no = raiz;        // No começa na raiz
        node *pai = nullptr;    // Pai do nó

        // Buscando o elemento na arvore
        while(no != nullptr){
            if(value < no->chave){  // Se estiver na esquerda da subarvore
                pai = no;
                no = no->esq;
                esquerdo = true;
            }
            else if(value > no->chave){ // Se estiver na direita da subarvore
                pai = no;
                no = no->dir;
                esquerdo = false;
            }
            else{   // Se o nó atual eh o que estava sendo buscado  
                break;
            }
        }

        // Caso nó não exista
        if(no == nullptr)
            return;

        // Caso folha
        if(no->dir == nullptr && no->esq == nullptr){
            if(esquerdo){
                pai->esq = nullptr;
            }
            else{
                pai->dir = nullptr;
            }
            return;
        }

        // Caso filho tem uma subarvore
        if(no->dir == nullptr){     // Se só tem subarvore na esquerda
            if(esquerdo){
                pai->esq = no->esq; // Caso 2 do slide
            } else {
                pai->dir = no->esq;
            }
        } else if(no->esq == nullptr){ // Se só tem subarvore na direita
            if(esquerdo){
                pai->esq = no->dir; // Caso 2 do slide (se fosse na direita)
            } else {
                pai->dir = no->dir;
            }
        } else {    // Caso 3 do slide (com duas subárvores)
            node* troca = largest_in_subtree(no->esq);  // Percorro ate chegar no maior elemento da subarvore da esq
            
            // Troca aponta para os filhos do nó
            troca->esq = no->esq;   
            troca->dir = no->dir;

            if(pai == nullptr)  // Caso seja a raiz
                raiz = troca;
            else{
                if(esquerdo){
                    pai->esq = troca;
                } else {
                    pai->dir = troca;
                }
            } 
            // importante: precisa calcular o tamanho da árvore após a remoção!!!!!!
        }
    }

    node* largest_in_subtree(node *raiz_sub){
        node* pt = raiz_sub;

        if(pt == nullptr)
            return nullptr;

        while(pt->dir != nullptr)
            pt = pt->dir;

        return pt;
    }

    node* smallest_in_subtree(node *raiz_sub){
        node* pt = raiz_sub;

        if(pt == nullptr)
            return nullptr;

        while(pt->esq != nullptr)
            pt = pt->esq;

        return pt;
    }

    /**
     * Função imprime a árvore
     */
    void print(){

    }

    /**
     * Função retorna o n-ésimo elemento da árvore
     */
    node* nth_element(int n){
        // Caso base
        return nth_element_recursive(raiz, n);
    }

    node* nth_element_recursive(node *no, int n){
        if(no == nullptr)
            return no;
        
        int tam_esq = no->esq != nullptr ? no->esq->tam : 0;

        if(n - tam_esq == 0)
            return no;

        if(tam_esq < n){
            return nth_element_recursive(no->esq, n);
        } else {
            return nth_element_recursive(no->dir, n-tam_esq-1);
        }
    }

    /**
     * Função retorna a posição da árvore do elemento passado por parâmetro (por ordem simétrica)
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