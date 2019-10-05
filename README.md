# Intro
Este projeto consiste na implementação de Árvore Binária de Busca (ABB) em C++. A implementação do projeto explora conceitos abordados da discplina de Estrutura de Dados Básica II, ministrada pela professora [Sílvia Monteiro](https://sigaa.ufrn.br/sigaa/public/docente/portal.jsf?siape=2859606).

## Funções implementadas
- ```search(int value)```: busca um valor na ABB.

- ```insert(int value)```: insere um valor na ABB.

- ```remove(int value)```: remove um valor na ABB.

- ```nth_element(int n)```: retorna o n-ésimo elemento do percurso em ordem (ordem simétrica) da ABB.

- ```position(int value)```: retorna a posição ocupada pelo elemento x em um percurso em ordem simétrica na ABB.

- ```int mediana()```: retorna o elemento que contém a mediana da ABB. Se a ABB possuir um número par de elementos, retorne o menor dentre os dois elementos medianos.

- ```boolean is_full()```: retorna verdadeiro se a ABB for uma árvore binária cheia e falso, caso contrário.

- ```boolean is_complete()```: retorna verdadeiro se a ABB for uma árvore binária completa.

- ```string to_string()```: retorna uma string que contém a sequência de visitação (percorrimento) da ABB por nível.

## Compilando
Para compilar, basta executar no terminal o seguinte comando: ```$ g++ -std=c++11 -I include/ src/main.cpp -o out ```

## Executando
Antes de tudo, escreva as operações que você deseja executar dentro do arquivo ```data/comandos.txt``` (uma operação por linha) e os valores da sua árvore de busca no arquivo ```data/arvore.txt```, no mesmo formato dos exemplos que já estão nestes arquivos.

Para executar o projeto, basta executar no terminal: ```$ ./out < data/arvore.txt ```

## Autores
Ranna Raabe Fernandes da Costa

Frankleiton Levy
