#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"


int main(){
  Colecao *aluno = NULL;
  Aluno *Aluno = NULL;

  int tamColecao=1;
  int idade,op, turma;
  int qtdAlunos=0; 
  float media =  0.0;
  char nome[30];

  do{
      printf("\nDigite 1 para escolher o tamanho da sua colecao e para cadastrar um aluno: \n");
      printf("Digite 2 para consultar um Aluno dentro da sua colecao: \n");
      printf("Digite 3 para listar os seus alunos cadastrados: \n");
      printf("Digite 4 para destruir sua colecao, caso não exista alunos: \n");
      printf("Digite 5 para esvaziar a colecao: \n");
      printf("Digite 0 para fechar o menu. \n");
        
      scanf("%d", &op);
    
    switch(op){

      case 1:
        if (aluno == NULL){
          printf("Digite o tamanho desejado para sua colecao: \n");
          scanf("%d", &tamColecao);
          if (tamColecao>0){
            aluno = colCriar(tamColecao);
            printf("colecao criada com sucesso! \n");

            for(int i=0; i<tamColecao; i++){
              printf("Digite o nome do %d aluno: \n", i+1);
              scanf("%s", nome);

              printf("Digite a idade do %d aluno: \n", i+1);
              scanf("%d", &idade);
              
              printf("Digite a media do %d aluno: \n", i+1);
              scanf("%f", &media);
            }
          }
          else{
            printf("Nao foi possivel criar uma colecao com esse tamanho, tente novamente com um valor maior! \n");
          }
        if (tamColecao >= qtdAlunos){
          aluno = criarAluno(nome,idade,media);
          colInserir(Aluno, aluno);
          printf("Aluno cadastrado com sucesso! \n");
          qtdAlunos++;
        }
        else{
          printf("Você ainda não tem uma colecao criada, tente escolher a opção 1! \n");
        }
        break;
        }
      case 2:
        //colConsultar();
        break; 
      case 3:
        turma = colpegarPrimeiro(aluno);
        for(int i=0; i<qtdAlunos*3;i++){
          printf("%s, %d , %f\n",aluno);
          turma = colpegarProximo(aluno);
        }
        //aluno = colpegarProximo(Aluno);
        //printf("%s, %d , %f\n",aluno );
        break;

      default: 
        printf("opção invalida, tente novamente!");
        break;
    }

      
      
  }while(op != 0);


  
  

  return 0;
}