#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <string>
#include <list>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
using namespace std;

class SistemaImobiliaria{
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
        Casa* cadastrarCasa( Endereco endereco, int tipoDeImovel);
        Apartamento* cadastrarApartamento(Endereco endereco, int tipoDeImovel);
        Terreno* cadastrarTerreno(Endereco endereco, int tipoDeImovel);
        Flat* cadastrarFlat(Apartamento* apartamento);
        Studio* cadastrarStudio(Flat *flat);
        bool ToUpper(string entrada, string atributo);
        Endereco cadastrarEndereco();
};

#endif