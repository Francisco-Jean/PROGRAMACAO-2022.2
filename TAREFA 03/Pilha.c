#include "Pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 10

struct pilha {
  int tamanho;
  int capacidade_maxima;
  Aluno *pilha_alunos;
};

/* Aloca espaço em memória e retorna uma pilha. */
Pilha *pilha_cria() {
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
  pilha->pilha_alunos = (Aluno *)malloc(CAPACIDADE_INICIAL * sizeof(Aluno *));
  pilha->capacidade_maxima = CAPACIDADE_INICIAL;
  pilha->tamanho = 0;
  return pilha;
}

/* Libera a memória de uma pilha previamente criada e atribui NULL ao ponteiro
 * pilha. Retorna 1 caso seja possível fazer a liberação e 0 caso a pilha
 * informada seja NULL. */
int pilha_libera(Pilha **pilha) {
  if (pilha != NULL) {
    if ((*pilha)->tamanho > 0) {
      free((*pilha)->pilha_alunos);
      (*pilha)->pilha_alunos = NULL;
    }
    free(*pilha);
    *pilha = NULL;
    return 1;
  }
  return 0;
}


/* Insere um aluno na Pilha. Retorna 1 se foi possível adicionar, 0 caso já
 * exista um aluno com a mesma matricula (nesse caso, o aluno não pode ser
 * adicionado) e -1 caso a pilha ou aluno sejam NULL.
 */
int pilha_push(Pilha *pilha, Aluno *aluno) {
    if (pilha == NULL || aluno == NULL) {
      return -1;
    }
  int matricula;
  char nome[50];
  char curso[30];
  
  int matricula2;
  char nome2[50];
  char curso2[30];
  alu_acessa(aluno,&matricula,nome,curso);
  
  for (int a = 0; a < pilha->tamanho; a++) {
    alu_acessa((&(pilha->pilha_alunos))[a],&matricula2,nome2,curso2);
    if(matricula2 == matricula){
      return 0;
    }
  }
  (&(pilha->pilha_alunos))[pilha->tamanho] = aluno;
  pilha->tamanho++;
  return 1;
}


/* Remove um aluno na pilha. Retorna o aluno ou NULL caso a pilha esteja vazia
 * ou seja NULL. */
Aluno *pilha_pop(Pilha *pilha) {
  if (pilha == NULL || pilha->tamanho == 0){
    return NULL;
  }
  Aluno *aln = (&(pilha->pilha_alunos))[pilha->tamanho-1];
  
  (&(pilha->pilha_alunos))[pilha->tamanho] = NULL;
  pilha->tamanho--;
  return aln;
}


/* Recupera o primeiro aluno da pilha. Retorna o aluno ou NULL caso a pilha
 * esteja vazia ou seja NULL. */
Aluno *pilha_top(Pilha *pilha) {
    if (pilha == NULL || pilha->tamanho == 0) {
    return NULL;
  }
  return (&(pilha->pilha_alunos))[pilha->tamanho-1];
}

/* Busca aluno pelo número de matricula. Retorna o aluno se este estiver na
 * lista e NULL caso contrário, isto é, (i) pilha vazia; (ii) não exista aluno
 * com a matricula fornecida; ou (iii) a pilha seja NULL */
Aluno *pilha_busca(Pilha *pilha, int matricula) {
  int matricula1;
  char nome[50];
  char curso[30];
  if (pilha != NULL) {
    for (int x = 0; x < pilha->tamanho; x++) {
      alu_acessa((&(pilha->pilha_alunos))[x], &matricula1, nome, curso);
      if (matricula1 == matricula) {
        return (&(pilha->pilha_alunos))[x];
      }
    }
  }
  return NULL;
}


/* Verifica se a pilha está vazia. Retorna 1 se a pilha estiver vazia, 0 caso
 * não esteja vazia e -1 se p Pilha for NULL
 */
int pilha_vazia(Pilha *pilha) {
  if (pilha == NULL) {
    return -1;
  }
  if (pilha->tamanho == 0) {
    return 1;
  }
  return 0;
}


/* Computa a quantidade de alunos na pilha. Retorna a quantidade de alunos
 * ou -1, caso a Pilha for NULL.
 */
int pilha_quantidade(Pilha *pilha) {
    if (pilha == NULL) {
    return -1;
  }
  return pilha->tamanho;
}
