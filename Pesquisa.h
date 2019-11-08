#ifndef PESQUISA_H
#define PESQUISA_H
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <deque>

using std::string;
using std::ifstream;
using std::set;
using std::multiset;
using std::map;
using std::vector;
using std::deque;

class Documento{
    public:
        //Inicializa o documento na base de dados recebendo nome e diretótio.
        Documento(string nome,string diretorio);
        //Retorna o nome do documento atual.
        string nome();
        //Assinala as coordenadas de V ao documento atual.
        void set_coord(vector<double> V);
        //Retorna a quantidade de vezes que a palavra p aparece no documento.
        int tf(string p);
        //Retorna as coordenadas do documento atual.
        vector<double> coordenadas();
    private:
        string nome_;
        string dir_;
        ifstream arquivo_;
        multiset<string> tokens_;
        vector<double> coord_;
    friend class Teste;
};

class DB{
    public:
        //Constroi a base de dados com os documentos de docs.
        DB(vector<Documento> docs);
        //Insere o documento doc na base de dados.
        void insere_doc(Documento doc);
        //Remove o documento de nome doc da base de dados.
        void remove_doc(string doc);
        //Atualiza o documento de nome doc na base de dados.
        void atualiza_doc(string doc);
        //Realiza uma consulta da string Q na base de dados.
        vector<string> consulta(string Q);
    private:
        int N_docs_;
        map<string,Documento> docs_;
        map<string,set<string>> id_inv_;
        //Calcula o índice invertido para a base de dados atual.
        void calcula_id_inv();
        //Calcula as coordenadas de um documento.
        void calcula_coord();

friend class Teste;
};



#endif //PESQUISA_H