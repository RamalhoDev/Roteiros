#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <list>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"

class GerenteDePersistencia{
    public:
        GerenteDePersistencia(){}
        ~GerenteDePersistencia(){}
        list <Imovel> recuperaListaImoveis();
        void salvaListaImoveis(Imovel *imovel);

};

#endif