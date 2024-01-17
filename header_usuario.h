typedef struct usuario Usuario;
// Definindo a estrutura da lista de Usuarios
typedef struct lista Lista;

//criação da lista
Lista *criarLista();

int inserirUsuario(Lista *l, Usuario cl);
void listarUsuario(Lista *l);
void pesquisarUsuario(Lista *lista, int usuarioId);
int removerUsuario(Lista *l, int code);
void actualizarUsuario(Lista *lista, int usuarioId);
void liberarMemoria(Lista *lista);

