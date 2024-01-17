#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_terefas.h"

 struct tarefa
{
    int id;
    char tarefa[50];
    char descricacao[200];
    int idUsuario;
    struct tarefa *prox;
};

// Definindo a estrutura da lista de Estudantes
 struct lista
{
   Tarefa top;
};


/* Função para exibir as tarefas na pilha
void exibirPilha(Pilha* pilha) {
    printf("Tarefas na pilha:\n");
    Tarefa* atual = pilha->topo;
    while (atual != NULL) {
        printf("Tarefas: %s\n", atual->tarefa);
        printf("Descrição: %s\n", atual->descricacao);
        printf("ID do Usuário: %d\n", atual->idUsuario);
        printf("\n");
        atual = atual->proximo;
    }
    printf("\n");
}
*/
