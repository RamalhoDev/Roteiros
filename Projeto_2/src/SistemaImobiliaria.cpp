#include <iostream>
#include <string>
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/Imovel.h"

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
    }
    return imoveis;
}

list <Imovel> SistemaImobiliaria:: getImoveisParaAlugarPorBairro(string bairro){
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;

    for(Imovel &i : imovel){

        if(!i.getEndereco().getBairro().compare(bairro) && i.getTipoOferta() == 0){
            imoveis.push_back(i);
        }
    }
    return imoveis;
}

list <Imovel> SistemaImobiliaria:: getImoveisParaVenderPorBairro(string bairro){
   GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;
    for(Imovel &i : imovel){

        if(!i.getEndereco().getBairro().compare(bairro) && i.getTipoOferta() == 1){
            imoveis.push_back(i);
        }
    }
    return imoveis;
}

list<Imovel> SistemaImobiliaria:: getImoveisPorCidade(string cidade){
    GerenteDePersistencia recupera;
    list <Imovel> imovel = recupera.recuperaListaImoveis();
    list <Imovel> imoveis;

    for(Imovel &i: imovel){
        cout << i.getEndereco().getCidade()<< endl;
        if(!i.getEndereco().getCidade().compare(cidade)){
            imoveis.push_back(i);
        }
    }
    return imoveis;
}

Endereco SistemaImobiliaria::cadastrarEndereco(){

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
            logradouro = ToUpper(logradouro);
            cidade = ToUpper(cidade);
            bairro = ToUpper(bairro);
            Endereco *endereco = new Endereco(logradouro, bairro, cidade, cep, numero);
            
            return *endereco;
}

Casa* SistemaImobiliaria::cadastrarCasa(Endereco endereco, int tipoDeImovel){

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

Apartamento* SistemaImobiliaria::cadastrarApartamento(Endereco endereco, int tipoDeImovel){
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
    getchar();

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
    cout<<"\n\nImovel Cadastrado Com Sucesso!\n";
    return apartamento;
}


Terreno* SistemaImobiliaria::cadastrarTerreno(Endereco endereco, int tipoDeImovel){
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

string SistemaImobiliaria::ToUpper(string entradaUsuario){
	string saidaUsuario;
	for(int i = 0; i  < entradaUsuario.size(); i++){
		saidaUsuario+= toupper(entradaUsuario[i]);
	}
	return saidaUsuario;
}