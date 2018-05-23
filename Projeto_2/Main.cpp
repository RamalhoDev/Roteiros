#include <iostream>
#include <string>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/GerenteDePersistencia.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/SistemaImobiliaria.h"

using namespace std;

//Imprime a descrição do Imovel
void ImprimirDescricao(list <Imovel> data){
	
	for(Imovel &i: data){
		cout<<i.getDescricao()<<endl;
	}

}

//Menu para seleção do tipo de Imovel
int Selecao(){
	int tipoDeImovel;

	cout << "\nInsira o tipo de imóvel que você deseja pesquisar (1 a 5):\n"
		<< "\t1 - Casa,\n"
		<< "\t2 - Apartamento\n"
		<< "\t3 - Terreno\n"
		<< "\t4 - Flat\n"
		<< "\t5 - Studio\n";
	cout <<"\tResposta: ";

	cin >> tipoDeImovel;
	getchar();
	return tipoDeImovel;
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

		//Menu de acesso, ocorre a escolha da ação desejada
		cout << "Escolha a operação que deseja realizar:\n";
		cout << "\t1 - Consultar Imoveis\n";
		cout << "\t2 - Cadastar Imoveis\n";
		cout << "\t3 - Sair do programa\n";
		cout <<"\t\tResposta: ";
		cin>>menu;
		getchar();

		if(menu == 1){
			//Consulta os imóveis
			list<Imovel> imoveis;

			cout<<"Quais imoveis gostaria de consultar?\n";
			
			//Especifica o tipo de imóvel que o cliente procura
			
			cout<<"\t1 - Imoveis para Alugar por Bairro\n" << 
				  "\t2 - Imovel para Vender por Bairro\n" << 
				  "\t3 - Imovel por Cidade\n"<< 
				  "\t4 - Imoveis por Tipo\n"<<
				  "\t5 - Todos os imoveis\n"<<
				  "\t6 - Imoveis para alugar por Tipo\n";
			
			cout<< "\t\tResposta: ";
			cin >> tipodeConsulta;
			
			getchar();

			if(tipodeConsulta == 1){
				//Consulta de imoveis para ALUGAR por bairro
			
				cout << "\t\tInsira o bairro desejado: ";
				
				//Ler o nome do bairro
				getline(cin,auxiliar);
				
				//Procura dentre todos os imóveis para ALUGAR, os que possuem o  bairro desejado
				imoveis =imobiliaria->getImoveisParaAlugarPorBairro(auxiliar);
				
				//Imprime todos os Imoveis de acordo com a busca por bairro
				ImprimirDescricao(imoveis);

			}else if(tipodeConsulta == 2);
				//Consulta de imoveis para VENDER por bairro
				
				cout << "\t\tInsira o bairro desejado: ";
				//Ler o nome do bairro
				getline(cin,auxiliar);
				
				//Procura dentre todos os imóveis para VENDER, os que possuem o  bairro desejado
				imoveis = imobiliaria->getImoveisParaVenderPorBairro(auxiliar);
				
				//Imprime todos os Imoveis de acordo com a busca por bairro
				ImprimirDescricao(imoveis);

			}else if(tipodeConsulta == 3){
				//Consulta por Cidade
			
				cout << "\t\tInsira a cidade desejada: ";
				//Ler o nome da Cidade
				getline(cin,auxiliar);
			
				//Procura dentre todos os imóveis do sistema, os que estejam na cidade desejada
				imoveis = imobiliaria->getImoveisPorCidade(auxiliar);
			
				//Imprime todos os Imoveis de acordo com a busca
				ImprimirDescricao(imoveis);

			}else if(tipodeConsulta == 4){
				//Imoveis por Tipo
				//Permite o cliente escolher o tipo de imovel que deseja procurar
				tipoDeImovel = Selecao();
				
				//Pesquisa o imovel a procura de acordo com  a base cdastrada no sistema
				imoveis = imobiliaria->getImoveisPorTipo(tipoDeImovel);
			
				//Imprime os imoveis de acordo com o tipo de consulta escolhida
				ImprimirDescricao(imoveis);
			
			}else if(tipodeConsulta == 5){
				//Consulta todos os imoveis
			
				//Acessa todos os imoveis cadastrados
				imoveis = imobiliaria->getImoveis();
			
				//Exibe a base de dados
				ImprimirDescricao(imoveis);

			}else if(tipodeConsulta == 6){
				//Aluguel por tipo de imóvel
				
				//Seleciona o tipo de imovel
				tipoDeImovel = Selecao();
			
				//Pesquisa todos os imoveis para alugar de acordo com o tipo inserido
				imoveis = imobiliaria->getImoveisPorTipoParaAlugar(tipoDeImovel);
			
				//Imprime os resultados da busca
				ImprimirDescricao(imoveis);
			}

		}else if(menu == 2){
			//Cadastrar imoveis
			GerenteDePersistencia *escrever;
			tipoDeImovel = Selecao();

			if(tipoDeImovel == 1){
				
				//Cadastra uma Casa
				Casa *casa;
				
				//Acessa a Lista para cadastrar o Imovel
				casa = imobiliaria->cadastrarCasa(imobiliaria->cadastrarEndereco(), tipoDeImovel);
				
				//Salva o imovel cadastrado
				escrever->salvaListaImoveis(casa);
				
				//Exclui o objeto
				casa->~Casa();
			
			}else if(tipoDeImovel == 2){
				
				//Cadastra um Apartamento
				Apartamento *apartamento;
				
				//Acessa a Lista para cadastrar o Imovel
				apartamento = imobiliaria->cadastrarApartamento(imobiliaria->cadastrarEndereco(), tipoDeImovel);
				
				//Salva o imovel cadastrado
				escrever->salvaListaImoveis(apartamento);
				
				//Exclui o objeto
				apartamento->~Apartamento();
			
			}else if(tipoDeImovel==3){
				
				//Cadastra um terreno
				Terreno *terreno;
				
				//Acessa a Lista para cadastrar o Imovel
				terreno = imobiliaria->cadastrarTerreno(imobiliaria->cadastrarEndereco(), tipoDeImovel);
				
				//Salva o imovel cadastrado
				escrever->salvaListaImoveis(terreno);
				
				//Exclui o objeto
				terreno->~Terreno();
			}
			else if(tipoDeImovel == 4){
				//Cadastra um Flat
				Flat *flat;
				
				//Acessa a Lista para cadastrar o Imovel
				flat = imobiliaria->cadastrarFlat(imobiliaria->cadastrarApartamento(imobiliaria->cadastrarEndereco(), tipoDeImovel));
				
				//Salva o imovel cadastrado
				escrever->salvaListaImoveis(flat);
				
				//Exclui o objeto
				flat->~Flat();
			
			}else if(tipoDeImovel == 5){
				
				//Cadastra um Studio
				Studio *studio;
				
				//Acessa a Lista para cadastrar o Imovel
				studio = imobiliaria->cadastrarStudio(imobiliaria->cadastrarFlat(imobiliaria->cadastrarApartamento(imobiliaria->cadastrarEndereco(), tipoDeImovel)));
				
				//Salva o imovel cadastrado
				escrever->salvaListaImoveis(studio);
				
				//Exclui o objeto
				studio->~Studio();
			}

			escrever->~GerenteDePersistencia();
			//Exclui o objeto
		
		}else if(menu == 3){
			//Finaliza o Programa
			
			//Desepede-se do usuário
			cout << "Obrigado por utilizar o programa !" << endl;
			break;
		}
	}
	return 0;
}
