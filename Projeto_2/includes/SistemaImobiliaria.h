#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <string>
#include <list>
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/Imovel.h"
using namespace std;

class SistemaImobiliaria{
    private:
        list <Imovel> imoveis;
    public:
        SistemaImobiliaria();
        ~SistemaImobiliaria();
        list <Imovel> getImoveis();
        list <string> getDescricaoImoveis();
        list <Imovel> getImoveisPorTipo(int tipo);
        list <Imovel> getImoveisParaAlugarPorBairro(string bairro);
        list <Imovel> getImoveisParaVenderPorBairro(string bairro);
        list <Imovel> getImoveisPorCidade(string cidade);
        Casa* cadastrarCasa( Endereco endereco, int tipoDeImovel);
        Apartamento* cadastrarApartamento(Endereco endereco, int tipoDeImovel);
        Terreno* cadastrarTerreno(Endereco endereco, int tipoDeImovel);
        string ToUpper(string entrada);
        Endereco cadastrarEndereco();
};

#endif