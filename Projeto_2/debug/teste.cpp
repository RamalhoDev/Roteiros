#include <iostream>
#include <string>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
using namespace std;

int main(){
    Endereco endereco = Endereco("Said abel", "treze de maio", "joao pessoa", "58025380", 37);
    // Casa casa =  Casa(5, 3, 200.5, 100.5, 1, 12600, endereco);
    // Terreno *terreno = new Terreno(200, 1, 300000, endereco);
    // Apartamento *apartamento = new Apartamento("nascente sul", 4, 2, 250, 100, 1, 1000, endereco);
     GerenteDePersistencia x;
    
    Imovel *imovel = new Imovel(1, 1000, endereco);
    x.salvaListaImoveis(imovel);
    imovel->~Imovel();
    Imovel imoveis = x.recuperaListaImoveis();
    cout << imoveis.getValor()<< endl;
    imoveis.~Imovel();
    
    return 0;
}