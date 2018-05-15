#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include "Imovel.h"

class GerenteDePersistencia{
    public:
        Imovel recuperaListaImoveis();
        void salvaListaImoveis(Imovel imovel);
};

#endif