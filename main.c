#include <stdio.h>
#include <stdlib.h>
#include "colecao.h"
#include <string.h>



int main(){
  Colecao *cofoAlunos = NULL;
  Aluno *Aluno = NULL;

  int tamColecao;
  int i=0;
  int idade,op, turma;
  int qtdAlunos=1;
  float media;
  char nome[30];
  char alunoParaRemover[30];
  char aux[100];

  do{
    printf("\nDigite 1 para escolher o tamanho da turma: \n");
    printf("Digite 2 para para matricular um aluno: \n");
    printf("Digite 3 para listar os seus alunos cadastrados: \n");
    printf("Digite 4 para remover um aluno da turma: \n");
    printf("Digite 5 para esvaziar a colecao: \n");
    printf("Digite 0 para fechar o menu. \n");

    scanf("%d", &op);

    switch(op){
      case 1:
        if(cofoAlunos == NULL){
          printf("Digite o tamanho da turma: ");
          scanf("%d",&tamColecao);
    
          if (tamColecao>0){
            cofoAlunos = colCriar(tamColecao);
          }
          else{
            printf("Tamanho da turma insuficiente, tente colocar um valor maior que 0! \n");
          }     
        }
        else{
          printf("já foi criada a turma");
        }
        break;
        
      case 2:
        if(cofoAlunos != NULL){
          printf("turma criada com sucesso! \n");
            for(int i=0; i<tamColecao; i++){
              printf("\n");
              printf("Digite o nome do %d aluno: \n", i+1);
              scanf("%s", nome);
              printf("Digite a idade do %d aluno: \n", i+1);
              scanf("%d", &idade);
              printf("Digite a media do %d aluno: \n", i+1);
              scanf("%f", &media);
              Aluno = criarAluno(nome,idade,media); // cadastrando os alunos no fim de cada iteração do laço
              qtdAlunos++;
              if (colInserir(cofoAlunos, Aluno)){
                printf("Aluno matriculado\n");
              }
              else{
                printf("Erro na matricula");
              }
            }
          }
        
        break;

      case 3:
        Aluno = colpegarPrimeiro(cofoAlunos);
        while(Aluno != NULL){
          printf("O nome do aluno é %s, sua idade é %d anos, sua média é %.2f.\n", pegarNome(Aluno), pegarIdade(Aluno), pegarMedia(Aluno));
          Aluno = colpegarProximo(cofoAlunos);
        }
        break;
        
      case 4:
        printf("Digite o nome do aluno que você deseja remover da turma: \n");
        scanf("%s", alunoParaRemover);
        
        //colRemover(cofoAlunos, alunoParaRemover);
        /*
        for( int i=0; i<qtdAlunos; i++){
          if(  Aluno[i]!= NULL){
            if(strcmp(alunoParaRemover, Aluno->nome[i])==1){
               Aluno[i] == NULL;
            }
          }
        }
        printf("Aluno removido com sucesso, se desejar, selecione a opção 3 novamente para ver os alunos atuais!");*/
        break;
        
      case 0:
        printf("Obrigado por utilizar nosso programa! \n");
        break;
      default:
        printf("opção invalida, tente novamente!");
        break;
    }



  }while(op != 0);


  return 0;
}

