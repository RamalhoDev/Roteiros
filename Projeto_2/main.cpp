#include <iostream>
#include <string>
#include "Imovel.h"
#include "SistemaImobiliaria.h"
#include "GerenteDePersistencia.h"
using namespace std;

int main(){
    GerenteDePersistencia x;
    x.recuperaListaImoveis();

    return 0;
}