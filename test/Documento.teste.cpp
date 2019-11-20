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
        /*Este método é utilizado para testar a atualização de documentos,
        a partir da alteração do diretorio do arquivo aberto atualmente na 
        classe Documento.*/
        static void altera_arq(Documento& doc,const string dir)
        {
            doc.dir_ = dir;
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

TEST_CASE("Testando o método 'nome':")
{
    Documento d1("Teste"),d2("d1","docs/doc1.txt",1),d3("","docs/vazio.txt",0),d4("d2","docs/d2.txt",2);
    CHECK(d1.nome() == Teste::nome(d1));
    CHECK(d2.nome() == Teste::nome(d2));
    CHECK(d3.nome() == Teste::nome(d3));
    CHECK(d4.nome() == Teste::nome(d4));
}

TEST_SUITE("Testando o método 'freq':")
{
    TEST_CASE("doc.txt:")
    {
        Documento doc("d1","docs/doc.txt",0);
        CHECK(doc.freq("teste") == 2);
        CHECK(doc.freq("1") == 1);
        CHECK(doc.freq("um") == 1);
        CHECK(doc.freq("guarda-chuva") == 0);
        CHECK(doc.freq("") == 0);
        CHECK(doc.freq("a") == 2);
    }
    TEST_CASE("doc1.txt:")
    {
        Documento doc("d2","docs/doc1.txt",0);
        CHECK(doc.freq("e") == 4);
        CHECK(doc.freq("da") == 1);
        CHECK(doc.freq("*/") == 0);
        CHECK(doc.freq("unidade") == 1);
        CHECK(doc.freq("no") == 2);
    }
}

TEST_CASE("Testando o método 'Set_coord':")
{
    vector<double> v1{1,0.5,-3.2,0.3,-3.7,0};
    vector<double> v2{1.9,2.3,-7.3,0.27,1.2,0.5};
    vector<double> v3{1,2,3,4};
    vector<double> v4,coord;
    Documento d1("Teste"),d2("ok"),d3("d1","docs/doc.txt",1),d4("d2","docs/d2.txt",2);
    d1.Set_coord(v1);
    d2.Set_coord(v2);
    d3.Set_coord(v3);
    d4.Set_coord(v2);
    CHECK(Teste::coord(d1) == v1);
    CHECK(Teste::coord(d2) == v2);
    CHECK(Teste::coord(d3) == v3);
    CHECK(Teste::coord(d4) == v2);
    d4.Set_coord(v1);
    CHECK(Teste::coord(d4) == v1);
    d1.Set_coord(v4);
    CHECK(Teste::coord(d1) == v4);
}

TEST_CASE("Testando o método 'coord':")
{
    vector<double> v1{1,0.5,-3.2,0.3,-3.7,0};
    vector<double> v2{1.9,2.3,-7.3,0.27,1.2,0.5};
    vector<double> v3{1,2,3,4};
    vector<double> v4,coord;
    Documento d1("Teste"),d2("ok"),d3("d1","docs/doc.txt",1),d4("d2","docs/d2.txt",2);
    d1.Set_coord(v1);
    d2.Set_coord(v2);
    d3.Set_coord(v3);
    d4.Set_coord(v2);
    coord = d1.coord();
    CHECK(coord == v1);
    coord = d2.coord();
    CHECK(coord == v2);
    coord = d3.coord();
    CHECK(coord == v3);
    coord = d4.coord();
    CHECK(coord == v2);
    d4.Set_coord(v1);
    coord = d4.coord();
    CHECK(coord == v1);
    d1.Set_coord(v4);
    coord = d1.coord();
    CHECK(coord == v4);
}

TEST_CASE("Testando o método 'tokens':")
{
    Documento d1("Mais um teste!"),d2("","docs/vazio.txt",0),d3("d1","docs/doc.txt",1),d4("d2","docs/doc1.txt",2);
    CHECK(d1.tokens() == Teste::tokens(d1));
    CHECK(d2.tokens() == Teste::tokens(d2));
    CHECK(d3.tokens() == Teste::tokens(d3));
    CHECK(d4.tokens() == Teste::tokens(d4));
}

TEST_SUITE("Testando o método 'Atualiza_doc':")
{
    TEST_CASE("Alterando documentos sem coordenadas atribuídas:")
    {
        Documento d1("d1","docs/doc1.txt",1),d2("d2","docs/doc3.txt",2);
        string att1 = "docs/d2.txt",att2 = "docs/doc.txt",nome_old,tok;
        int id_old;
        ifstream in;
        unordered_multiset<string> res,toks;
        nome_old = Teste::nome(d1);
        id_old = Teste::id(d1);
        in.open("docs/f3.txt");
        Teste::altera_arq(d1,att1);
        d1.Atualiza_doc();
        CHECK(Teste::nome(d1) == nome_old);
        CHECK(Teste::id(d1) == id_old);
        REQUIRE(Teste::arq_aberto(d1) == true);
        while(in >> tok)
        {
            res.insert(tok);
        }
        toks = Teste::tokens(d1);
        REQUIRE(toks.size() == res.size());
        CHECK(toks == res);
        CHECK(Teste::coord(d1).empty() == true);
        CHECK(Teste::coord(d1).size() == 0);
        in.close();
        res.clear();
        nome_old = Teste::nome(d2);
        id_old = Teste::id(d2);
        in.open("docs/f1.txt");
        Teste::altera_arq(d2,att2);
        d2.Atualiza_doc();
        CHECK(Teste::nome(d2) == nome_old);
        CHECK(Teste::id(d2) == id_old);
        REQUIRE(Teste::arq_aberto(d2) == true);
        while(in >> tok)
        {
            res.insert(tok);
        }
        toks = Teste::tokens(d2);
        REQUIRE(toks.size() == res.size());
        CHECK(toks == res);
        CHECK(Teste::coord(d2).empty() == true);
        CHECK(Teste::coord(d2).size() == 0);
        in.close();
    }
    TEST_CASE("Alterando documentos com coordenadas atribuídas:")
    {
        Documento d1("d1","docs/d2.txt",1),d2("d2","docs/doc.txt",2);
        vector<double> v1{1.2,0.6,-3.4,0},v2{0,0.5,-0.3,0.25};
        string att1 = "docs/doc3.txt",att2 = "docs/doc1.txt",nome_old,tok;
        int id_old;
        ifstream in;
        unordered_multiset<string> res,toks;
        nome_old = Teste::nome(d1);
        id_old = Teste::id(d1);
        in.open("docs/f4.txt");
        d1.Set_coord(v1);
        d2.Set_coord(v2);
        Teste::altera_arq(d1,att1);
        d1.Atualiza_doc();
        CHECK(Teste::nome(d1) == nome_old);
        CHECK(Teste::id(d1) == id_old);
        REQUIRE(Teste::arq_aberto(d1) == true);
        while(in >> tok)
        {
            res.insert(tok);
        }
        toks = Teste::tokens(d1);
        REQUIRE(toks.size() == res.size());
        CHECK(toks == res);
        CHECK(Teste::coord(d1).empty() == true);
        CHECK(Teste::coord(d1).size() == 0);
        in.close();
        res.clear();
        nome_old = Teste::nome(d2);
        id_old = Teste::id(d2);
        in.open("docs/f2.txt");
        Teste::altera_arq(d2,att2);
        d2.Atualiza_doc();
        CHECK(Teste::nome(d2) == nome_old);
        CHECK(Teste::id(d2) == id_old);
        REQUIRE(Teste::arq_aberto(d2) == true);
        while(in >> tok)
        {
            res.insert(tok);
        }
        toks = Teste::tokens(d2);
        REQUIRE(toks.size() == res.size());
        CHECK(Teste::coord(d2).empty() == true);
        CHECK(Teste::coord(d2).size() == 0);
        in.close();
    }
    TEST_CASE("Alterações com arquivos vazios:")
    {
        Documento d("d1","docs/doc.txt",1),vazio("","docs/vazio.txt",0);
        vector<double> v{1,2,3,4};
        string nome_old,tok;
        int id_old;
        ifstream in;
        unordered_multiset<string> res,toks;
        nome_old = Teste::nome(d);
        id_old = Teste::id(d);
        Teste::altera_arq(d,"docs/vazio.txt");
        d.Atualiza_doc();
        CHECK(Teste::nome(d) == nome_old);
        CHECK(Teste::id(d) == id_old);
        REQUIRE(Teste::arq_aberto(d) == true);
        toks = Teste::tokens(d);
        REQUIRE(toks.empty() == true);
        CHECK(toks.size() == 0);
        CHECK(Teste::coord(d).empty() == true);
        CHECK(Teste::coord(d).size() == 0);
        nome_old = Teste::nome(vazio);
        id_old = Teste::id(vazio);
        Teste::altera_arq(vazio,"docs/doc.txt");
        vazio.Atualiza_doc();
        in.open("docs/f1.txt");
        CHECK(Teste::nome(vazio) == nome_old);
        CHECK(Teste::id(vazio) == id_old);
        REQUIRE(Teste::arq_aberto(vazio) == true);
        while(in >> tok)
        {
            res.insert(tok);
        }
        toks = Teste::tokens(vazio);
        REQUIRE(toks.size() == res.size());
        CHECK(Teste::coord(vazio).empty() == true);
        CHECK(Teste::coord(vazio).size() == 0);
        in.close();
    }
}