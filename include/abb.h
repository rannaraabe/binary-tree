/**
 * @file abb.h
 * @author Ranna Raabe e Frankleiton Levy
 */

#include <iostream>
#include <string>
#include <stack>
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

    // Construtor do node
    node(int value) : chave(value), esq(nullptr), dir(nullptr), tam(1) { }
};

class abb
{
private:
    node *raiz;    // Nó raiz

public:
    /**
     * Construtor padrão
     */
    abb(){
        raiz = nullptr;
    }

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

    /**
     * Função de inserção de um nó em uma árvore binária
     */
    void insert(int value){
        if(raiz == nullptr){
            raiz = new node(value);     // Atribui o valor passado para raiz
            return;
        }
        insert_recursive(raiz, value);
    }

    void insert_recursive(node *pt, int value){
        if(pt->chave == value){       // Busca o valor na árvore, antes de adicionar
            cout << "err-insert: Valor [" << value << "] já está na árvore" << endl;
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
        pt->tam = tam_esq + tam_dir+1;

    }

    /**
     * Função de remoção de um nó em uma árvore binária
     */
    void remove(int value){
        bool esquerdo = false;  // Esquerdo é verdadeiro sse pai->esq == no
        node *no = raiz;        // No começa na raiz
        node *pai = nullptr;    // Pai do nó

        if(search(value) == nullptr)    // Caso o nó não exista na árvore, eu encerro
            return;

        // Buscando o elemento na arvore assim para poder saber quem eh o pai
        while(no != nullptr){
            no->tam--;  // Diminuo o tamanho do nó a cada passada

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

        // Caso folha
        if(no->dir == nullptr && no->esq == nullptr){
            if(esquerdo){
                pai->esq = nullptr;
                no->tam--;  // Diminuo o tamanho da arvore
            }
            else{
                pai->dir = nullptr;
                no->tam--;  // Diminuo o tamanho da arvore
            }
            return;
        }

        // Caso filho tem uma subarvore
        if(no->dir == nullptr){     // Se só tem subarvore na esquerda
            if(esquerdo){
                pai->esq = no->esq; // Caso 2 do slide
                no->tam--;  // Diminuo o tamanho da arvore
            } else {
                pai->dir = no->esq;
                no->tam--;  // Diminuo o tamanho da arvore
            }
        } else if(no->esq == nullptr){ // Se só tem subarvore na direita
            if(esquerdo){
                pai->esq = no->dir; // Caso 2 do slide (se fosse na direita)
                no->tam--;  // Diminuo o tamanho da arvore
            } else {
                pai->dir = no->dir;
                no->tam--;  // Diminuo o tamanho da arvore
            }
        } else {    // Caso 3 do slide (com duas subárvores)
            node* troca = largest_in_subtree(no->esq);  // Percorro ate chegar no maior elemento da subarvore da esq
            // Tb existe a opcao de chamar a funcao smallest_in_subtree(); e percorrer até no menor elemento da subarvore da dir
            node* pai_troca = largest_in_subtree_father(no->esq);        

            if(pai_troca->dir == nullptr){
                troca->dir = no->dir;
            } else {
                pai_troca->dir = nullptr;
                // Troca aponta para os filhos do nó
                troca->dir = no->dir;
                troca->esq = no->esq;
            }

            if(pai == nullptr){  // Caso seja a raiz
                raiz = troca;
                troca->tam = no->tam-1;  // Diminuo o tamanho da arvore
            }
            else{
                if(esquerdo){
                    pai->esq = troca;
                    troca->tam = no->tam-1;  // Diminuo o tamanho da arvore
                } else {
                    pai->dir = troca;
                    troca->tam = no->tam-1;  // Diminuo o tamanho da arvore
                }
            }
            delete no;
        }
    }

    /**
     * Função auxiliar da função remove(). A função percorre a subarvore até chegar no maior elemento
     */
    node* largest_in_subtree(node *raiz_sub){
        node* pt = raiz_sub;

        if(pt == nullptr)   // Caso não exista nó
            return nullptr;

        while(pt->dir != nullptr)   // Percorre até chegar no ultimo nó
            pt = pt->dir;

        return pt;  // Retorna o ultimo nó
    }

    node* largest_in_subtree_father(node *raiz_sub){    // A função percorre a subarvore até chegar no maior elemento salvando o ponteiro pai dele
        node* pt = raiz_sub;

        if(pt == nullptr)   // Caso não exista nó
            return nullptr;

        if(pt->dir == nullptr)  // Já é o maior elemento, não tem pai
            return nullptr;

        while(pt->dir->dir != nullptr)   // Percorre até chegar no ultimo nó
            pt = pt->dir;

        return pt;  // Retorna o ultimo nó
    }

    /**
     * Função auxiliar da função remove(). A função percorre a subarvore até chegar no menor elemento
     */
    node* smallest_in_subtree(node *raiz_sub){
        node* pt = raiz_sub;

        if(pt == nullptr)   // Caso não exista nó
            return nullptr;

        while(pt->esq != nullptr)   // Percorre até chegar no ultimo nó
            pt = pt->esq;

        return pt;  // Retorna o ultimo nó
    }

    /**
     * Função imprime a árvore no formato pré ordem (15(13(9(6()))(14()))(25(17())(28(27())(31()))))
     */
    void print(){
        node* no = raiz;

        if(no == nullptr)
            cout << "err-print: Árvore vazia" << endl;

        print_recursive(no);
    }

    void print_recursive(node *no){
        if(no == nullptr)
            return;

        cout << "(" << no->chave;

        print_recursive(no->esq);
        print_recursive(no->dir);

        if(no->esq == nullptr && no->dir == nullptr)    // Caso o nó seja folha
            cout << "()";
        else if(no->esq != nullptr && no->dir == nullptr);   // Caso o nó não tenha filho na direita
        else if(no->esq == nullptr && no->dir != nullptr);   // Caso o nó não tenha filho na esquerda

        cout << ")";
    }

    /**
     * Função retorna o n-ésimo elemento da árvore
     */
    node* nth_element(int n){
        // Caso base
        return nth_element_recursive(raiz, n);
    }

    // TODO corrigir seg fault q ta dando quando busca qualquer elemento que não está na primeira posicao
    node* nth_element_recursive(node *no, int n){
        if (raiz->tam < n){
            cout << "err-nth_element: A árvore não possui essa posição! ";
            return new node(-1e9);
        }
        
        if(no == nullptr)
            return nullptr;

        int tam_esq = no->esq != nullptr ? no->esq->tam : 0;    // Calcula o tamanho da subarvore esquerda

        if(n - tam_esq == 0)    // Significa que você está no elemento da busca, basta retorna-lo
            return no;

        if(tam_esq > n){
            return nth_element_recursive(no->esq, n);   // Caso do elemento passado estar na subarvore esquerda
        } else {
            return nth_element_recursive(no->dir, n-tam_esq-1); // Caso do elemento passado estar na subarvore direita
        }
    }

    /**
     * Função retorna a posição da árvore do elemento passado por parâmetro (por ordem simétrica)
     */
    int position(int value){
        if(search(value) != nullptr)    // Primeiro procuro se o elemento está na árvore
            return position_recursive(raiz, value, size(raiz->esq), size(raiz->dir));

        cout << "err-position: O elemento não está na árvore! ";
        return -1e9;    // Retorno saída qualquer caso o elemente não esteja na árvore
    }

    int position_recursive(node* no, int value, int l, int r){
        if(no->chave == value)  // Se o valor do nó atual for o valor que eu busco, retorno o valor de left (l)
            return l;

        if(no->chave > value){  // Busco na subarvore esquerda
            l = l - size(no->esq->dir) - 1;
            r = r + size(no->esq->dir) + 1;
            return position_recursive(no->esq, value, l, r);
        } else {    // Busco na subarvore direira
            return position_recursive(no->dir, value, l+size(no->dir->esq)+1, r-size(no->dir->esq)+1);
        }
    }

    /**
     * Função auxiliar da função position(). Retorna o tamanho do nó
     */  
    int size(node* no){
        if(no == nullptr)
            return 0;

        return no->tam;
    }

    /**
     * Função retorna o elemento que contém a mediana da árvore
     */
    int mediana(){
        // Se for impar, retorna o elemento raiz->tam/2, se for par retorna o raiz->tam/2-1
        return nth_element(raiz->tam/2 - (1-(raiz->tam%2)))->chave;
    }

    /**
     * Função retorna true se a árvore binária for cheia
     */
    bool is_full(){
        // TODO
        // Conferir se até o penultimo nivel se <= n-1 folhas
        // Ainda n sei como fazer mas bora pensar, pensei que só, mas num saiu nao kkk
    }

    /**
     * Função retorna true se a árvore binária for completa (e estritamente binária, no caso)
     */
    bool is_complete(){
        // TODO
        // Conferir se cada folha tem os filhos esq e dir nulos, se todas as folhas tiverem eh completa
        // Conferir tb se cada nó
        // Cada nó tem que ter o ultimo tamanho igual para todas as folhas, com esq e dir nulos, como salvamos isso pra verificar futuramente ?
    }

    /**
     * Função retorna uma string com a sequência de visitação da árvore por nível
     */
    string to_string(){
        node* no = raiz;

        if(no == nullptr)   // Se a raiz for nula, não existe arvore
            return "Árvore vazia";

        string arvore = "";

        // TODO
        // Usar um array (lembra o jeito de salvar uma heap), e só concatenar os valores de cada posicao do array na string
        // Aaaacho que isso funcionaria, mas acho q a complexidade fica n^2
        // Pode usar uma fila, adicionar os valores da arvore lá
        // Depois pegar todos e colocar na string e retornar, acho q esse a complixidade fica em n

        return arvore;
    }
};