#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <list>
#include "Imovel.h"

class GerenteDePersistencia{
    public:
        GerenteDePersistencia(){}
        ~GerenteDePersistencia(){}
        list <Imovel> recuperaListaImoveis();
        void salvaListaImoveis(Imovel *imovel);

};

#endif