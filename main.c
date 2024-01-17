#include "registro_tarefas.c"
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
    system("cls");
}
// Exiber menu principal
void menuPrincial()
{
    printf("********************* Usuário *********************\n");
    printf("");
    printf("1- Registrar usuário\n");
    printf("2- Listar usuário\n");
    printf("3- Pesquisar usuário\n");
    printf("4- Deletar usuário usuário\n");
    printf("5- atualizar Usuário");
    printf("6- LiberarMemoria")
        printf("0 - Sair\n");
    system("cls");
}
// Exiber menu principal
void menuPrincial()
{
    printf("********************* Tarefas *********************\n");
    printf("");
    printf("1- Adicionar uma nova tarefa\n");
    printf("2- Lolocar como finalizada bom base a prioridade- Listar usuário\n");
    printf("6- Liberar Memoria")
        printf("0 - Sair\n");
    system("cls");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = criarLista();
    Usuario al;
    int opMenu_principal, opMenu_usuario, opMenu_tarefa, idUsuario;

    do
    {
        menuPrincial();
        scanf("%d", &opMenu_principal);
        switch (op)
        {
        case 1:
            exiberMenuUsuarios();
            ´ scanf("%d", &opMenu_usuario);

            do
            {

                switch (opMenu_usuario)
                {
                case 1:
                    system("cls");
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
                    break;
                case 2:
                    system("cls");
                    listarUsuario(lista);
                    break;
                case 3:
                    printf("Digite o id do usuário para pesquisar: ");
                    scanf("%d", &clienteId);
                    pesquisarUsuario(lista, idUsuario);
                    break;

                case 4:
                    system("cls");
                    printf("Digite o id do usuário que seja apagar: ");
                    scanf("%d", &clienteId);
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
                   system("cls");
                    printf("Digite o número de usuário para atualizar: ");
                    scanf("%dC", &clienteId);
                     actualizarUsuario(lista, idUsuario);
                    break;

                case 6:
                    system("cls");
                    liberarMemoria(lista);
                    break;

                case 0:
                    system("cls");
                    printf("Saindo do programa...\n");
                    break;
                default:
                    printf("Opção inválida!\n");
                    break;
                }

            } while (opMenu_usuario !=0);

            break;
        case 1:
            exiberMenuTarefas();
            scanf("%d", &opMenu_tarefa);
            break;
        }

    } while (op != 0);

    return 0;
}
