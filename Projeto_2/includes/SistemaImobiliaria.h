#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <string>
#include <list>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
using namespace std;

class SistemaImobiliaria{ //Classe Sistema Imobiliaria, Onde são Criado as Listas e sublistas
    private:
        list <Imovel> imoveis;
    public:
        SistemaImobiliaria();
        ~SistemaImobiliaria();
        list <Imovel> getImoveis();
        list <Imovel> getImoveisPorTipoParaAlugar(int tipo);
        list <Imovel> getImoveisPorTipo(int tipo);
        list <Imovel> getImoveisParaAlugarPorBairro(string bairro);
        list <Imovel> getImoveisParaVenderPorBairro(string bairro);
        list <Imovel> getImoveisPorCidade(string cidade);
        
        //Cadastramento de cada tipo de Imovel usando ponteiros
        Casa* cadastrarCasa( Endereco endereco, int tipoDeImovel);              //Cadastramento de Casa
        Apartamento* cadastrarApartamento(Endereco endereco, int tipoDeImovel); //Cadastramento de Apartamento
        Terreno* cadastrarTerreno(Endereco endereco, int tipoDeImovel);         //Cadastramento de Terreno
        Flat* cadastrarFlat(Apartamento* apartamento);                          //Cadastramento de Flat
        Studio* cadastrarStudio(Flat *flat);                                    //Cadastramento de Studio
        bool ToUpper(string entrada, string atributo);                          //Compara
        Endereco cadastrarEndereco();                                           
};

#endif
