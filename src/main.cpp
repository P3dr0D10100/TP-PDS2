#ifdef _WIN32
#define LIMPAR system("cls")
#define PARA system("pause")
#define LOCAL system("chcp 65001")
#else
#define LIMPAR system("clear")
#define PARA cout << "Pressione qualquer tecla para continuar...\n"; getchar()
#define LOCAL
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
    LOCAL;
    LIMPAR;
    char opt;
    vector<Documento> Documentos;
    Documentos = init();
    MBus Maq_bus(Documentos);
    while(true)
    {
        opt = menu();
        switch(opt)
        {
            case 'A': pesquisa(Maq_bus); break;
            case 'B': altera_db(Maq_bus); break;
            case 'S': exit(0);
            default: cout << "Erro: opção inválida, tente novamente.\n"; PARA; menu();
        }
    }
    return 0;
}

vector<Documento> init()
{
    int i;
    string dir,in,nome,ext;
    vector<string> nomes;
    vector<Documento> Res;
    cout << "PROGRAMA PARA PESQUISA EM BANCOS DE DADOS\nDigite um diretório contendo alguns arquivos de texto para inicializar a base de dados: ";
    cin >> dir;
    //Mudar contra-barras para barras.
    for(i = 0; i < dir.size(); i++)
    {
        if(dir[i] == '\\')
        {
            dir[i] = '/';
        }
    }
    if(dir[dir.size() - 1] == '/' )
    {
        dir.erase(dir.size() - 1);
    }
    cout << "Entre, agora, os nomes dos arquivos que estão nesse diretório, separados por vírgulas e sem a extensão, caso houver: ";
    cin >> in;
    cout << "Agora, entre a extensão dos arquivos, caso houver (entre ponto \".\" para nenhuma): ";
    cin >> ext;
    if(ext == ".")
    {
        ext = "";
    }
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
            in = dir + "\\" + n + ext;
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
    cout << "PROGRAMA PARA PESQUISA EM BANCOS DE DADOS\nEscolha uma opção:\n\nA) Realizar pesquisa.\nB) Alterar banco de dados.\nS) Sair.\n\nEntre a letra correspondente à opção desejada: ";
    cin >> Res;
    Res = toupper(Res);
    return Res;
}

void pesquisa(MBus& maq)
{
    string query;
    vector<int> Res;
    LIMPAR;
    cout << "Entre os termos que deseja pesquisar na base de dados e pressione enter: ";
    fseek(stdin,0,SEEK_END);
    std::getline(std::cin,query);
    LIMPAR;
    Documento Q(query);
    try
    {
        Res = maq.consulta(Q);
        cout << "Os documentos da base de dados que apresentam os termos \"" << query << "\", em ordem de relevância, são:\n\n"; 
        for(int i : Res)
        {
            cout << maq.nome_doc(i) << endl;
        }
    }catch(std::invalid_argument& e)
    {
        cout << "Erro: " << e.what() << ".";
    }
    cout << "\n\n";
    PARA;
}

void altera_db(MBus& maq)
{
    char opt;
    int i;
    string dir,nome,doc,ext;
    LIMPAR;
    cout << "Escolha uma opção:\n\nA) Adicionar um documento.\nB) Remover um documento.\nC) Atualizar a base de dados.\nV) Voltar.\n\nEntre a letra correspondente à opção desejda: ";
    cin >> opt;
    opt = toupper(opt);
    switch(opt)
    {
        case 'A':
            LIMPAR;
            cout << "Entre o diretório que contém o documento que deseja adicionar: ";
            cin >> dir;
            for(i = 0; i < dir.size(); i++)
            {
                if(dir[i] == '\\')
                {
                    dir[i] = '/';
                }
            }
            if(dir[dir.size() - 1] == '/' )
            {
                dir.erase(dir.size() - 1);
            }
            cout << "Entre o nome do documento que deseja adicionar, sem a extensão, caso houver: ";
            cin >> nome;
            cout << "Entre, agora, a extensão do arquivo, caso houver (entre ponto \".\" para nenhuma): ";
            cin >> ext;
            if(ext == ".")
            {
                ext = "";
            }
            doc = dir + "\\" + nome + ext;
            try
            {
                Documento D(nome,doc,ids);
                maq.inserir_doc(D);
            }catch(std::invalid_argument& e)
            {
                cout << "Erro: " << e.what() << "." << endl;
                PARA;
                break;
            }
            cout << "Documento adicionado com sucesso!" << endl;
            ids++;
            PARA;
            break;
        case 'B':
            LIMPAR;
            cout << "Entre o nome do documento que deseja remover da base de dados, sem a extensão, caso houver: ";
            cin >> nome;
            try
            {
                maq.remover_doc(nome);
            }catch(std::invalid_argument& e)
            {
                cout << "Erro: " << e.what() << "." << endl;
                PARA;
                break;
            }
            cout << "Documento removido com sucesso!" << endl;
            PARA;
            break;
        case 'C':
            LIMPAR;
            maq.att_doc();
            break;
        case 'V':
            return;
        default:
            while(opt != 'A' && opt != 'B' && opt != 'C')
            {
                cout << "Erro: opção inválida.\nTente novamente:\n";
                cin >> opt;
                opt = toupper(opt);
            }
    }   
}