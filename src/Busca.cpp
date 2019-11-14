#include "Busca.h"
#include <math.h>
#include <algorithm>

MBus::MBus(std::vector<Documento> &doc){
    N_docs_ = doc.size();
    docs_ = doc;
    calcula_id_inv();
} 

void MBus::calcula_id_inv(){
    for (int i=0; i<docs_.size(); i++){
        for (auto &t : docs_[i].tokens()){
            id_inv_[t].insert(i);
        }
    }
}

void MBus::calcula_coord(){
    for (auto &d : docs_){
        vector <double> W;
        for (auto &t : id_inv_){
            W.push_back( log(N_docs_ / t.second.size()) * d.freq(t.first)); 
        }
        d.set_coord(W);
    }
}

vector <string> MBus::consulta(string Q){
    //primeiro separar a string Q em tokens: unordered_multiset <string> Qtolkens
    unordered_multiset <string> Qtokens;
    vector <double> QW;
    for (auto &t : id_inv_){
        QW.push_back( log(N_docs_ / t.second.size()) * Qtokens.count(t.first));
    }
    vector <double> dist_Q_docs;
    for (int i=0; i<docs_.size(); i++){
        //calcular distância de Q até docs[i]
    }
    sort (dist_Q_docs.rbegin(), dist_Q_docs.rend());
   
}

void MBus::inserir_doc(Documento doc){
    docs_.push_back(doc);
    N_docs_++;
    for (auto &t : doc.tokens()){
        id_inv_[t].insert(N_docs_-1);
    }
    calcula_coord();
}

void MBus::remover_doc(string Doc){

}
