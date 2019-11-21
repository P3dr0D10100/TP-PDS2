#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "src/Busca.h"
#include <utility>


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
    
};

//Este teste apenas habilita o uso da acentuação no windows.
TEST_CASE("Acentos:")
{
    setlocale(LC_ALL,"Portuguese");
}

TEST_SUITE("MBus"){
    TEST_CASE("ÍNDICE INVERTIDO E CONSTRUTOR"){
        Documento um ("", "docs/doc4.txt", 0);
        Documento dois ("", "docs1/doc5.txt", 1);
        vector <Documento> DOCS;
        DOCS.push_back(um);
        DOCS.push_back(dois);
        MBus teste (DOCS);

        CHECK (Teste_MBus::num_d(teste) == 2);

        map<string,set<int>> indice_teste {
            make_pair("este", set<int> {0,1}),
            make_pair("e", set<int> {0,1}),
            make_pair("um", set<int> {0,1}),
            make_pair("documento", set<int> {0}),
            make_pair("teste", set<int> {0,1}),
            make_pair("de", set<int> {0}),
            make_pair("com", set<int> {0,1}),
            make_pair("dez", set<int> {0}),
            make_pair("palavras", set<int> {0,1}),
            make_pair("ok", set<int> {0}),
        
        };
        CHECK ( Teste_MBus::indice(teste) == indice_teste );
    }

    TEST_CASE ("CALCULO DAS COORDENADAS"){
        
    }

   
}


