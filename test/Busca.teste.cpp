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
    static void calc_id (){
        MBus::calcula_id_inv();
    }

};

TEST_SUITE("MBus"){
    TEST_CASE("ÍNDICE INVERTIDO E CONSTRUTOR"){
        Documento um ("", "docs/doc.txt", 0);
        Documento dois ("", "docs1/doc.txt", 0);
        vector <Documento> DOCS;
        DOCS.push_back(um);
        DOCS.push_back(dois);
        MBus teste (DOCS);

        CHECK (Teste_MBus::num_d(teste) == 2);

        map<string,set<int>> indice_teste {
            make_pair("um", set<int> {0,1}),
            make_pair("arquivo", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
            make_pair("um", set<int> {0}),
        };
        CHECK (Teste_MBus::indice() == indice_teste );
    }

    TEST_CASE("Construtor"){
        Documento um ("", "docs/doc.txt", 0);
        vector <Documento>

    }
}


