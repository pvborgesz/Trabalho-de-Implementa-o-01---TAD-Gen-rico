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
typedef struct Aluno{
	char nome[30];
	int idade;
	float media; 
}aluno; 

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

int colInserir(Colecao *c, char nome, int idade, float media){
  if ( c != NULL ) {
    if ( c->numItens < c->maxItens) {
    c->item[c->numItens] = item;
    c->numItens++;
    c->nome = nome;
    return 1;
    }
  }
}
/* fim de colInserir */


void *colRemover(Colecao *c, void *item){
  int i,j;
  int data;

  if (c!=NULL){
    if(c -> numItens > 0){
      i=0;
      while(i < c-> numItens && c -> item[i] != item){
        i++;
      }
      if( c-> item[i] == item ){
        data = c-> item[i];
        for (j=i; j<c->numItens; j++){
          c-> item[j] = c-> item[j+1];
        }
        return data; 
      } 
    }
  }
  return -32767;
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