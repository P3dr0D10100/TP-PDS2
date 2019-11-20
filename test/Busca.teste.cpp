#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "src/Busca.h"

class Teste {
    public:
    map<string,set<int>> indice (MBus &m){
        return m.id_inv_;
    }

};

TEST_SUITE("MBus"){
    TEST_CASE("Índice Invertido"){
       
    }
}


