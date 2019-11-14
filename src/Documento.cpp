#include "Documento.h"

Documento::Documento(string doc,string dir){

}
unordered_multiset<string>& Documento::tokens(){
    return tokens_;
}

int Documento::freq(string P){
    return tokens_.count(P);
}
string Documento::nome(){
    return nome_;
}
void Documento::set_coord(vector<double> &V) {
    coord_ = V;
}