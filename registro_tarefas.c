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
    char prioridade; // 'A' para alta, 'B' para média, 'C' para baixa
    int status; // 0 para pendente, 1 para concluída
    struct tarefa *prox;
};

// Definindo a estrutura da Lista de Tarefas Diárias
struct listaTarefas {
    struct tarefa *inicio;
    int tamanho;
};

// Definindo a estrutura da lista de Estudantes
 struct lista
{
   Tarefa top;
};

// Função para criar uma lista de tarefas diárias vazia
struct listaTarefas *criarListaTarefas() {
    struct listaTarefas *l = (struct listaTarefas *)malloc(sizeof(struct listaTarefas));
    if (l != NULL) {
        l->inicio = NULL;
        l->tamanho = 0;
    }
    return l;
}

// Função para inserir uma tarefa no início da lista
int inserirTarefa(struct listaTarefas *l, struct tarefa tarefa) {
    if (l == NULL)
        return 0;
    struct tarefa *novo = (struct tarefa *)malloc(sizeof(struct tarefa));
    if (novo == NULL)
        return 0;
    *novo = tarefa;
    novo->prox = l->inicio;
    l->inicio = novo;
    l->tamanho++;
    return 1;
}

// Função para listar todas as tarefas da lista
void listarTarefas(struct listaTarefas *l) {
    if (l == NULL)
        return;
    struct tarefa *aux = l->inicio;
    while (aux != NULL) {
    	printf("Tarefa: %s\n", aux->tarefa);
        printf("Descrição: %s\n", aux->descricao);
        printf("Prioridade: %c\n", aux->prioridade);
        printf("Status: %d\n", aux->status);
        aux = aux->prox;
    }
}

// Função para pesquisar uma tarefa pelo código de prioridade
struct tarefa *pesquisarTarefa(struct listaTarefas *l, char prioridade) {
    if (l == NULL)
        return NULL;
    struct tarefa *aux = l->inicio;
    while (aux != NULL) {
        if (aux->prioridade == prioridade)
            return aux;
        aux = aux->prox;
    }
    return NULL;
}

// Função para remover uma tarefa pelo nome
int removerTarefa(struct listaTarefas *l, char* nomeTarefa) {
    if (l == NULL)
        return 0;
    struct tarefa *aux = l->inicio;
    struct tarefa *ant = NULL;
    while (aux != NULL && strcmp(aux->tarefa, nomeTarefa) != 0) {
        ant = aux;
        aux = aux->prox;
    }
    if (aux == NULL) // tarefa não encontrada
        return 0;
    if (ant == NULL) // remover o primeiro nó
        l->inicio = aux->prox;
    else // remover um nó que não é o primeiro
        ant->prox = aux->prox;
    free(aux);
    l->tamanho--;
    return 1;
}

// Função para atualizar uma tarefa pela descrição
int atualizarTarefa(struct listaTarefas *l, char *descricao, struct tarefa novaTarefa) {
    if (l == NULL)
        return 0;
    struct tarefa *aux = l->inicio;
    while (aux != NULL) {
        if (aux->descricao == descricao) {
            *aux = novaTarefa; // atualiza a tarefa
            return 1;
        }
        aux = aux->prox;
    }
    return 0; // tarefa não encontrada
}

// Função para priorizar as tarefas com base na prioridade
void priorizarTarefas(struct listaTarefas *lista) {
    if (lista == NULL || lista->inicio == NULL)
        return;
    struct tarefa *i, *j;
    for (i = lista->inicio; i->prox != NULL; i = i->prox) {
        for (j = i->prox; j != NULL; j = j->prox) {
            if (i->prioridade > j->prioridade) {
                // Troca as tarefas
                struct tarefa temp = *i;
                *i = *j;
                *j = temp;
                // Troca os ponteiros para o próximo nó
                struct tarefa *tempProx = i->prox;
                i->prox = j->prox;
                j->prox = tempProx;
            }
        }
    }
    printf("Tarefas reorganizadas com base na prioridade.\n");
}

// Função para filtrar tarefas por estado (pendente ou concluída)
void filtrarTarefasporEstado(struct listaTarefas *l, int status) {
    if (l == NULL)
        return;
    struct tarefa *aux = l->inicio;
    while (aux != NULL) {
        if (aux->status == status) {
        	printf("Tarefa: %s\n", aux->tarefa);
            printf("Descrição: %s\n", aux->descricao);
            printf("Prioridade: %c\n", aux->prioridade);
            printf("Status: %d\n", aux->status);
        }
        aux = aux->prox;
    }
}

// Função para gerenciar a fila FIFO de tarefas
struct tarefa *gerenciarFilaFIFO(struct listaTarefas *l) {
    if (l == NULL || l->inicio == NULL)
        return NULL;
    struct tarefa *aux = l->inicio;
    l->inicio = l->inicio->prox;
    l->tamanho--;
    return aux;
}

// Função para gerenciar a fila de prioridade de tarefas
struct tarefa *gerenciarFilaPrioridade(struct listaTarefas *lista, char* nomeTarefa) {
    if (lista == NULL || lista->inicio == NULL)
        return NULL;
    // Encontra a tarefa pelo nome
    struct tarefa *tarefaNome = lista->inicio;
    struct tarefa *aux = lista->inicio;
    while (aux != NULL) {
        if (strcmp(aux->tarefa, nomeTarefa) == 0) {
            tarefaNome = aux;
            break;
        }
        aux = aux->prox;
    }
    // Remove a tarefa pelo nome da lista
    removerTarefa(lista, tarefaNome->tarefa);
    return tarefaNome;
}

// Função para liberar memória alocada para a lista de tarefas
void liberarMemoria(struct listaTarefas *lista) {
    if (lista == NULL)
        return;
    struct tarefa *aux;
    while (lista->inicio != NULL) {
        aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
    }
    free(lista);
    printf("Lista de tarefas liberada da memória.\n");
}
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
