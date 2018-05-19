#include <iostream>
#include <string>
#include "Imovel.h"
 #include "SistemaImobiliaria.h"
using namespace std;

SistemaImobiliaria:: SistemaImobiliaria();
SistemaImobiliaria:: ~SistemaImobiliaria();

void SistemaImobiliaria:: cadastraImovel(Imovel imovel){
    return imovel;
}

string SistemaImobiliaria:: getImoveis(){

}

string SistemaImobiliaria:: getDescricaoImoveis(){

}

Imovel SistemaImobiliaria:: getImoveisPorTipo(int tipo){
    return tipo;
}

Imovel SistemaImobiliaria:: getImoveisParaAlugarPorBairro(string bairro){
    return bairro;
}
Imovel SistemaImobiliaria:: getImoveisParaVenderPorBairro(string bairro){
    return bairro
}
Imovel SistemaImobiliaria:: getImoveisPorCidade(string cidade){
    return cidade;
}
