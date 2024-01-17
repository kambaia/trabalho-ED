typedef struct tarefa Tarefa;
// Definindo a estrutura da lista de Clientes
typedef struct lista Pilha;

//criação da lista
Pilha *criarLista();

int push(Pilha *l, Tarefa cl);
void pop(Pilha *l);
void exibirTarefas(Pilha* pilha);
