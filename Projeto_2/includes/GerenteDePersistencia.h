#ifndef GERENTEDEPERSISTENCIA_H
#define GERENTEDEPERSISTENCIA_H
#include <list>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"

class GerenteDePersistencia{
    
    //Escreve no arquivo
    public:
        GerenteDePersistencia(){}
        ~GerenteDePersistencia(){}
        list <Imovel> recuperaListaImoveis();
    
        //Salva a lista após alguma modificação
        void salvaListaImoveis(Imovel *imovel);

};

#endif
