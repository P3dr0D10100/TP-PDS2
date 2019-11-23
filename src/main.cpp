#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <experimental/filesystem>
#include "Busca.h"
#define LIMPAR system("cls")
#define PARA system("pause")
#define LOCAL system("chcp 65001")

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

namespace fs = std::experimental::filesystem;

static int ids;

vector<Documento> init();
char menu();
void pesquisa(MBus& maq);
void altera_db(MBus& maq);
string get_nome(string in,string path);

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
    string dir,nome,fpath;
    vector<Documento> Res;
    cout << "PROGRAMA PARA PESQUISA EM BANCOS DE DADOS\nDigite um diretório contendo alguns arquivos de texto para inicializar a base de dados: ";
    cin >> dir;
    try
    {
        fs::path D(dir),F;
        for(auto file : fs::recursive_directory_iterator(D))
        {   
            F = file.path();
            fpath = F.string();
            nome = get_nome(fpath,D.string());
            Res.push_back(Documento(nome,fpath,ids));
            ids++;
        }
    }catch(fs::filesystem_error& e)
    {
        cout << "Erro: ocorreu um erro ao acessar o diretório especificado." << endl;
        PARA;
    }catch(std::invalid_argument& e)
    {
        cout << "Erro: " << e.what() << "." << endl;
        PARA;
    }
    cout << "Base de dados inicializada com sucesso!" << endl;
    PARA;
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
    string dir,nome,doc,ext,in;
    vector<string> nomes;
    LIMPAR;
    cout << "Escolha uma opção:\n\nA) Adicionar um documento.\nB) Remover um documento.\nC) Atualizar a base de dados.\nV) Voltar.\n\nEntre a letra correspondente à opção desejda: ";
    cin >> opt;
    opt = toupper(opt);
    switch(opt)
    {
        case 'A':
            LIMPAR;
            cout << "Entre o diretório que contém o(s) documento(s) que deseja adicionar: ";
            cin >> dir;
            if(dir[dir.size() - 1] == '/' )
            {
                dir.erase(dir.size() - 1);
            }
            cout << "Entre os nomes dos documentos que deseja adicionar, sem a extensão, caso houver, separados por vírgulas (ou apenas um único nome): ";
            cin >> in;
            cout << "Entre, agora, a extensão dos arquivos, caso houver (entre ponto \".\" para nenhuma): ";
            cin >> ext;
            for(i = 0; i < in.size() + 1; i++)
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
                    Documento D(n,in,ids);
                    maq.inserir_doc(D);
                    ids++;
                }
            }catch(std::invalid_argument& e)
            {
                cout << "Erro: " << e.what() << "." << endl;
                PARA;
                break;
            }
            cout << "Documento(s) inserido(s) com sucesso na base de dados!" << endl;
            PARA;
            break;
        case 'B':
            LIMPAR;
            cout << "Entre o nome do documento que deseja remover da base de dados, com a extensão, caso houver: ";
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

string get_nome(string in,string path)
{
    string res;
    int i;
    for(i = path.size() + 1; i < in.size(); i++)
    {
        res.push_back(in[i]);
    }
    return res;
}