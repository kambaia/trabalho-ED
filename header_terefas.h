typedef struct tarefa Tarefa;
// Definindo a estrutura da lista de Clientes
typedef struct lista Pilha;

//criação da lista
Pilha *criarLista();

int push(Pilha *l, Tarefa cl);
void pop(Pilha *l);
void exibirTarefas(Pilha* pilha);
int atualizarTarefa(struct listaTarefas *l, char *descricao, struct tarefa novaTarefa);
struct listaTarefas *criarListaTarefas();
struct tarefa *gerenciarFilaFIFO(struct listaTarefas *l);
struct tarefa *gerenciarFilaPrioridade(struct listaTarefas *lista, char* nomeTarefa);
int inserirTarefa(struct listaTarefas *l, struct tarefa tarefa);
void liberarMemoria(struct listaTarefas *lista);
void listarTarefas(struct listaTarefas *l);
struct tarefa *pesquisarTarefa(struct listaTarefas *l, char prioridade);
void priorizarTarefas(struct listaTarefas *lista);
int removerTarefa(struct listaTarefas *l, char* nomeTarefa);
