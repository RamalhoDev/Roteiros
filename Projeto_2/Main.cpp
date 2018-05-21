#include <iostream>
#include <string>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"

using namespace std;

string ToUpper(string entradaUsuario){
	string saidaUsuario;
	for(int i = 0; i  < entradaUsuario.size(); i++){
		saidaUsuario+= toupper(entradaUsuario[i]);
	}
	return saidaUsuario;
}

int main(void){

	setlocale(LC_ALL, "Portuguese");
	SistemaImobiliaria *imobiliaria;
	int tipoOferta,tipoDeImovel,menu, tipodeConsulta, x;
	string auxiliar, auxiliarNova;

	while(1){
		cout<< "----------------------------------------------\n\n";
		cout <<"                       MENU \n";
		cout<< "----------------------------------------------\n\n";


		cout << "Escolha a operação que deseja realizar: \n";
		cout << "      1 - Consultar Imoveis \n";
		cout << "      2 - Cadastar Imoveis \n";
		cout << "      3 - Sair do programa\n";

		cin>>menu;
		getchar();

		if(menu==1){

			list<Imovel> imoveis;
			list<string> descricao;
			list<Imovel> ::iterator it;
			list<string> ::iterator s;
			cout<<"Quais imoveis gostaria de consultar?\n";
			
			cout<<"1 - Imoveis para Alugar por Bairro\n" << 
				"2 - Imovel para Vender por Bairro\n" << 
				"3 - Imovel por Cidade\n"<< 
				"4 - Imoveis por Tipo\n"<<
				"5 - Todos os imoveis\n"<<
				"6 - Descrição de todos os imoveis\n";
			cout<< "Resposta: ";
			cin >> tipodeConsulta;
			getchar();

			if(tipodeConsulta == 1){
			
				cout << "Insira o bairro desejado:" << endl;
				getline(cin,auxiliar);
				auxiliar = ToUpper(auxiliar);
				cout << auxiliar << endl;
				imoveis =imobiliaria->getImoveisParaAlugarPorBairro(auxiliar);
				for(Imovel &i: imoveis){
					cout<<it->getDescricao()<<endl;
				}
			
			}else if(tipodeConsulta == 2){
			
				cout << "Insira o bairro desejado:" << endl;
				getline(cin,auxiliar);
				auxiliar = ToUpper(auxiliar);
				imoveis =imobiliaria->getImoveisParaVenderPorBairro(auxiliar);
				for(Imovel &i: imoveis){
					cout<<it->getDescricao()<<endl;
				}
			}else if(tipodeConsulta==3){
			
				cout << "Insira a cidade desejada:" <<endl;
				getline(cin,auxiliar);
				imoveis = imobiliaria->getImoveisPorCidade(auxiliar);	
				for(Imovel &i: imoveis){
					cout<<i.getDescricao()<<endl;
				}

			}else if(tipodeConsulta==4){
			
				cout << "\nInsira o tipo de imóvel que você deseja pesquisar (1 a 3):\n"
					<< "1-Casa,\n"
					<< "2-Apartamento\n"
					<< "3-Terreno\n";
				cin >> tipoDeImovel;
				getchar();
				imoveis = imobiliaria->getImoveisPorTipo(tipoDeImovel);
				for(Imovel &i: imoveis){
					cout<<i.getDescricao()<<endl;
				}
			}else if(tipodeConsulta==5){
			
				imoveis = imobiliaria->getImoveis();
				
				for(Imovel &i: imoveis){
					cout<<i.getTipoOferta()<<endl;
				}

			}else if(tipodeConsulta==6){
			
				descricao = imobiliaria->getDescricaoImoveis();
				for(string &i: descricao){
					cout<<i<<endl;
				}
			}

		}else if(menu==2){
			GerenteDePersistencia *escrever;
			SistemaImobiliaria *imobiliaria;
			
			cout<< "Insira o tipo de Imovel que você deseja cadastrar: \n\n";
			cout <<"     1 - Casa\n";
			cout <<"     2 - Apartamento\n";
			cout <<"     3 - Terreno\n";
			cout << "Resposta: " ;
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
			cout << "passou" << endl;
		
		}else if(menu == 3){
			cout << "Obrigado por utilizar o programa !" << endl;
			break;
		}
	}
	return 0;
}
