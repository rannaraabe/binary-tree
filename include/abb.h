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
            cout << "erro-insert: Valor [" << value << "] já está na árvore!\n" << endl;
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

        if(search(value) == nullptr){    // Caso o nó não exista na árvore, eu encerro
            cout << "erro-remove: Valor [" << value << "] não está na árvore!\n" << endl;
            return;
        }

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
            cout << "aqui" << endl;
            node* troca = largest_in_subtree(no->esq);  // Percorro ate chegar no maior elemento da subarvore da esq
            // Tb existe a opcao de chamar a funcao smallest_in_subtree(); e percorrer até no menor elemento da subarvore da dir
            cout << "aqui2" << endl;            
            node* pai_troca = largest_in_subtree_father(no->esq);        

            cout << "aqui3" << endl;

            if(pai_troca->dir == nullptr){
                cout << "aqui4" << endl;
                troca->dir = no->dir;
                cout << "aqui5" << endl;
            } else {
                cout << "aqui6" << endl;

                pai_troca->dir = nullptr;
                // Troca aponta para os filhos do nó
                troca->dir = no->dir;
                troca->esq = no->esq;
                cout << "aqui7" << endl;

            }

            cout << "aquiiiiiiiiiii" << endl;


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
            cout << "erro-print: Árvore vazia!\n" << endl;

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

    node* nth_element_recursive(node *no, int n){
        if (no == nullptr || no->tam < n){
            cout << "erro-nth_element: A árvore não possui essa posição!\n";
            return new node(-1e9);
        }

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

        cout << "erro-position: O elemento não está na árvore!\n";
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
        node* no = raiz;
        return is_full_recursive(no);  // Chamo a função recursiva
    }

    bool is_full_recursive(node* no){
        if(no == nullptr)  // Caso a árvore seja vazia
            return false;

	    if(no->esq == no->dir && no->dir == nullptr)  // Caso o nó seja folha
		    return true;
	    
        //Caso os nós da esqueda e direita nao sejam nulos e as subarvores esqueda e direita foram cheias
        if ((no->esq) && (no->dir))
            return (is_full_recursive(no->esq) && is_full_recursive(no->dir));

        return false;    
    }

    /**
     * Função retorna true se a árvore binária for completa (e estritamente binária, no caso)
     */
    bool is_complete(){
        node* no = raiz;
        return is_complete_recursive(no);  // Chamo a função recursiva
    }

    bool is_complete_recursive(node* no){
        if(no == nullptr)  // Caso a árvore seja vazia
            return false;

        // Caso o nó possua dois filhos
        if(no->esq != nullptr && no->dir != nullptr)
            return true;

        if(no->esq == nullptr){
            if(is_complete_recursive(no->dir))  // Chamo a funcao para verificar se o filho direito tambem eh nulo
                return true;

            return false;   // O nó raiz só possui 1 filho
        } 
        
        // Verifico o mesmo para o caso do filho direito ser nulo
        if(is_complete_recursive(no->esq))  // Verifico se o filho esq tambem eh nulo
            return true;

        return false;  // O nó raiz só possui 1 filho
    }

    /**
     * Função retorna uma string com a sequência de visitação da árvore por nível
     */
    string to_string(){
        string str = "";

        if(raiz == nullptr){    // Confiro antes se a árvore está vazia
            cout << "erro-to_string: Árvore está vazia!\n" << endl;
            return str;
        }

        // Uso uma pilha para guardar os filhos do nó 
        queue<node*> q;
        q.push(raiz);   // Guardo a raiz

        while(!q.empty()){  
            node *no = q.front();
            q.pop();

            str += std::to_string(no->chave) + " ";  // Vou concatenando o valores dos nós
            
            if(no->esq != nullptr)  // Se tiver filho esquerdo, guardo na fila
                q.push(no->esq);

            if(no->dir != nullptr)  // Se tiver filho direito, guardo na fila
                q.push(no->dir);
        }
        
        str.pop_back();
        return str;
    }
};