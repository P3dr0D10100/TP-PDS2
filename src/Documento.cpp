#include "Documento.h"
#include <cctype>
#include <assert.h>

Documento::Documento(string doc,string dir,int id)
{
    string lin,tok;
    int i;
    nome_ = doc;
    dir_ = dir;
    arquivo_.open(dir_);
    assert(arquivo_.is_open());
    while(std::getline(arquivo_,lin))
    {
        tok.reserve(lin.size());
        for(i = 0; i <= lin.size(); i++)
        {
            if(lin[i] == ' ' || lin[i] == '\0')
            {
                tok.shrink_to_fit();
                tokens_.insert(tok);
                tok.clear();
                tok.reserve(lin.size() - i);
            }else 
            if(isalnum(lin[i]))
            {
                tok.push_back(tolower(lin[i]));
            }
        }
        tok.clear();
    }
    id_ = id;
}

Documento::~Documento()
{
    arquivo_.close();
}