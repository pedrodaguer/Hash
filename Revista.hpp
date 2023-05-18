#include <iostream>
#include <string>
using namespace std;

#define TAM 31

struct Revista
{
    int matricula;
    string Titulo;
    string Editora;
    string Autor;
    Revista *proximo;
};

struct ListaRev
{
    Revista *inicio;
    int tam;
};

void inicializarListaRev(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirListaRev(Lista *l, int matricula, string titulo, string autor, string editora)
{
    Revista *novo = new Revista;

    if (novo)
    {
        novo->matricula = matricula;
        novo->Titulo = titulo;
        novo->Autor = autor;
        novo->Editora = editora;
        novo->proximo = NULL;

        if (l->inicio == NULL)
        {
            l->inicio = novo;
        }
        else
        {
            Revista *primeiro = l->inicio;
            novo->proximo = primeiro;
            l->inicio = novo;
        }

        l->tam++;
    }
    else
    {
        cout << "\n\tErro ao alocar memória!\n";
    }
}

Revista *buscarListaRev(Lista *l, int matricula)
{
    Revista *aux = l->inicio;
    while (aux != NULL)
    {
        if (aux->matricula == matricula)
        {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

void imprimirListaRev(Lista *l)
{
    Revista *aux = l->inicio;
    cout << " Tam(" << l->tam << "): ";
    while (aux)
    {
        cout << aux->Titulo << " | ";
        aux = aux->proximo;
    }
}

void inicializarTabelaRev(Lista t[])
{
    for (int i = 0; i < TAM; i++)
        inicializarListaRev(&t[i]);
}

int funcaoHashRev(int matricula)
{
    return matricula % TAM;
}

void inserirRev(Lista t[], int matricula, string titulo, string autor, string editora)
{
    int id = funcaoHashRev(matricula);
    inserirListaRev(&t[id], matricula, titulo, autor, editora);
}

Revista *buscarRev(Lista t[], int matricula)
{
    int id = funcaoHashRev(matricula);
    return buscarListaRev(&t[id], matricula);
}

void imprimirRev(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        cout << i << " = ";
        imprimirListaRev(&t[i]);
        cout << "\n";
    }
}
