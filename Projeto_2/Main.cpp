#include <iostream>
#include <string>
#include "Imovel.h"
#include "SistemaImobiliaria.h"
#include "GerenteDePersistencia.h"




using namespace std;

int main(void){

	setlocale(LC_ALL, "Portuguese");

	Imovel cadastroImobiliario;

	int imovel_para_alugar, imovel_para_vender, controle=0, numero, tipoOferta;
	double valor;

	string logradouro, bairro, cidade, cep;

	int menu tipodeConsulta;

	const Endereco &endereco;

	cout<< "----------------------------------------------\n\n";
	coun <<"                       MENU \n";
	cout<< "----------------------------------------------\n\n";


	cout<<"Escolha a operação que deseja realizar: \n";
	cout<<"      1 - Consultar Imoveis \n";
	cout<<"      2- Cadastar Imoveis \n";

	cin>>menu;

	if(menu==1){

		cout<<"Quais imoveis gostaria de consultar?\n";
		cout<<"1- Imoveis para Alugar por Bairro\n 2- Imovel para Vender por Bairro\n 3- Imovel por Cidade\n 4- Imoveis por Tipo\n 5- Todos os imoveis\n ";
		cin<<tipodeConsulta;
		cadastroImobiliario.SistemaImobiliaria.getImoveis(tipodeConsulta);
	}

	if(menu==2){

		cout<<" Utilize a simobologia 0 para não e 1 para sim \n";

		do{
			if(controle!=0){
				cout<<"Voce pode escoler apenas uma opção\nTente novamente\n\n";
			}
			cout<<"\n\n O seu imovel esta disponível para alugar?\n";
			cin>> imovel_para_alugar;
			cadastroImobiliario.setImovel_para_alugar(aluguel);

			cout<<"\n\n O seu imovel esta disponível para vender?\n";
			cin>> imovel_para_vender;
			cadastroImobiliario.setImovel_para_vender(venda);
			++controle;

		} while (imovel_para_alugar==imovel_para_vender);




		cout<< "----------------------------------------------\n\n";
		coun <<"            INFORMAÇÕES ADICIONAIS \n";
		cout<< "----------------------------------------------\n\n";

		do{
			cout<< "Esolha o seu tipo de Oferta: \n\n";
			cout <<"     1 - Casa\n";
			cout <<"     2 - Apartamento\n";
			cout <<"     3 - Terreno\n";

			cin>>tipoOferta;

		}while (tipoOferta!=1 && tipoOferta!=2 && tipoOferta!=3)

		cadastroImobiliario.setTipoOferta(tipoOferta);

		cout<< "-------------------------------------\n\n";
		coun <<"                 Endereço \n";
		cout<< "-------------------------------------\n\n";

		cout<< "Digite seu Logradouro: ";
		getline(cin, logradouro);
		Endereco.getLogradouro(logradouro);

		cout<< "\nDigite seu Bairro: ";
		getline(cin, bairro);
		Endereco.getBairro(bairro);

		cout<< "\nDigite sua Cidade: ";
		getline(cin, cidade);
		Endereco.getCidade(cidade);

		cout<< "\nDigite seu CEP: ";
		getline(cin, cep);
		Endereco.getCep(cep);

		cout<< "\nDigite o numero do imovel: ";
		cin>>numero;
		Endereco.getNumero(numero);


		cout<< "-------------------------------------\n\n";
		coun <<"            Especificações \n";
		cout<< "-------------------------------------\n\n";

		//CASA
		int numPavimentos, numQuartos, 
		double areaTerrenoCasa,areaConstruidaCasa
		

		//APARTAMENTO

	    int numQuartosAP, vagasGaragemAP;
	    double valorCondominio, areaCondominio;
	    string posicaoAP;

	    //TERRENO
	    double areaterreno;


		if(tipoOferta==1){
		//CASA	

			cout<<"\n Digite a quantidade o número de pavimentos da casa: ";
			cin<<numPavimentos;
			cadastroImobiliario.Casa.getNumPavimentos(numPavimentos);



			cout<<"\n Digite a quantidade o número quartos da casa: ";
			cin<<numQuartos;
			cadastroImobiliario.Casa.getNumQuartos(numQuartos);


			cout<<"\n Digite a área total da casa: ";
			cin<<areaTerrenoCasa;
			cadastroImobiliario.Casa.getAreaTerreno(areaTerrenoCasa);


			cout<<"\n Digite a área construida da casa: ";
			cin<<areaConstruidaCasa;
			cadastroImobiliario.Casa.getAreaConstruida(areaConstruidaCasa);



		}
		else if(tipoOferta==2){
		//AP	

			cout<<"\n Digite a quantidade o número quartos do apartamento: ";
			cin<<numQuartosAP;
			cadastroImobiliario.Apartamento.getNumQuartos(numQuartosAP);

			cout<<"\n Digite a quantidade de vagas na garagem disponiveis para o seu apartamento: ";
			cin<<vagasGaragemAP;
			cadastroImobiliario.Apartamento.getVagasGaragem(vagasGaragemAP);

			cout<<"\n Digite o valor do condomínio: ";
			cin<<valorCondominio;
			cadastroImobiliario.Apartamento.getValorCondominio(valorCondominio);

			cout<<"\n Digite a área do seu apartamento ";
			cin<<areaCondominio;
			cadastroImobiliario.Apartamento.getArea(areaCondominio);


			cout<<"\n Digite a posição do seu apartamento: ";
			getline(cin, posicaoAP);
			cadastroImobiliario.Apartamento.getPosicao(posicaoAP);
		}
		else{
		//TERRENO	
			cout<<"Digite a área do seu terreno: "
			cin<< areaterreno;
			cadastroImobiliario.Terreno.getArea(areaterreno);
		}
		



		cout<< "\n-------------------------------------\n\n";
		coun <<"                 Valor \n";
		cout<< "-------------------------------------\n\n";

		cout<<"Qual o valor do seu imovel?\n";
		cin>> valor;
		cadastroImobiliario.setValor(valor);

		cout<<"\n\nImovel Cadastrado Com Sucesso!\n";

	}












}
