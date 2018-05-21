#include <iostream>
#include <string>
#include "/home/aluno/Documentos/Projeto2/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
#include "/home/aluno/Documentos/Projeto2/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"
#include "/home/aluno/Documentos/Projeto2/Roteiros/Projeto_2/includes/Imovel.h"

using namespace std;

SistemaImobiliaria::SistemaImobiliaria(){}
SistemaImobiliaria::~SistemaImobiliaria(){}

list <Imovel> SistemaImobiliaria:: getImoveis(){
    GerenteDePersistencia recupera;
    list<Imovel> imovel = recupera.recuperaListaImoveis();
    return imovel;
}

list <string> SistemaImobiliaria:: getDescricaoImoveis(){
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <string> descricao;
    for(Imovel &i : imovel){
        descricao.push_back(i.getDescricao());
    }
    return descricao;
}

list <Imovel> SistemaImobiliaria:: getImoveisPorTipo(int tipo){
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;
    for(Imovel &i : imovel){
        if(i.getTipoDeImovel() == tipo){
            i.getTipoDeImovel();
            imoveis.push_back(i);
        }
        i.~Imovel();
    }

    return imoveis;
}

list <Imovel> SistemaImobiliaria:: getImoveisParaAlugarPorBairro(string bairro){
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;
    for(Imovel &i : imovel){
        if(i.getEndereco().getBairro() == bairro && i.getTipoOferta() == 0){
            imoveis.push_back(i);
        }
        i.~Imovel();
    }
    return imoveis;
}

list <Imovel> SistemaImobiliaria:: getImoveisParaVenderPorBairro(string bairro){
   GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;
    for(Imovel &i : imovel){
        if(i.getEndereco().getBairro() == bairro && i.getTipoOferta() == 1){
            imoveis.push_back(i);
        }
        i.~Imovel();
    }
    return imoveis;
}
list<Imovel> SistemaImobiliaria:: getImoveisPorCidade(string cidade){
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;
    for(Imovel &i: imovel){
        if(i.getEndereco().getCidade() == cidade){
            imoveis.push_back(i);
        }
        i.~Imovel();
    }
    return imoveis;
}

