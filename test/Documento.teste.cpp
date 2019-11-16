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
        static void fechar_arq(Documento& doc)
        {
            doc.arquivo_.close();
        }
};
