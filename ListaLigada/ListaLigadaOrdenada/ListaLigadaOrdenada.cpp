#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
    menu();
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no Windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no Windows
    }
}

void inicializar()
{
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    cout << "Lista inicializada \n";
}

void exibirQuantidadeElementos() {
    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;
}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    cout << "Elementos: \n";
    NO* aux = primeiro;
    while (aux != NULL) {
        cout << aux->valor << endl;
        aux = aux->prox;
    }
}

void inserirElemento()
{
    int valor;
    cout << "Digite o elemento: ";
    cin >> valor;
    
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return;
    novo->valor = valor;
    novo->prox = NULL;
    
    if (primeiro == NULL || primeiro->valor > valor) {
        novo->prox = primeiro;
        primeiro = novo;
    } else {
        NO* aux = primeiro;
        while (aux->prox != NULL && aux->prox->valor < valor) {
            aux = aux->prox;
        }
        if (aux->prox != NULL && aux->prox->valor == valor) {
            cout << "Valor duplicado! Nao inserido." << endl;
            free(novo);
            return;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

void excluirElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia. Nada para excluir.\n";
        return;
    }

    int numero;
    cout << "Digite o valor a ser excluido: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor < numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL || atual->valor != numero) {
        cout << "ELEMENTO NAO ENCONTRADO\n";
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    cout << "Elemento excluido com sucesso!\n";
}

void buscarElemento()
{
    if (primeiro == NULL) {
        cout << "Lista vazia. Nenhum elemento para buscar.\n";
        return;
    }

    int numero;
    cout << "Digite o valor a ser buscado: ";
    cin >> numero;

    NO* aux = primeiro;
    while (aux != NULL && aux->valor < numero) {
        aux = aux->prox;
    }

    if (aux != NULL && aux->valor == numero) {
        cout << "ENCONTRADO\n";
    } else {
        cout << "ELEMENTO NAO ENCONTRADO\n";
    }
}
