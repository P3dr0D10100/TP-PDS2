#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#ifdef _WIN32
#define LOCAL system("chcp 65001");
#else
#define LOCAL
#endif
#include "include/doctest.h"
#include "src/Busca.h"
#include <utility>
using std::make_pair;

class Teste_MBus {
    public:
    static map<string,set<int>> indice (const MBus &m){
        return m.id_inv_;
    }
    static int num_d (const MBus &m){
        return m.N_docs_;
    }
    static vector <Documento> documentos (const MBus &m){
        return m.docs_;
    }
    static vector <int> consulta ( MBus &m,  Documento &d){
        return m.consulta(d);
    }
    
    
};

//Habilitando acentuação no windows
TEST_CASE("Acentos:")
{
    LOCAL;
}

TEST_SUITE("MBus"){
    TEST_CASE("ÍNDICE INVERTIDO, E CONSTRUTOR"){
        Documento um ("", "docs/doc4.txt", 0);
        Documento dois ("", "docs/doc5.txt", 1);
        vector <Documento> DOCS;
        DOCS.push_back(um);
        DOCS.push_back(dois);
        MBus teste (DOCS);

        CHECK (Teste_MBus::num_d(teste) == 2);

        
        map<string,set<int>> indice_teste {
            make_pair("com", set<int> {0,1}),
            make_pair("de", set<int> {0}),
            make_pair("dez", set<int> {0}),
            make_pair("documento", set<int> {0}),
            make_pair("e", set<int> {0,1}),
            make_pair("este", set<int> {0,1}),
            make_pair("ok", set<int> {0}),
            make_pair("palavras", set<int> {0,1}),
            make_pair("teste", set<int> {0,1}),
            make_pair("um", set<int> {0,1})
        
        };
        CHECK ( Teste_MBus::indice(teste) == indice_teste );

     
    }

    TEST_CASE ("CÃƒï¿½LCULO COORDENADAS"){
        Documento um ("", "docs/doc4.txt", 0);
        Documento dois ("", "docs/doc5.txt", 2);
        vector <Documento> DOCS;
        DOCS.push_back(um);
        DOCS.push_back(dois);
        MBus teste (DOCS);

        vector<double> coord_doc4 {
            0.0,
            log(2) * 2,
            log(2) * 3,
            log(2) * 2,
            0.0,
            0.0,
            log(2) * 2,
            0.0,
            0.0,
            0.0
        };

        vector<double> coord_doc5{
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0,
            0.0
        };

        vector <double> u = Teste_MBus::documentos(teste)[0].coord();
        CHECK (u == coord_doc4);
        u = Teste_MBus::documentos(teste)[1].coord();
        CHECK (u == coord_doc5);  
    }

    TEST_CASE ("CONSULTA 1"){
        Documento um ("", "docs/doc6.txt", 0);
        Documento dois ("", "docs/doc7.txt", 2);
        Documento tres ("" , "docs/doc8.txt", 8);
        vector <Documento> DOCS;
        DOCS.push_back(dois);
        DOCS.push_back(um);
        DOCS.push_back(tres);
        MBus teste (DOCS);

        Documento q ("Programacao quero teste teste novo");

        vector<int> c = Teste_MBus::consulta(teste, q);

        CHECK (c.size() == 3);
        CHECK (c[0] == 0);
        CHECK (c[1] == 2);
        CHECK (c[2] == 8);
    }

    TEST_CASE ("CONSULTA 2"){
        Documento um ("", "docs/doc4.txt", 2);
        Documento dois ("", "docs/doc5.txt", 0);
        
        vector <Documento> DOCS;
        DOCS.push_back(dois);
        DOCS.push_back(um);
        
        MBus teste (DOCS);

        Documento q ("ok");

        vector<int> c = Teste_MBus::consulta(teste, q);

        CHECK (c.size() == 2);
        CHECK (c[0] == 2);
        CHECK (c[1] == 0);
    }

    TEST_CASE ("INSERIR DOCUMENTO"){
        vector <Documento> DOCS;
        MBus teste (DOCS);
        Documento doc("", "docs/doc6.txt", 1);
        teste.inserir_doc(doc);
        map <string,set<int>> teste_indice;
        teste_indice["novo"].insert(1);
        teste_indice["teste"].insert(1);
        teste_indice["documento"].insert(1);
        teste_indice["teste"].insert(1);
        teste_indice["quero"].insert(1);
        teste_indice["acabar"].insert(1);
        teste_indice["logo"].insert(1);

        CHECK (Teste_MBus::num_d(teste) == 1);
        CHECK (Teste_MBus::documentos(teste).size() == 1);
        CHECK (Teste_MBus::indice(teste) == teste_indice);

        Documento doc1("", "docs/doc7.txt", 3);
        teste.inserir_doc(doc1);
        teste_indice["mais"].insert(3);
        teste_indice["novo"].insert(3);
        teste_indice["documento"].insert(3);
        teste_indice["trabalho"].insert(3);
        teste_indice["programacao"].insert(3);
        teste_indice["final"].insert(3);

        CHECK (Teste_MBus::num_d(teste) == 2);
        CHECK (Teste_MBus::documentos(teste).size() == 2);
        CHECK (Teste_MBus::indice(teste) == teste_indice);

    }
   
    TEST_CASE ("REMOVER DOCUMENTO EM MBus - ENCONTRA DOC"){
        vector <Documento> DOCS;
        Documento doc("primeiro", "docs/doc6.txt", 1);
        Documento doc1("segundo", "docs/doc7.txt", 3);
        DOCS.push_back(doc);
        DOCS.push_back(doc1);
        MBus teste (DOCS);
        teste.remover_doc("segundo");
        map <string,set<int>> teste_indice;
        teste_indice["novo"].insert(1);
        teste_indice["teste"].insert(1);
        teste_indice["documento"].insert(1);
        teste_indice["teste"].insert(1);
        teste_indice["quero"].insert(1);
        teste_indice["acabar"].insert(1);
        teste_indice["logo"].insert(1);
        CHECK (Teste_MBus::num_d(teste) == 1);
        CHECK (Teste_MBus::indice(teste) == teste_indice);

    }

    TEST_CASE ("REMOVER DOCUMENTO EM MBus - NAO ENCONTRA DOC"){
        vector <Documento> DOCS;
        Documento doc("primeiro", "docs/doc6.txt", 1);
        Documento doc1("segundo", "docs/doc7.txt", 3);
        DOCS.push_back(doc);
        DOCS.push_back(doc1);
        MBus teste (DOCS);
        teste.remover_doc("terceiro");

        CHECK (Teste_MBus::num_d(teste) == 2);
    }
    
    TEST_CASE ("REMOVER DOCUMENTO EM MBus VAZIA"){
        vector <Documento> DOCS;
        MBus teste (DOCS);
        teste.remover_doc("");
        CHECK (Teste_MBus::num_d(teste) == 0);
    }
   
}