Endereco SistemaImobiliaria::cadastrarEndereco(){

            string cidade, bairro, logradouro, cep;
            int numero;
            
			cout<< "-------------------------------------\n\n";
			cout <<"                 Endereço \n";
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

Casa* SistemaImobiliaria::cadastrarCasa(Endereco endereco, int tipoDeImovel){

            Casa *casa;
            int numPavimentos, numQuartos, areaTerreno, areaConstruida, valor, tipoOferta;
			cout << "-------------------------------------\n\n";
			cout << "            Especificações \n";
			cout << "-------------------------------------\n\n";

            cout << "\n Digite a quantidade o número de pavimentos da casa: ";
            cin >> numPavimentos;

            cout << "\n Digite a quantidade o número quartos da casa: ";
            cin >> numQuartos;

            cout << "\n Digite a área total da casa: ";
            cin >> areaTerreno;

            cout << "\n Digite a área construida da casa: ";
            cin >> areaConstruida;

			cout<< "\n-------------------------------------\n\n"
			    <<"                 Valor \n"
			    <<"-------------------------------------\n\n";

            cout << "Deseja alugar ou vender seu imovel ?\n"
                 << "0 - Vender,\n"
                 << "1 - Alugar.\n";
            cin >> tipoOferta;
			cout<<"Qual o valor do seu imovel?\n";
			
            cin >> valor;
            casa = new Casa(numPavimentos,numQuartos, areaTerreno, areaConstruida,tipoOferta, tipoDeImovel, valor, endereco);
            getchar();
            
            cout<<"\n\nImovel Cadastrado Com Sucesso!\n";
            return casa;
}

Apartamento* SistemaImobiliaria::cadastrarApartamento(Endereco endereco, int tipoDeImovel){
    int numQuartos, vagasGaragem, valorCondominio, area, valor, tipoOferta;
    string posicao;
    Apartamento *apartamento;
    cout << "-------------------------------------\n\n";
    cout << "            Especificações \n";
    cout << "-------------------------------------\n\n";

    cout<<"\n Digite a quantidade o número quartos do apartamento: ";
    cin>> numQuartos;
    cout<<"\n Digite a quantidade de vagas na garagem disponiveis para o seu apartamento: ";
    cin>>vagasGaragem;

    cout<<"\n Digite o valor do condomínio: ";
    cin>>valorCondominio;

    cout<<"\n Digite a área do seu apartamento ";
    cin>>area;
    
    getchar();

    cout<<"\n Digite a posição do seu apartamento: ";
    getline(cin, posicao);

    cout<< "\n-------------------------------------\n\n"
        <<"                 Valor \n"
        <<"-------------------------------------\n\n";
    
    cout << "Deseja vender ou alugar seu imovel ?\n"
         << "0 - Vender,\n"
         << "1 - Aluga.\n";
    cin >> tipoOferta;     
    cout << "Qual o valor do seu imovel?\n";
    
    cin >> valor;
    getchar();
    cout<<"\n\nImovel Cadastrado Com Sucesso!\n";
    apartamento = new Apartamento(posicao, numQuartos, vagasGaragem, valorCondominio,area,tipoOferta,tipoDeImovel,valor,endereco);
    return apartamento;
}


Terreno* SistemaImobiliaria::cadastrarTerreno(Endereco endereco, int tipoDeImovel){
    int area, valor, tipoOferta;
    Terreno *terreno;
    cout << "-------------------------------------\n\n";
    cout << "            Especificações \n";
    cout << "-------------------------------------\n\n";
    
    cout << "Deseja vender ou alugar seu imovel ?\n"
        << "0 - Vender,\n"
        << "1 - Aluga.\n";
    cin >> tipoOferta;    

    cout<<"Digite a área do seu terreno: "<<endl;
    cin >> area;

    cout<< "\n-------------------------------------\n\n"
        <<"                 Valor \n"
        <<"-------------------------------------\n\n"

        <<"Qual o valor do seu imovel?\n";
    
    cin >> valor;
    
    cout<<"\n\nImovel Cadastrado Com Sucesso!\n";
    terreno = new Terreno(area,tipoOferta, tipoDeImovel, valor,endereco);
    getchar();
    return terreno;
}

Casa SistemaImobiliaria::lerCasaDoArquivo(ifstream &arquivo){
    string cidade, bairro, logradouro, cep;
    int numero, tipoDeImovel, valor, areaConstruida, areaTerreno;
    int numPavimentos, numQuartos, tipoOferta;
    
    arquivo >> tipoDeImovel >> valor >> tipoOferta; 
    arquivo >> bairro >> cidade;
    arquivo >> cep >> numero >> logradouro;
    arquivo >> areaConstruida >> areaTerreno >> numPavimentos >> numQuartos;

    Endereco endereco = Endereco(logradouro, bairro, cidade, cep, numero);
    Casa casa = Casa(numPavimentos, numQuartos, areaTerreno, areaConstruida, tipoOferta, tipoDeImovel, valor, endereco);
    cout << casa.getDescricao()<<endl;
    return casa;
}

Apartamento SistemaImobiliaria::lerApartamentoDoArquivo(ifstream &arquivo){
    string cidade, bairro, logradouro, cep, posicao;
    int numero, tipoDeImovel, valor;
    int numQuartos, vagasGaragem,area , valorCondominio, tipoOferta;

    arquivo >> tipoDeImovel >> valor >> tipoOferta; 
    arquivo >> bairro >> cidade;
    arquivo >> cep >> numero >> logradouro;
    arquivo >> posicao >> numQuartos >>vagasGaragem >> area >> valorCondominio;
    
    Endereco endereco = Endereco(logradouro, bairro, cidade, cep, numero);
    Apartamento apartamento = Apartamento(posicao,numQuartos,vagasGaragem,valorCondominio,area,tipoOferta, tipoDeImovel, valor, endereco);
    cout << apartamento.getDescricao()<< endl;
    return apartamento;
}

Terreno SistemaImobiliaria::lerTerrenoDoArquivo(ifstream &arquivo){
    string cidade, bairro, logradouro, cep;
    int numero, tipoDeImovel, valor,tipoOferta;
    int area;
    
    arquivo >> tipoDeImovel >> valor >> tipoOferta; 
    arquivo >> bairro >> cidade;
    arquivo >> cep >> numero >> logradouro;
    arquivo >> area;
    Endereco endereco = Endereco(logradouro, bairro, cidade, cep, numero);
    Terreno terreno =  Terreno(area,tipoOferta, tipoDeImovel, valor, endereco);
    cout << terreno.getDescricao()<<endl;
    return terreno;
}