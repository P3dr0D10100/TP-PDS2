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
}