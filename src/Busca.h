#ifndef BUSCA_H
#define BUSCA_H
#include <string>
#include <map>
#include <set>
#include <vector>
#include "Documento.h"

using std::string;
using std::map;
using std::set;
using std::vector;

class MBus{
    public:
        //Constroi uma base de dados com os documentos de docs.
        MBus(vector<Documento> &docs);
        //Insere o documento doc na base de dados.
        void inserir_doc(Documento doc);
        //Remove o documento de nome "doc" da base de dados.
        void remover_doc(string doc);
        //Atualiza do documento de nome "doc" na base de dados.
        void att_doc(string doc);
        //Realiza uma busca pela palavra "Q" na base de dados.
        vector<string> consulta(string Q);
    private:
        int N_docs_;
        //map do nome dos documentos para o objeto da classe Documento correspondente.
        vector<Documento> docs_;
        //map de palavras para um set com o índice dos documentos.
        map<string,set<int>> id_inv_;
        
        void calcula_id_inv();
        //Calcula as coordenadas de um documento.
        void calcula_coord();
    friend class Teste;
};

#endif //BUSCA_H