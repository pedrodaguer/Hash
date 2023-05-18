#include "Revista.hpp"
#include "Livro.hpp"
using namespace std;

void menu(Lista tabela[], ListaRev tabelarev[])
{
    int opcao;
    Livro l1;
    Revista r1;
    int matricula;
    string titulo, editora, autor;
    inicializarTabela(tabela);
    inicializarTabelaRev(tabelarev);
    do
    {
        cout << "\t1 - Inserir\n\t2 - Buscar\n\t3 - Imprimir\n\t4 - Sair\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\t1 - Livro\n\t2 - Revista\n";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                cout << "\tDigite a matrícula do livro que deseja inserir: ";
                cin >> matricula;
                cout << "\tDigite o título do livro que deseja inserir: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "\tDigite a editora do livro que deseja inserir: ";
                getline(cin, editora);
                cout << "\tDigite o autor do livro que deseja inserir: ";
                getline(cin, autor);
                inserir(tabela, matricula, titulo, autor, editora);
                break;

            case 2:
                cout << "\tDigite a matrícula da revista que deseja inserir: ";
                cin >> matricula;
                cout << "\tDigite o título da revista que deseja inserir: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "\tDigite a editora da revista que deseja inserir: ";
                getline(cin, editora);
                cout << "\tDigite o autor da revista que deseja inserir: ";
                getline(cin, autor);
                inserirRev(tabelarev, matricula, titulo, autor, editora);
                break;

            default:
                break;
            }

        case 2:
            cout << "\t1 - Livro\n\t2 - Revista\n";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                cout << "\tDigite a matrícula do livro que deseja buscar: ";
                cin >> matricula;
                if (Livro *livroEncontrado = buscar(tabela, matricula))
                {
                    cout << "\tLivro encontrado!\n";
                    cout << "\tTítulo do livro: " << livroEncontrado->Titulo << "\n";
                    cout << "\tMatrícula do livro: " << livroEncontrado->matricula << "\n";
                    cout << "\tAutor do livro: " << livroEncontrado->Autor << "\n";
                    cout << "\tEditora do livro: " << livroEncontrado->Editora << "\n";
                }
                else
                {
                    cout << "\tLivro não encontrado!\n";
                }
                break;

            case 2:
                cout << "\tDigite a matrícula da revista que deseja buscar: ";
                cin >> matricula;
                if (Revista *revistaEncontrada = buscarRev(tabelarev, matricula))
                {
                    cout << "\tRevista encontrada!\n";
                    cout << "\tTítulo: " << revistaEncontrada->Titulo << "\n";
                    cout << "\tMatrícula: " << revistaEncontrada->matricula << "\n";
                    cout << "\tAutor: " << revistaEncontrada->Autor << "\n";
                    cout << "\tEditora: " << revistaEncontrada->Editora << "\n";
                }
                else
                {
                    cout << "\tRevista não encontrada!\n";
                }
                break;

            default:
                break;
            }

        case 3:
            cout << "\t1 - Livro\n\t2 - Revista\n";
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                imprimir(tabela);
                break;

            case 2:
                imprimirRev(tabelarev);
                break;

            default:
                cout << "Opção inválida!\n";
            }
        }
        while (opcao != 4)
            ;
    }
}
