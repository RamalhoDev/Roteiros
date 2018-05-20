#ifndef SISTEMAIMOBILIARIA_H
#define SISTEMAIMOBILIARIA_H
#include <string>
#include "Imovel.h"
#include <list>
using namespace std;

class SistemaImobiliaria{
    private:
        list <Imovel> imoveis;
    public:
        SistemaImobiliaria();
        virtual ~SistemaImobiliaria();
        void cadastraImovel(Imovel imovel);
        list <Imovel> getImoveis();
        string getDescricaoImoveis();
        list <Imovel> getImoveisPorTipo(int tipo);
        list <Imovel> getImoveisParaAlugarPorBairro(string bairro);
        list <Imovel> getImoveisParaVenderPorBairro(string bairro);
        list <Imovel> getImoveisPorCidade(string cidade);
};

#endif