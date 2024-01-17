
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
    printf("1- Adicionar uma nova tarefa\n");
    printf("2- Lolocar como finalizada bom base a prioridade- Listar usuário\n");
    printf("6- Liberar Memoria");
    printf("0 - Sair\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    Lista *lista = criarLista();
    Usuario al;
    int opMenu_principal, opMenu_usuario, opMenu_tarefa, voltar, idUsuario;

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
            break;
         default:
            printf("Opção inválida!\n");
            break;

        }


    } while (opMenu_principal != 0);

    return 0;
}
