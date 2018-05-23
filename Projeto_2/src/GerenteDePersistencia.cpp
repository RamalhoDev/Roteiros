#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
using namespace std;

list <Imovel> GerenteDePersistencia::recuperaListaImoveis(){
    list <Imovel> imoveis;
    ifstream arquivo;
    arquivo.open("imobiliaria.txt", ios::in);
    int  numero,tipoDeOferta,tipoDeImovel, tamanho;
    string logradouro, bairro, cidade, cep,auxiliar; 
    double valor;
    Imovel lerImovel;
    Endereco endereco;
    

    while(arquivo.good()){
        string descricao = "";
        
        getline(arquivo, bairro);
        getline(arquivo, cidade);
        getline(arquivo, cep);
        getline(arquivo, logradouro);
    
        arquivo >> numero;
        arquivo >> tipoDeOferta;
        arquivo >> tipoDeImovel;
        arquivo >> valor;

        while(1){
            getline(arquivo, auxiliar);
             if(!auxiliar.compare("-1"))
                break;
            descricao+= auxiliar+"\n";
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
    arquivo<< imovel->getDescricao();
    arquivo<< -1;
    arquivo<<"\n";
    arquivo.close();
}

