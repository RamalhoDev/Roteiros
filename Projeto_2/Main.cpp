#include <iostream>
#include <string>
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rodrigoramalho/roteiro/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"

using namespace std;

string ToUpper(string entradaUsuario){
	string saidaUsuario;
	for(int i = 0; i  < entradaUsuario.size(); i++){
		saidaUsuario+= toupper(entradaUsuario[i]);
	}
	return saidaUsuario;
}

void ImprimirDescricao(list <Imovel> data){
	for(Imovel &i: data){
		cout<<i.getDescricao()<<endl;
	}
}

int main(void){
	setlocale(LC_ALL, "Portuguese");

	while(1){
		SistemaImobiliaria *imobiliaria;
		int tipoDeImovel, menu, tipodeConsulta;
		string auxiliar;

		cout<< "----------------------------------------------\n";
		cout <<"\t\t\tMENU\n";
		cout<< "----------------------------------------------\n\n";


		cout << "Escolha a operação que deseja realizar:\n";
		cout << "\t1 - Consultar Imoveis\n";
		cout << "\t2 - Cadastar Imoveis\n";
		cout << "\t3 - Sair do programa\n";
		cout <<"\t\tResposta: ";
		cin>>menu;
		getchar();

		if(menu == 1){

			list<Imovel> imoveis;
			list<string> descricao;
			list<Imovel> ::iterator it;
			list<string> ::iterator s;
			cout<<"Quais imoveis gostaria de consultar?\n";
			
			cout<<"\t1 - Imoveis para Alugar por Bairro\n" << 
				"\t2 - Imovel para Vender por Bairro\n" << 
				"\t3 - Imovel por Cidade\n"<< 
				"\t4 - Imoveis por Tipo\n"<<
				"\t5 - Todos os imoveis\n"<<
				"\t6 - Descrição de todos os imoveis\n";
			cout<< "\t\tResposta: ";
			cin >> tipodeConsulta;
			getchar();

			if(tipodeConsulta == 1){
			
				cout << "\t\tInsira o bairro desejado: ";
				getline(cin,auxiliar);
				auxiliar = ToUpper(auxiliar);
				imoveis =imobiliaria->getImoveisParaAlugarPorBairro(auxiliar);
			
				ImprimirDescricao(imoveis);
			}else if(tipodeConsulta == 2){
			
				cout << "\t\tInsira o bairro desejado: ";
				getline(cin,auxiliar);
				auxiliar = ToUpper(auxiliar);
				imoveis = imobiliaria->getImoveisParaVenderPorBairro(auxiliar);
				
				ImprimirDescricao(imoveis);

			}else if(tipodeConsulta == 3){
			
				cout << "\t\tInsira a cidade desejada: ";
				getline(cin,auxiliar);
				auxiliar = ToUpper(auxiliar);
				imoveis = imobiliaria->getImoveisPorCidade(auxiliar);	
				
				ImprimirDescricao(imoveis);
			}else if(tipodeConsulta == 4){
			
				cout << "\nInsira o tipo de imóvel que você deseja pesquisar (1 a 3):\n"
					<< "\t1-Casa,\n"
					<< "\t2-Apartamento\n"
					<< "\t3-Terreno\n";
				cout <<"\tResposta: ";
				cin >> tipoDeImovel;
				imoveis = imobiliaria->getImoveisPorTipo(tipoDeImovel);
				
				ImprimirDescricao(imoveis);
			}else if(tipodeConsulta == 5){
			
				imoveis = imobiliaria->getImoveis();
		
				ImprimirDescricao(imoveis);

			}else if(tipodeConsulta == 6){
			
				descricao = imobiliaria->getDescricaoImoveis();
				for(string &i: descricao){
					cout<<i<<endl;
				}
			}

		}else if(menu == 2){
			GerenteDePersistencia *escrever;
			SistemaImobiliaria *imobiliaria;
			
			cout<< "Insira o tipo de Imovel que você deseja cadastrar: \n\n";
			cout <<"\t1 - Casa\n";
			cout <<"\t2 - Apartamento\n";
			cout <<"\t3 - Terreno\n";
			cout << "\tResposta: " ;
			cin>>tipoDeImovel;
			getchar();

			if(tipoDeImovel == 1){

				Casa *casa;
				casa = imobiliaria->cadastrarCasa(imobiliaria->cadastrarEndereco(), tipoDeImovel);
				escrever->salvaListaImoveis(casa);
				casa->~Casa();
			
			}else if(tipoDeImovel == 2){

				Apartamento *apartamento;
				apartamento = imobiliaria->cadastrarApartamento(imobiliaria->cadastrarEndereco(), tipoDeImovel);
				escrever->salvaListaImoveis(apartamento);
				apartamento->~Apartamento();
			
			}else if(tipoDeImovel==3){
				Terreno *terreno;
				terreno = imobiliaria->cadastrarTerreno(imobiliaria->cadastrarEndereco(), tipoDeImovel);
				escrever->salvaListaImoveis(terreno);
				terreno->~Terreno();
			}

			escrever->~GerenteDePersistencia();
		}else if(menu == 3){
			cout << "Obrigado por utilizar o programa !" << endl;
			break;
		}
	}
	return 0;
}
