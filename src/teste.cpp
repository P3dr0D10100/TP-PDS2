#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

int main(){
    map<string,set<int>> indice_teste {
            make_pair("este", set<int> {0,1}),
            make_pair("e", set<int> {0,1}),
            make_pair("um", set<int> {0,1}),
            make_pair("documento", set<int> {0}),
            make_pair("teste", set<int> {0,1}),
            make_pair("de", set<int> {0}),
            make_pair("com", set<int> {0,1}),
            make_pair("dez", set<int> {0}),
            make_pair("palavras", set<int> {0,1}),
            make_pair("ok", set<int> {0}),
        
    };

    for (auto &m : indice_teste){
        cout << m.first << endl;
    }

    return 0;
}