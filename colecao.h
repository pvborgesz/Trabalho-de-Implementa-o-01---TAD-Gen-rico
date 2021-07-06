/*------------------------------------------------
Colecao.h
Arquivo com a especificação para o TAD Colecao,
tipo de dado para uma coleção genérica.
Exemplo do curso: Estrutura de Dados
---------------------------------------------------
Autor: João Mateus e Paulo Victor

Julho/2021
-------------------------------------------------*/
#ifndef COLECAO_H
#define COLECAO_H
/*-------------------------------------------------
Definicoes locais
-------------------------------------------------*/
typedef struct colecao
Colecao;

typedef struct aluno
Aluno;

/*-------------------------------------------------
Funcoes que implementam as operacoes do
TAD ColecaoInt
*/

Colecao *colCriar( int max_itens );

int colInserir( Colecao *c, int *item);

void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*));
//void *colRemover( Colecao *c, void *item );

int colBuscar( Colecao *c, void *key );

int colDestruir( Colecao *c );

void *colpegarPrimeiro(Colecao *c);

void *colpegarProximo(Colecao *c);

Aluno *criarAluno(char[], int idade, float media);

char *pegarNome(Aluno *aluno);

int pegarIdade(Aluno *aluno);

float pegarMedia(Aluno *aluno);

//int colRemoverAluno(Colecao *c, void *item);
void *colRemover(Colecao *c, void *key, int(*cmp)(void*,void*));

int compararAlunos(void *aluno1, void *aluno2);


#endif