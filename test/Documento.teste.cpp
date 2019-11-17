#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "src/Documento.h"

class Teste{
    public:
        static string nome(const Documento& doc)
        {
            return doc.nome_;
        }
        static string dir(const Documento& doc)
        {
            return  doc.dir_;
        }
        static int id(const Documento& doc)
        {
            return doc.id_;
        }
        static bool arq_aberto(const Documento& doc)
        {
            return doc.arquivo_.is_open();
        }
        static unordered_multiset<string> tokens(const Documento& doc)
        {
            return doc.tokens_;
        }
        static vector<double> coord(const Documento& doc)
        {
            return doc.coord_;
        }
};

static int ids = 1;

//Este teste apenas habilita o uso da acentuação no windows.
TEST_CASE("Acentos:")
{
    setlocale(LC_ALL,"Portuguese");
}

TEST_SUITE("Testes para o construtor da classe Documento:")
{
    TEST_CASE("Arquivo vazio:")
    {
        string d = "docs/vazio.txt";
        Documento doc("",d,ids);
        CHECK(Teste::nome(doc) == "");
        CHECK(Teste::dir(doc) == d);
        CHECK(Teste::id(doc) == ids);
        REQUIRE(Teste::arq_aberto(doc) == true);
        unordered_multiset<string> toks = Teste::tokens(doc);
        CHECK(toks.empty() == true);
        CHECK(toks.size() == 0);
        vector<double> crd = Teste::coord(doc);
        CHECK(crd.empty() == true);
        CHECK(crd.size() == 0);
        ids++;
    }
    TEST_CASE("Arquivos não-vazios:")
    {
        string d,nome,tok;
        ifstream format;
        unordered_multiset<string> toks,res;
        vector<double> crd;
        SUBCASE("doc.txt")
        {
            nome = "d1";
            d = "docs/doc.txt";
            Documento doc(nome,d,ids);
            CHECK(Teste::nome(doc) == "d1");
            CHECK(Teste::dir(doc) == d);
            CHECK(Teste::id(doc) == ids);
            REQUIRE(Teste::arq_aberto(doc) == true);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            format.open("docs/f1.txt");
            while(format >> tok)
            {
                res.insert(tok);
            }
            REQUIRE(toks.size() == res.size());
            CHECK(toks == res);
            crd = Teste::coord(doc);
            CHECK(crd.empty() == true);
            CHECK(crd.size() == 0);
            format.close();
            ids++;
        }
        SUBCASE("doc1.txt")
        {
            nome = "d2";
            d = "docs/doc1.txt";
            Documento doc(nome,d,ids);
            CHECK(Teste::nome(doc) == nome);
            CHECK(Teste::dir(doc) == d);
            CHECK(Teste::id(doc) == ids);
            REQUIRE(Teste::arq_aberto(doc) == true);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            format.open("docs/f2.txt");
            while(format >> tok)
            {
                res.insert(tok);
            }
            REQUIRE(toks.size() == res.size());
            CHECK(toks == res);
            crd = Teste::coord(doc);
            CHECK(crd.empty() == true);
            CHECK(crd.size() == 0);
            format.close();
            ids++;
        }
        SUBCASE("d2.txt")
        {
            nome = "d3";
            d = "docs/d2.txt";
            Documento doc(nome,d,ids);
            CHECK(Teste::nome(doc) == nome);
            CHECK(Teste::dir(doc) == d);
            CHECK(Teste::id(doc) == ids);
            REQUIRE(Teste::arq_aberto(doc) == true);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            format.open("docs/f3.txt");
            while(format >> tok)
            {
                res.insert(tok);
            }
            REQUIRE(toks.size() == res.size());
            CHECK(toks == res);
            crd = Teste::coord(doc);
            CHECK(crd.empty() == true);
            CHECK(crd.size() == 0);
            format.close();
            ids++;
        }
        SUBCASE("doc3.txt")
        {
            nome = "d4";
            d = "docs/doc3.txt";
            Documento doc(nome,d,ids);
            CHECK(Teste::nome(doc) == nome);
            CHECK(Teste::dir(doc) == d);
            CHECK(Teste::id(doc) == ids);
            REQUIRE(Teste::arq_aberto(doc) == true);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            format.open("docs/f4.txt");
            while(format >> tok)
            {
                res.insert(tok);
            }
            REQUIRE(toks.size() == res.size());
            CHECK(toks == res);
            crd = Teste::coord(doc);
            CHECK(crd.empty() == true);
            CHECK(crd.size() == 0);
            format.close();
        }
    }
    TEST_CASE("Construindo a partir de strings:")
    {
        string s1,s2,s3,s4;
        s1 = "TeStanDO a ConstruCao d-e #DoCuMento a partir de \"strings\"! (ok)";
        s2 = "OUTRO teste a partir dE 'StringS': 1, 2, 3, 4";
        s3 = "Mais um #TESTE com UmA 'string'@#%!";
        s4 = "CRiAndo maIS uma STRING % e exercitando a CRIATIVIDADE...";
        SUBCASE("s1:")
        {
            unordered_multiset<string> res{"testando","a","construcao","de","documento","a","partir","de","strings","ok"};
            unordered_multiset<string> toks;
            Documento doc(s1);
            CHECK(Teste::nome(doc) == "Query");
            CHECK(Teste::dir(doc) == "");
            CHECK(Teste::id(doc) == -1);
            CHECK(Teste::arq_aberto(doc) == false);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            CHECK(toks.size() == 10);
            CHECK(toks == res);
        }
        SUBCASE("s2:")
        {
            unordered_multiset<string> res{"outro","teste","a","partir","de","strings","1","2","3","4"};
            unordered_multiset<string> toks;
            Documento doc(s2);
            CHECK(Teste::nome(doc) == "Query");
            CHECK(Teste::dir(doc) == "");
            CHECK(Teste::id(doc) == -1);
            CHECK(Teste::arq_aberto(doc) == false);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            CHECK(toks.size() == 10);
            CHECK(toks == res);
        }
        SUBCASE("s3:")
        {
            unordered_multiset<string> res{"mais","um","teste","com","uma","string"};
            unordered_multiset<string> toks;
            Documento doc(s3);
            CHECK(Teste::nome(doc) == "Query");
            CHECK(Teste::dir(doc) == "");
            CHECK(Teste::id(doc) == -1);
            CHECK(Teste::arq_aberto(doc) == false);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            CHECK(toks.size() == 6);
            CHECK(toks == res);
        }
        SUBCASE("s4:")
        {
            unordered_multiset<string> res{"criando","mais","uma","string","e","exercitando","a","criatividade"};
            unordered_multiset<string> toks;
            Documento doc(s4);
            CHECK(Teste::nome(doc) == "Query");
            CHECK(Teste::dir(doc) == "");
            CHECK(Teste::id(doc) == -1);
            CHECK(Teste::arq_aberto(doc) == false);
            toks = Teste::tokens(doc);
            REQUIRE(toks.empty() == false);
            CHECK(toks.size() == 8);
            CHECK(toks == res);
        }
    } 
}