#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <list>
#include "/home/aluno/Documentos/Projeto2/Roteiros/Projeto_2/includes/Imovel.h"

class GerenteDePersistencia{
    public:
        GerenteDePersistencia(){}
        ~GerenteDePersistencia(){}
        list <Imovel> recuperaListaImoveis();
        void salvaListaImoveis(Imovel *imovel);

};

#endif