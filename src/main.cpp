#ifdef _WIN32
#define LIMPAR system("cls")
#define PARA system("pause")
#else
#define LIMPAR system("clear")
#define PARA cout << "Pressione qualquer tecla para continuar...\n"; getchar()
#endif
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "Busca.h"


using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

static int ids;

vector<Documento> init();
char menu();
void pesquisa(MBus& maq);
void altera_db(MBus& maq);

int main(int argc,char* argv[])
{
    setlocale(LC_ALL,"Portuguese");
    char opt;
    vector<Documento> Documentos;
    Documentos = init();
    MBus Maq_bus(Documentos);
    opt = menu();
    switch(opt)
    {
        case 'A': pesquisa(Maq_bus); break;
        case 'B': altera_db(Maq_bus); break;
        case 'S': exit(0);
        default: cout << "Erro: opção inválida, tente novamente.\n"; PARA; menu();
    }
    menu();
    return 0;
}

vector<Documento> init()
{
    int i;
    string dir,in,nome;
    vector<string> nomes;
    vector<Documento> Res;
    cout << "PROGRAMA PARA PESQUISAS EM BANCOS DE DADOS\nDigite um diretório contendo alguns arquivos de texto (.txt) para inicializar a base de dados: ";
    cin >> dir;
    if(dir[dir.size() - 1] == '\\' || dir[dir.size() - 1] == '/' )
    {
        dir.erase(dir.size() - 1);
    }
    cout << "Entre, agora, os nomes dos arquivos que estão nesse diretório, separados por vírgulas e sem a extensão (.txt): ";
    cin >> in;
    for(i = 0; i <= in.size(); i++)
    {
        if(in[i] != ',' && in[i] != '\0')
        {
            nome.push_back(in[i]);
        }else
        {
            nomes.push_back(nome);
            nome.clear();
        }
    }
    in.clear();
    try
    {
        for(string n : nomes)
        {
            in = dir + "\\" + n + ".txt";
            Res.push_back(Documento(n,in,ids));
            ids++;
        }
    }catch(std::invalid_argument& e)
    {
        cout << "\nErro: " << e.what() << "\nVerifique o diretório e os nomes informados (e as suas formatações) e tente novamente..." << endl;
        PARA;
    }
    return Res;
}

char menu()
{
    char Res;
    LIMPAR;
    cout << "PROGRAMA PARA PESQUISAS EM BANCOS DE DADOS\nEscolha uma opção:\n\nA) Realizar pesquisa.\nB) Alterar banco de dados.\nS) Sair.\nEntre a letra correspondente à opção desejada: ";
    cin >> Res;
    Res = toupper(Res);
    return Res;
}

void pesquisa(MBus& maq)
{
    string query;
    vector<int> Res;
    LIMPAR;
    cout << "Entre os termos que deseja pesquisar na base de dados: ";
    cin >> query;
    Documento Q(query);
    try
    {
        maq.consulta(Q);
        cout << "Resultado:\nOs documentos em que os termos \"" << query << "\" aparecem, ordenados por relevância, são:\n";
        for(int i: Res)
        {
            cout << maq.nome_doc(i) << endl;
        }
    }catch(std::invalid_argument& e)
    {
        cout << "Erro: " << e.what() << ".";
    }
    cout << endl;
    PARA;
}

void altera_db(MBus& maq)
{
    char opt;
    string dir,nome,doc;
    LIMPAR;
    cout << "Escolha uma opção:\nA) Adicionar um documento.\nB) Remover um documento.\nC) Atualizar a base de dados.\nEntre a letra correspondente à opção desejda: ";
    cin >> opt;
    opt = toupper(opt);
    switch(opt)
    {
        case 'A':
            LIMPAR;
            cout << "Entre o diretório que contém o documento que deseja adicionar: ";
            cin >> dir;
            if(dir[dir.size() - 1] == '\\' || dir[dir.size() - 1] == '/' )
            {
                dir.erase(dir.size() - 1);
            }
            cout << "Entre o nome do documento que deseja adicionar, sem a extensão (.txt): ";
            cin >> nome;
            doc = dir + "\\" + nome + ".txt";
            maq.inserir_doc(Documento(nome,dir,ids));
            break;
        case 'B':
            LIMPAR;
            cout << "Entre o nome do documento que deseja remover da base de dados, sem a extensão (.txt): ";
            cin >> nome;
            maq.remover_doc(nome);
            break;
        case 'C':
            LIMPAR;
            maq.att_doc();
            break;
        default:
            while(opt != 'A' && opt != 'B' && opt != 'C')
            {
                cout << "Erro: opção inválida.\nTente novamente:\n";
                cin >> opt;
                opt = toupper(opt);
            }
    }   
}