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
        //Inicializa o documento com nome "doc" e diretório "dir", preparando para a busca.
        Documento(string doc,string dir);
        //Retorna o nome do documento atual.
        string nome();
        //Retorna a frequência da palavra P no documento atual.
        int freq(string P);
        //Atribui ao documento atual as coordenadas contidas em V.
        void set_coord(vector<double> V);
        //Retorna as coordenadas do documento atual.
        vector<double> coord();
        //Fecha o documento após o uso.
        ~Documento();
    private:
        string nome_;
        string dir_;
        ifstream arquivo_;
        unordered_multiset<string> tokens_;
        vector<double> coord_;
};

#endif //DOCUMENTO_H