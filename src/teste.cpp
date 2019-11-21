#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include "Documento.h"
#include "Busca.h"
#include <math.h>
using namespace std;

int main(){
    Documento um ("", "C:/Users/leone/Desktop/Codigos/PDS2/TP-PDS2/bin/docs/doc7.txt", 0);
    Documento dois ("", "C:/Users/leone/Desktop/Codigos/PDS2/TP-PDS2/bin/docs/doc8.txt", 1);
    Documento tres ("", "C:/Users/leone/Desktop/Codigos/PDS2/TP-PDS2/bin/docs/doc6.txt", 2);
    vector <Documento> DOCS;
    DOCS.push_back(um);
    DOCS.push_back(dois);
    DOCS.push_back(tres);
    MBus teste (DOCS);

    Documento c ("programacao quero teste teste novo");
    cout << "oi" << endl;
    vector <int> con = teste.consulta(c);
    for (auto &i : con){
        cout << i << endl;
    }

    return 0;
}