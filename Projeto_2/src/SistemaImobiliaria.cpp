#include <iostream>
#include <string>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"	//"SistemaImobiliaria.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"	//"GerenteDePersistencia.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"			//"Imovel.h"

using namespace std;

SistemaImobiliaria::SistemaImobiliaria(){} //Construtor de Sistema Imobiliaria
SistemaImobiliaria::~SistemaImobiliaria(){}

list <Imovel> SistemaImobiliaria:: getImoveis(){	//Lendo as Listas referentes a Sistema Imobiliaria

    GerenteDePersistencia recupera;
    list<Imovel> imovel = recupera.recuperaListaImoveis();
    return imovel;

}

list <Imovel> SistemaImobiliaria:: getImoveisPorTipo(int tipo){		//Lendo as Listas referentes a Imoveis por Tipo

    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;

    for(Imovel &i : imovel){
        if(i.getTipoDeImovel() == tipo){
            imoveis.push_back(i);
        }
    }

    return imoveis;
}

list <Imovel> SistemaImobiliaria::getImoveisPorTipoParaAlugar(int tipo){	//Lendo as Listas referentes a Imovel para alugar

    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;

    for(Imovel &i : imovel){
        if(i.getTipoDeImovel() == tipo && i.getTipoOferta() == 0){
            imoveis.push_back(i);
        }
    }

    return imoveis;
}
        
list <Imovel> SistemaImobiliaria:: getImoveisParaAlugarPorBairro(string bairro){	//Lendo as Listas referentes a Imovel para alugar por Bairro
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;

    for(Imovel &i : imovel){

        if( ToUpper(bairro,i.getEndereco().getBairro()) && i.getTipoOferta() == 0){
            imoveis.push_back(i);
        }

    }

    return imoveis;
}

list <Imovel> SistemaImobiliaria:: getImoveisParaVenderPorBairro(string bairro){	//Lendo as Listas referentes a Imovel para vender por Bairro
 
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;
 
    for(Imovel &i : imovel){

        if(ToUpper(bairro,i.getEndereco().getBairro()) && i.getTipoOferta() == 1){
            imoveis.push_back(i);
        }
 
    }
 
    return imoveis;
}

list<Imovel> SistemaImobiliaria:: getImoveisPorCidade(string cidade){	//Lendo as Listas referentes a Imovel por Cidades
 
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;

    for(Imovel &i: imovel){
 
        cout << i.getEndereco().getCidade()<< endl;
 
        if(ToUpper(cidade,i.getEndereco().getCidade())){
            imoveis.push_back(i);
        }
 
    }

    return imoveis;
}

Endereco SistemaImobiliaria::cadastrarEndereco(){	//Cadastramento de endereços dos Imoveis em geral

            string cidade, bairro, logradouro, cep;
            int numero;
            
			cout<< "-------------------------------------\n";
			cout <<"\t\t\tEndereço\n";
			cout<< "-------------------------------------\n\n";

			cout<< "Digite seu Logradouro: ";
            getline(cin,logradouro);
            
			cout<< "\nDigite seu Bairro: ";
            getline(cin, bairro);

			cout<< "\nDigite sua Cidade: ";
			getline(cin, cidade);

			cout<< "\nDigite seu CEP: ";
			getline(cin, cep);

			cout<< "\nDigite o numero do imovel: ";
			cin>>numero;
            getchar();
            Endereco *endereco = new Endereco(logradouro, bairro, cidade, cep, numero);
            
            return *endereco;
}

Casa* SistemaImobiliaria::cadastrarCasa(Endereco endereco, int tipoDeImovel){	//Cadastramento das informações especificas de uma Casa

            Casa *casa;
            int numPavimentos, numQuartos, tipoOferta;
            double areaTerreno, areaConstruida, valor;

			cout << "-------------------------------------\n";
			cout << "\t\tEspecificações\n";
			cout << "-------------------------------------\n\n";

            cout << "\n Digite a quantidade o número de pavimentos da casa: ";
            cin >> numPavimentos;

            cout << "\n Digite a quantidade o número quartos da casa: ";
            cin >> numQuartos;

            cout << "\n Digite a área total da casa: ";
            cin >> areaTerreno;

            cout << "\n Digite a área construida da casa: ";
            cin >> areaConstruida;

			cout<< "\n-------------------------------------\n"
			    <<"\t\tValor\n"
			    <<"-------------------------------------\n\n";

            cout << "Deseja alugar ou vender seu imovel ?\n"
                 << "\t1 - Vender,\n"
                 << "\t0 - Alugar.\n";
            cin >> tipoOferta;
			cout<<"Qual o valor do seu imovel?\n";
            cin >> valor;

            casa = new Casa(numPavimentos,numQuartos, areaTerreno, areaConstruida,tipoOferta, tipoDeImovel, valor, endereco);
            getchar();
            
            cout<<"\n\nImovel Cadastrado Com Sucesso!\n";
            return casa;
}

