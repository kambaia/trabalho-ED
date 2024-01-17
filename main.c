
#include "registro_usuario.c"
#include <locale.h>
// Função principal

// Exiber menu principal
void menuPrincial()
{
    printf("*********************Seja bem vido ao gestor de tarefas *********************\n");
    printf("");
    printf("1- usuários\n");
    printf("2- Tarefas\n");
    printf("0 - Sair\n");
}
// Exiber menu principal
void exiberMenuUsuarios()
{
    printf("********************* Usuário *********************\n");
    printf("");
    printf("1- Registrar usuário\n");
    printf("2- Listar usuário\n");
    printf("3- Pesquisar usuário\n");
    printf("4- Deletar usuário usuário\n");
    printf("5- atualizar Usuário");
    printf("6- LiberarMemoria");
    printf("0 - Sair\n");
}
// Exiber menu principal
void exiberMenuTarefas()
{
    printf("********************* Tarefas *********************\n");
    printf("");
    printf("1. Adicionar Tarefa Diaria\n");
    printf("2. Remover Tarefa Diaria\n");
    printf("3. Listar Tarefas Diarias\n");
    printf("4. Editar Tarefa Diaria\n");
    printf("5. Priorizar Tarefa\n");
    printf("6. Filtrar Tarefas Diarias por Estado\n");
    printf("7. Gerenciar Fila FIFO\n");
    printf("8. Gerencia Fila de Prioridade\n");
    printf("9. Lolocar como finalizada bom base a prioridade- Listar usuário\n");
    printf("10. Liberar Memoria");
    printf("0. Sair\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = criarLista();
    Usuario al;
    int opMenu_principal, opMenu_usuario, opMenu_tarefa, voltar, idUsuario;
    struct listaTarefas *lista = criarListaTarefas();
    struct tarefa tarefa, novaTarefa;
    struct tarefa *proxTarefa = NULL; // Mova a declaração para fora do bloco switch
    struct tarefa *tarefaPrioritaria = NULL; // Mova a declaração para fora do bloco switch

    do
    {
        menuPrincial();
        scanf("%d", &opMenu_principal);
        switch (opMenu_principal)
        {
        case 1:
            exiberMenuUsuarios();
            scanf("%d", &opMenu_usuario);
            do
            {
                switch (opMenu_usuario)
                {
                case 1:

                    printf("Primeiro Nome: ");
                    scanf("%s", &al.primeiroNome);

                    if (inserirUsuario(lista, al))
                    {
                        printf("Usuário inserido com sucesso.\n");
                    }
                    else
                    {
                        printf("Erro ao inserir Usuário.\n");
                    }
                     printf("Desejas adiconarr mais?: sim [1]  não [0] ");
                    scanf("%d", &voltar);
                    break;
                case 2:

                    listarUsuario(lista);
                    break;
                case 3:
                    printf("Digite o id do usuário para pesquisar: ");
                    scanf("%d", &idUsuario);
                    pesquisarUsuario(lista, idUsuario);
                    break;

                case 4:

                    printf("Digite o id do usuário que seja apagar: ");
                    scanf("%d", &idUsuario);
                    if (removerUsuario(lista, idUsuario))
                    {
                        printf("Usuário apagado com sucesso.\n");
                    }
                    else
                    {
                        printf("Erro ao remover usuário.\n");
                    }
                    break;
                case 5:

                    printf("Digite o número de usuário para atualizar: ");
                    scanf("%dC", &idUsuario);
                     actualizarUsuario(lista, idUsuario);
                    break;

                case 6:
                    liberarMemoria(lista);
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
                }

            } while (voltar != 0);
             break;
            
        case 2:
            exiberMenuTarefas();
            scanf("%d", &opMenu_tarefa);
            
           switch (opMenu_tarefa) {
            case 1:
                // Adiciona Tarefa Diária
                printf("Nome da Tarefa: ");
                scanf(" %s", tarefa.tarefa);
                fflush(stdin);

                printf("Descrição: ");
                scanf(" %s", tarefa.descricao);
                fflush(stdin);

                printf("Prioridade ('A' para alta, 'B' para media, 'C' para baixa): ");
                scanf(" %c", &tarefa.prioridade);
                fflush(stdin);

                printf("Status (0 para pendente, 1 para concluida): ");
                scanf(" %d", &tarefa.status);
                fflush(stdin);

                inserirTarefa(lista, tarefa);
                printf("Tarefa adicionada com sucesso.\n");
                break;

            case 2:
				    // Remove Tarefa Diária
				    char nomeTarefa[100];
				    printf("Nome da Tarefa a ser removida: ");
				    scanf(" %s", nomeTarefa);
				    if (removerTarefa(lista, nomeTarefa)) {
				        printf("Tarefa removida com sucesso.\n");
				    } else {
				        printf("Erro ao remover tarefa.\n");
				    }
				    break;

            case 3:
                // Lista Tarefas Diárias
                if (lista->inicio == NULL) {
                    printf("Nenhuma Tarefa\n");
                } else {
                    printf("\nLista de Tarefas Diárias:\n");
                    listarTarefas(lista);
                }
                break;

            case 4:
                // Edita Tarefa Diária
                printf("Nome da tarefa a ser editada: ");
                scanf(" %s", novaTarefa.tarefa);
                fflush(stdin);

                printf("Nova Descrição: ");
                scanf(" %s", novaTarefa.descricao);
                fflush(stdin);

                printf("Nova Prioridade ('A' para alta, 'B' para media, 'C' para baixa): ");
                scanf(" %c", &novaTarefa.prioridade);
                fflush(stdin);

                printf("Novo status (0 para pendente, 1 para concluída): ");
                scanf(" %d", &novaTarefa.status);
                fflush(stdin);

                if (atualizarTarefa(lista, novaTarefa.tarefa, novaTarefa)) {
                    printf("Tarefa atualizada com sucesso.\n");
                } else {
                    printf("Erro ao atualizar tarefa.\n");
                }
                break;

            case 5:
			    // Prioriza Tarefas Diárias
			    priorizarTarefas(lista);
			    printf("Tarefas reorganizadas com base na prioridade.\n");
			    break;

            case 6:
                // Filtra Tarefas Diárias por Estado
                int estadoFiltro;
                printf("Filtrar por estado (0 para pendente, 1 para concluida): ");
                scanf("%d", &estadoFiltro);
                filtrarTarefasporEstado(lista, estadoFiltro);
                break;
               
            /*case 7:
			    // Gerencia Fila FIFO de Tarefas Diárias
			     proxTarefa = gerenciarFilaFIFO(lista);
			    if (proxTarefa != NULL) {
			        printf("Próxima tarefa removida: %s\n", proxTarefa->tarefa);
			    } else {
			        printf("Nenhuma tarefa na fila.\n");
			    }
			    break;

            case 8:
    			// Gerencia Fila de Prioridade de Tarefas Diárias
			    tarefaPrioritaria = gerenciarFilaPrioridade(lista);
			    if (tarefaPrioritaria != NULL) {
			        printf("Tarefa de maior prioridade removida: %s\n", tarefaPrioritaria->tarefa);
			    } else {
			        printf("Nenhuma tarefa na fila.\n");
			    }
			    break;*/
			    
            case 0:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opMenu_tarefa != 0);
    liberarMemoria(lista);

    return 0;
    }
