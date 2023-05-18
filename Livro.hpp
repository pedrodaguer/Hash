#include <iostream>
#include <string>
using namespace std;

#define TAM 31

struct Livro
{
    int matricula;
    string Titulo;
    string Editora;
    string Autor;
    Livro *proximo;
};

struct Lista
{
    Livro *inicio;
    int tam;
};

void inicializarLista(Lista *l)
{
    l->inicio = NULL;
    l->tam = 0;
}

void inserirLista(Lista *l, int matricula, string titulo, string autor, string editora)
{
    Livro *novo = new Livro;

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
            Livro *primeiro = l->inicio;
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

Livro *buscarLista(Lista *l, int matricula)
{
    Livro *aux = l->inicio;
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

void imprimirLista(Lista *l)
{
    Livro *aux = l->inicio;
    cout << " Tam(" << l->tam << "): ";
    while (aux)
    {
        cout << aux->Titulo << " | ";
        aux = aux->proximo;
    }
}

void inicializarTabela(Lista t[])
{
    for (int i = 0; i < TAM; i++)
        inicializarLista(&t[i]);
}

int funcaoHash(int matricula)
{
    return matricula % TAM;
}

void inserir(Lista t[], int matricula, string titulo, string autor, string editora)
{
    int id = funcaoHash(matricula);
    inserirLista(&t[id], matricula, titulo, autor, editora);
}

Livro *buscar(Lista t[], int matricula)
{
    int id = funcaoHash(matricula);
    return buscarLista(&t[id], matricula);
}

void imprimir(Lista t[])
{
    for (int i = 0; i < TAM; i++)
    {
        cout << i << " = ";
        imprimirLista(&t[i]);
        cout << "\n";
    }
}
