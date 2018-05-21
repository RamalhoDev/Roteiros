#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"

using namespace std;

list <Imovel> GerenteDePersistencia::recuperaListaImoveis(){
    list <Imovel> imoveis;
    SistemaImobiliaria imobiliaria;
    ifstream arquivo;
    arquivo.open("imobiliaria.txt", ios::in);
    int tipoImovel;
    while(!arquivo.eof()){
        arquivo >> tipoImovel;
        if(tipoImovel == 1){
            Casa casa;
            casa = imobiliaria.lerCasaDoArquivo(arquivo);
            imoveis.push_back(casa);
            casa.~Casa();
        }else if(tipoImovel==2){
            Apartamento apartamento;
            apartamento = imobiliaria.lerApartamentoDoArquivo(arquivo);
            imoveis.push_back(apartamento);
            apartamento.~Apartamento();
        }else if(tipoImovel == 3){
            Terreno terreno;
            terreno = imobiliaria.lerTerrenoDoArquivo(arquivo);
            imoveis.push_back(terreno);
            terreno.~Terreno();
        }
    }
    arquivo.close();
    return imoveis;
}

void GerenteDePersistencia::salvaListaImoveis(Imovel *imovel){
    ofstream arquivo;
    arquivo.open("imobiliaria.txt",ios::app);
    imovel->escreveNoArquivo(arquivo);
    arquivo.close();
}

