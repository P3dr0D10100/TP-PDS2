#include "Documento.h"
#include <cctype>
#include <exception>
#include <assert.h>

Documento::Documento(string doc,string dir,int id)
{
    string lin,tok;
    int i;
    nome_ = doc;
    dir_ = dir;
    arquivo_.open(dir_);
    if(!arquivo_.is_open())
    {
        throw std::invalid_argument("Nome de arquivo ou diretório inválido.");
    }
    assert(arquivo_.is_open());
    while(std::getline(arquivo_,lin))
    {
        tok.reserve(lin.size());
        for(i = 0; i <= lin.size(); i++)
        {
            if(lin[i] == ' ' || lin[i] == '\0')
            {
                tok.shrink_to_fit();
                if(tok != "")
                {
                    tokens_.insert(tok);
                    tok.clear();
                    tok.reserve(lin.size() - i);
                }else
                {
                    tok.clear();
                    tok.reserve(lin.size() - i);
                }
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

Documento::Documento(string str)
{
    string tok;
    int i;
    nome_ = "Query";
    dir_ = "";
    id_ = -1;
    tok.reserve(str.size());
    for(i = 0; i < str.size() + 1; i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            tok.shrink_to_fit();
            if(tok != "")
            {
                tokens_.insert(tok);
                tok.clear();
                tok.reserve(str.size() - i);
            }else
            {
                tok.clear();
                tok.reserve(str.size() + 1);
            }
        }else
        if(isalnum(str[i]))
        {
            tok.push_back(tolower(str[i]));
        }
    }
}

Documento::Documento(const Documento& doc)
{
    this->nome_ = doc.nome_;
    this->dir_ = doc.dir_;
    this->id_ = doc.id_;
    this->tokens_ = doc.tokens_;
    this->coord_ = doc.coord_;
}

string Documento::nome()
{
    return this->nome_;
}

int Documento::id()
{
    return this->id_;
}

int Documento::freq(string p)
{
    return tokens_.count(p);
}

void Documento::Set_coord(vector<double>& V)
{
    coord_ = V;
}

vector<double> Documento::coord()
{
    return coord_;
}

unordered_multiset<string>& Documento::tokens() 
{
    return tokens_;
}

void Documento::Atualiza_doc()
{
    string lin,tok;
    int i;
    tokens_.clear();
    coord_.clear();
    arquivo_.close();
    arquivo_.open(dir_);
    if(!arquivo_.is_open())
    {
        throw std::runtime_error("Erro ao acessar o arquivo!");
    }
    while(std::getline(arquivo_,lin))
    {
        tok.reserve(lin.size());
        for(i = 0; i <= lin.size(); i++)
        {
            if(lin[i] == ' ' || lin[i] == '\0')
            {
                tok.shrink_to_fit();
                if(tok != "")
                {
                    tokens_.insert(tok);
                    tok.clear();
                    tok.reserve(lin.size() - i);
                }else
                {
                    tok.clear();
                    tok.reserve(lin.size() - i);
                }
            }else 
            if(isalnum(lin[i]))
            {
                tok.push_back(tolower(lin[i]));
            }
        }
        tok.clear();
    }
}

void Documento::operator=(const Documento& doc)
{
    this->nome_ = doc.nome_;
    this->dir_ = doc.dir_;
    this->id_ = doc.id_;
    this->tokens_ = doc.tokens_;
    this->coord_ = doc.coord_;
}

Documento::~Documento()
{
    arquivo_.close();
}