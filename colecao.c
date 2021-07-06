#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"

// Estrutura da colecao de alunos
typedef struct colecao{
  int numItens;
  int maxItens;
  int atual;
  void **item;
}Colecao;

// Estrutura do Aluno
typedef struct aluno{
	char nome[30];
  int idade;
  float media;
}Aluno;

Colecao *colCriar(int maxItens){
  Colecao *c;
  if (maxItens>0){
    c = (Colecao*)malloc(sizeof(void*)*maxItens);
    if(c!=NULL){
      c->item = (void**)malloc(sizeof(void*)*maxItens);
      if(c->item != NULL){
        c->maxItens = maxItens;
        c->numItens = 0;
        return c;
      }
      free(c);
    }
  }
return NULL;
}

int colInserir(Colecao *c, int *item ){
  if ( c != NULL ) {
    if ( c->numItens < c->maxItens) {
    c->item[c->numItens] = item;
    c->numItens++;
    return 1;
    }
  }
}
/* fim de colInserir */

void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*))
{
  int i, j;
  void *del;
  if(c != NULL)
  {
    if(c->numItens > 0)
    {
      for(i=0; i < c->numItens; i++)
      {
        if(cmp(key, c->item[i]) == 1)
        {
          del = c->item[i];
          for(j=i; j < c->numItens-1; j++)
          {
            c->item[j] = c->item[j+1];
          }
          c->numItens--;
          return del;
        }
      }
    }
  }
  return NULL;
}



//fim  de colRemover

void *colConsultar(Colecao *c, int item){
  int i;
  int data;

  if(c != NULL){
    if(c-> numItens >0){
      i=0;
      while( i < c-> numItens && c-> item[i] != item){
        i++;
      }
      if( c->item[i] == item){
        return c->item;
      }
    }
  }
  return -32767;
}

int colDestruir( Colecao *c ){
  if ( c != NULL ) {
    if ( c->numItens == 0 ) {
      free(c->item);
      free(c);
      return 1 ;
    }
  }
  return 0;
} /* fim de colDestruir */


void *colpegarPrimeiro(Colecao *c){
  if(c!=NULL){
        if(c->item != NULL){
            c->atual = 0;
            return c->item[c->atual];
        }
    }
    return NULL;
}

void *colpegarProximo(Colecao *c)
{
    if(c!=NULL){
        if(c->item != NULL){
            c->atual++;
            if(c->atual < c->numItens){
                return c->item[c->atual];
            }
        }
    }
    return NULL;
}

Aluno *criarAluno(char nome[], int idade, float media){
  Aluno *aluno = (Aluno *)malloc(sizeof(Aluno));
  if(aluno != NULL){
    strcpy(aluno->nome, nome);
    aluno->idade = idade;
    aluno->media = media;
    return aluno;
  }
  else{
    return NULL;
  }
}

char *pegarNome(Aluno *aluno) // Retorna o nome do Aluno
{
  if(aluno != NULL){
    return aluno->nome;
  }
  return NULL;
}

int pegarIdade(Aluno *aluno) // Retorna a idade do Aluno
{
  if(aluno != NULL){
    return aluno->idade;
  }
  return -1;
}

float pegarMedia(Aluno *aluno) // Retorna a media do Aluno
{
  if(aluno != NULL){
    return aluno->media;
  }
  return 0;
}


/*int colRemoverAluno(Colecao *c, void *item){
  void *data;
  int i;
  int *stat;
  if(c != NULL){
    if(c -> numItens>0){
      i= 0;
do
            {
                stat = strcmp(item, c->item[i]);
                if(stat != 0)
                {
                    data = c->item[i];
                    i++;
                    c->item[i] = NULL;
                }
                else
                {
                    break;
                }
            }while(i < c->numItens);
    }
  }
}*/


