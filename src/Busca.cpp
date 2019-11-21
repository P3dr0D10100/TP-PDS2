#include "Busca.h"
#include <math.h>
#include <utility>
#include <algorithm>

MBus::MBus(std::vector<Documento> &doc){
    N_docs_ = doc.size();
    docs_ = doc;
    calcula_id_inv();
    calcula_coord();
} 

void MBus::calcula_id_inv(){
    for (int i=0; i<docs_.size(); i++){
        for (auto &t : docs_[i].tokens()){
            id_inv_[t].insert(docs_[i].id());
        }
    }
}

void MBus::calcula_coord(){
    for (auto &d : docs_){
        vector <double> W;
        for (auto &t : id_inv_){
            W.push_back( log(N_docs_ / t.second.size()) * d.freq(t.first)); 
        }
        d.Set_coord(W);
    }
}

vector <int> MBus::consulta(Documento &Q){
    Q.tokens();
    vector <double> QW;
    for (auto &t : id_inv_){
        QW.push_back( log(N_docs_ / t.second.size()) * Q.tokens().count(t.first));
    }
    vector <std::pair<long double,int>> dist_Q_docs;
    for (int i=0; i<docs_.size(); i++){
        long double soma_coord = 0, soma_q = 0, soma_doc = 0;
        for (int j=0; j<Q.coord.size(); j++){
            soma_coord += Q.coord[j] * docs_[i].coord[j];
            soma_q += Q.coord[j] * Q.coord[j];
            soma_doc += docs_[i].coord[j] * docs_[i].coord[j];
        }
        dist_Q_docs[i] = std::make_pair( soma_coord / (sqrt(soma_q) * sqrt(soma_doc)) , i);
        //calcular distância de Q até docs[i]
    }
    sort (dist_Q_docs.rbegin(), dist_Q_docs.rend());
   
   vector <int> docs_sorted;
   for (auto &i : dist_Q_docs){
       docs_sorted.push_back(i.second);
   }
   return docs_sorted;
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
    bool achou = false;
    for (int i=0; i<docs_.size(); i++){
        if (docs_[i].nome() == Doc){
            N_docs_--;
            docs_.erase(docs_.begin()+i);
            achou = true;
            calcula_id_inv();
            calcula_coord();
        }
    }
    if (achou == false){
        // mensagem de erro ou alguma coisa
    }
    
}

void MBus::att_doc(){
    calcula_id_inv();
    calcula_coord();
}