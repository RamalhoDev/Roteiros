#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <list>
#include "Imovel.h"

class GerenteDePersistencia{
    public:
        void recuperaListaImoveis();
        void salvaListaImoveis(list <Imovel> imovel);
};

#endif