Apartamento* SistemaImobiliaria::cadastrarApartamento(Endereco endereco, int tipoDeImovel){	//Cadastramento das informações especificas de um Apartamento

    int numQuartos, vagasGaragem, tipoOferta;
    double area, valor, valorCondominio;
    string posicao;
    Apartamento *apartamento;

    cout << "-------------------------------------\n";
    cout << "\t\tEspecificações\n";
    cout << "-------------------------------------\n\n";

    cout<<"\nDigite a quantidade o número quartos do apartamento: ";
    cin>> numQuartos;

    cout<<"\nDigite a quantidade de vagas na garagem disponiveis para o seu apartamento: ";
    cin>>vagasGaragem;

    cout<<"\nDigite o valor do condomínio: ";
    cin>>valorCondominio;

    cout<<"\nDigite a area do apartamento: ";
    cin>>area;
    getchar();
    
    cout << "\nDigite a posicao do seu apartamento: ";
    getline(cin, posicao);

    cout<< "\n-------------------------------------\n"
        <<"\t\tValor\n"
        <<"-------------------------------------\n\n";
    
    cout << "Deseja vender ou alugar seu imovel ?\n"
         << "\t1 - Vender,\n"
         << "\t0 - Aluga.\n";
    cin >> tipoOferta;     
    
    cout << "Qual o valor do seu imovel?\n";
    cin >> valor;
    getchar();
    
    apartamento = new Apartamento(posicao, numQuartos, vagasGaragem, valorCondominio, area, tipoOferta, tipoDeImovel, valor, endereco);
    
    cout <<"\n\nImovel Cadastrado Com Sucesso!\n";
    return apartamento;
}

Terreno* SistemaImobiliaria::cadastrarTerreno(Endereco endereco, int tipoDeImovel){	//Cadastramento das informações especificas de um Terreno

    double area, valor;
    int tipoOferta;
    Terreno *terreno;

    cout << "-------------------------------------\n";
    cout << "\t\tEspecificações\n";
    cout << "-------------------------------------\n\n";
    
    cout << "Deseja vender ou alugar seu imovel ?\n"
        << "\t1 - Vender,\n"
        << "\t0 - Aluga.\n";
    cin >> tipoOferta;    

    cout<<"Digite a área do seu terreno: "<<endl;
    cin >> area;

    cout<< "\n-------------------------------------\n"
        <<"\t\tValor\n"
        <<"-------------------------------------\n\n"
        <<"Qual o valor do seu imovel?\n";
    cin >> valor;
    
    cout<<"\n\nImovel Cadastrado Com Sucesso!\n";
    terreno = new Terreno(area,tipoOferta, tipoDeImovel, valor,endereco);
    getchar();

    return terreno;
}

bool SistemaImobiliaria::ToUpper(string entrada, string atributo){

	string saidaUsuario;
	
    for(int i = 0; i  < entrada.size(); i++){
		if(toupper(entrada[i]) == toupper(atributo[i]))
            continue;
        return false; 
    }

	return true;
}


Flat* SistemaImobiliaria::cadastrarFlat(Apartamento *apartamento){	//Cadastramento das informações especificas de um Flat
    
    string ar, internet, tv, lavanderia, limpeza, recepcao;
    
    cout << "-------------------------------------\n";
    cout << "\t\tEspecificações\n";
    cout << "-------------------------------------\n\n";
    cout << "\n\tPossui ar-condicionado ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> ar;

    cout << "\n\tPossui lavanderia ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> lavanderia;

    cout << "\n\tPossui limpeza ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> limpeza;

    cout << "\n\tPossui TV a cabo ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> tv;  

    cout << "\n\tPossui Internet ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> internet;  

    cout << "\n\tPossui recepcao ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> recepcao;  
    
    Flat* flat = new Flat(ar, 
                          internet, 
                          tv, 
                          lavanderia, 
                          limpeza, 
                          recepcao, 
                          apartamento->getPosicao(),
                          apartamento->getNumQuartos(), 
                          apartamento->getVagasGaragem(),
                          apartamento->getValorCondominio(),
                          apartamento->getArea(),
                          apartamento->getTipoOferta(),
                          apartamento->getTipoDeImovel(),
                          apartamento->getValor(),
                          apartamento->getEndereco());
    return flat;
}

Studio* SistemaImobiliaria::cadastrarStudio( Flat *flat){	//Cadastramento das informações especificas de um Studio
    
    string piscina, sauna, ginastica;
    cout << "-------------------------------------\n";
    cout << "\t\tEspecificações\n";
    cout << "-------------------------------------\n\n";
    cout << "\n\tPossui Sauna ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> sauna;

    cout << "\n\tPossui Piscina ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> piscina;

    cout << "\n\tPossui salão de Ginastica ?\n"
         << "Insira S para Sim ou N para Nao: ";
    cin  >> ginastica;
    
    Studio* studio = new Studio(piscina,
                          sauna,
                          ginastica,
                          flat->getAr(), 
                          flat->getInternet(), 
                          flat->getTv(), 
                          flat->getLavanderia(), 
                          flat->getLimpeza(), 
                          flat->getRecepcao(), 
                          flat->getPosicao(),
                          flat->getNumQuartos(), 
                          flat->getVagasGaragem(),
                          flat->getValorCondominio(),
                          flat->getArea(),
                          flat->getTipoOferta(),
                          flat->getTipoDeImovel(),
                          flat->getValor(),
                          flat->getEndereco());
    return studio;
}
