#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header_usuario.h"


 struct usuario
{
    int id;
    char primeiroNome[50];
    struct usuario *prox;
};

// Definindo a estrutura da lista de Estudantes
 struct lista
{
    Usuario *inicio;
    int tam;
};

// Criando uma lista vazia
Lista *criarLista()
{
    Lista *l = (Lista *)malloc(sizeof(Lista));
    if (l != NULL)
    {
        l->inicio = NULL;
        l->tam = 0;
    }
    return l;
}

// Inserindo um estudante no inicio da lista
int inserirUsuario(Lista *l, Usuario al)
{
    if (l == NULL)
        return 0;
    Usuario *novoCl = (Usuario *)malloc(sizeof(Usuario));
    if (novoCl == NULL)
        return 0;
    *novoCl = al;
    novoCl->prox = l->inicio;
    l->inicio = novoCl;
    l->tam++;
    return 1;
}
// Listar todos os estudantes da lista
void listarUsuario(Lista *l)
{
    if (l == NULL)
        return;
    if (l->inicio == NULL)
    {
        printf("Lista vazia.\n");
        return;
    }
    Usuario *aux = l->inicio;
    while (aux != NULL)
    {
        printf("Nome: %s %s\n", aux->primeiroNome, aux->primeiroNome);
        printf("----------\n");
        aux = aux->prox;
    }
}
// Função principal
//Pequisar pelo numero de estudante
void pesquisarUsuario(Lista *lista, int usuarioId) {
    Usuario *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->id == usuarioId) {
            printf("usuario encontrado:\n");
            printf("ID: %s %s\n", atual->id);
            printf("Nome: %s %s\n", atual->primeiroNome, atual->primeiroNome);
            return;
        }
        atual = atual->prox;
    }
    printf("Usuário com ID %d não encontrado.\n", usuarioId);
}

// Removendo um estudante pelo seu code
int removerUsuario(Lista *l, int usuarioId)
{
    if (l == NULL)
        return 0;
    if (l->inicio == NULL)
        return 0;
    Usuario *ant, *atual = l->inicio;
    while (atual != NULL && atual->id != usuarioId)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
        return 0;
    if (atual == l->inicio)
    {
        l->inicio = atual->prox;
    }
    else
    {
        ant->prox = atual->prox;
    }
    free(atual);
    l->tam--;
    return 1;
}
// Atualizar Aluno Pelo Numero de Estudante
void actualizarUsuario(Lista *lista, int usuarioId) {
    Usuario *atual = lista->inicio;

    while (atual != NULL) {
        if (atual->id == usuarioId) {
            printf("Primeiro Nome: ");
            scanf("%s", atual->primeiroNome);
            system("cls");
            printf("Usuário atualizado com sucesso.\n");
            return;
        }
        atual = atual->prox;
    }
     system("cls");
    printf(" Usuario com id %d não encontrado.\n", usuarioId);
}


void liberarMemoria(Lista *lista) {
    if (lista == NULL) return; // verificando se a lista é válida
    Usuario *aux; 
    while (lista->inicio != NULL) { // enquanto a lista não estiver vazia
        aux = lista->inicio; // fazendo o ponteiro auxiliar apontar para o início da lista
        lista->inicio = aux->prox; // fazendo o início da lista apontar para o segundo nó
        free(aux); // liberando a memória do primeiro nó
    }
    free(lista); // liberando a memória da lista
    printf("Lista de usuario limpa.\n");
}

