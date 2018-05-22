#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
using namespace std;

list <Imovel> GerenteDePersistencia::recuperaListaImoveis(){
    list <Imovel> imoveis;
    ifstream arquivo;
    arquivo.open("imobiliaria.txt", ios::in);

    while(!arquivo.eof()){
        string logradouro, bairro, cidade, cep, descricao = "", auxiliar;
        int  numero,tipoDeOferta,tipoDeImovel;
        double valor;
        
        Imovel lerImovel;
        Endereco endereco;
        
        getline(arquivo, logradouro);
        getline(arquivo, bairro);
        getline(arquivo, cidade);
        getline(arquivo, cep);
        arquivo >> numero;
        arquivo >> tipoDeOferta;
        arquivo >> tipoDeImovel;
        arquivo >> valor;
        
        for(int i = 0; i<8; i++){
           getline(arquivo, auxiliar);
           descricao+=auxiliar+"\n";
        }

        endereco = Endereco(logradouro, bairro, cidade, cep, numero);
        lerImovel = Imovel(tipoDeImovel,tipoDeOferta,valor,endereco, descricao);
        
        imoveis.push_back(lerImovel);
    }

    arquivo.close();
    return imoveis;
}

void GerenteDePersistencia::salvaListaImoveis(Imovel *imovel){
    ofstream arquivo;
    arquivo.open("imobiliaria.txt",ios::app);

    arquivo << imovel->getEndereco().getBairro();
    arquivo <<"\n";
    arquivo << imovel->getEndereco().getCidade();
    arquivo <<"\n";
    arquivo << imovel->getEndereco().getCep();
    arquivo <<"\n";
    arquivo << imovel->getEndereco().getLogradouro();
    arquivo <<"\n";
    arquivo << imovel->getEndereco().getNumero();
    arquivo <<"\n";
    arquivo<< imovel->getTipoOferta();
    arquivo<<"\n";
    arquivo<< imovel->getTipoDeImovel();
    arquivo<<"\n";
    arquivo<< imovel->getValor();
    arquivo<<"\n";
    arquivo << imovel->getDescricao();
    
    arquivo.close();
}

