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
        string getImoveis();
        string getDescricaoImoveis();
        Imovel getImoveisPorTipo(int tipo);
        Imovel getImoveisParaAlugarPorBairro(string bairro);
        Imovel getImoveisParaVenderPorBairro(string bairro);
        Imovel getImoveisPorCidade(string cidade);
};

#endif