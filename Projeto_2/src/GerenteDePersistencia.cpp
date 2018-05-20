#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include "Imovel.h"
#include "GerenteDePersistencia.h"

using namespace std;

void GerenteDePersistencia::recuperaListaImoveis(){
    string logradouro, bairro, cidade, cep;
    int numero;
    list <Imovel> imoveis;
    Imovel lerImovel;
    Endereco endereco;
    ifstream arquivo("imobiliaria.bin", ios::in | ios::binary | ios::ate);
    
    if(!arquivo.is_open()){
        cout << "There is something wrong with the file." << endl;
    }

    while(!arquivo.eof()){
        int size = sizeof(Imovel);
        getline(arquivo, logradouro);
        getline(arquivo , bairro);
        getline(arquivo, cidade);
        getline(arquivo, cep);
        arquivo >> numero;
        endereco = Endereco(logradouro, bairro, cidade, cep, numero);

        lerImovel= Imovel(2, 250.9, endereco);
        imoveis.push_back(lerImovel);
    }
    arquivo.close();
}
void GerenteDePersistencia::salvaListaImoveis(list <Imovel> imovel){

}