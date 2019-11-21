#ifndef DOCUMENTO_H
#define DOCUMENTO_H
#include <string>
#include <fstream>
#include <unordered_set>
#include <vector>

using std::string;
using std::ifstream;
using std::unordered_multiset;
using std::vector;

class Documento{
    public:
        //Inicializa o documento com nome "doc", diretório "dir" e identificador id, preparando para a busca.
        Documento(string doc,string dir,int id);
        //Inicializa um objeto da classe documento a partir da string "str".
        Documento(string str);
        //Inicializa o documento como uma c�pia do documento "doc".
        Documento(const Documento& doc);
        //Retorna o nome do documento atual.
        string nome();
        //Retorna o id único do documento atual.
        int id();
        //Retorna a frequência da palavra P no documento atual.
        int freq(string P);
        //Atribui ao documento atual as coordenadas contidas em V.
        void Set_coord(vector<double>& V);
        //Retorna as coordenadas do documento atual.
        vector<double> coord();
        //Retorna os tokens gerados a partir do documento atual.
        unordered_multiset<string>& tokens();
        //Atualiza o documento atual (realiza nova leitura).
        //Precondição: o objeto foi criado a partir de um documento.
        void Atualiza_doc();
        //Implementa o operador = para a classe documento.
        void operator=(const Documento& doc);
        //Fecha o documento após o uso.
        ~Documento();
    private:
        string nome_;
        string dir_;
        int id_;
        ifstream arquivo_;
        unordered_multiset<string> tokens_;
        vector<double> coord_;
    friend class Teste;
};

#endif //DOCUMENTO_H