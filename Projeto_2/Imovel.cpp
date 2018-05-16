#include<string>
#include "Imovel.h"

using namespace std;

Imovel::Imovel();
Imovel::~Imovel();
Imovel::Imovel(int imovel_para_alugar, int imovel_para_vender, int tipoOferta, double valor, const Endereco &endereco)
{

}

double Imovel:: getVelor()
{
    return valor;
}

int Imovel:: getTipoOferta()
{
    return tipoImovel;
}

Endereco Imovel:: getEndereco()
{
    return endereco;
}

Endereco :: Endereco() : Imovel(){}
Endereco :: ~Endereco() : Imovel(){}

string Endereco:: getLogradouro()
{
    return logradouro;
}

string Endereco:: getBairro()
{
    return bairro;
}

string Endereco:: getCidade()
{
    return cidade;
}

string Endereco:: getCep()
{
    return cep;
}

int Endereco:: getNumero()
{
    return numero;
}



Casa :: Casa() : Imovel(){}
Casa :: ~Casa() : Imovel(){}

void Casa:: setNumPavimentos(int numPavimentos)
{
    this-> numPavimentos = numPavimentos;
}

int Casa:: getNumPavimentos()
{
    return numPavimentos;
}

void Casa:: setNumQuartos(int numQuartos)
{
    this-> numQuartos = numQuartos;
}

int Casa:: getNumQuartos()
{
    return numQuartos;
}

void Casa:: setAreaTerreno(double areaTerreno)
{
    this-> areaTerreno = areaTerreno;
}

double Casa:: getAreaTerreno()
{
    return numQuartos;
}

void Casa:: setAreaConstruida(double areaConstruida)
{
    this-> areaConstruida = areaConstruida;
}

double Casa:: getAreaConstruida()
{
    return numConstruida;
}


Apartamento:: Apartamento() : Imovel(){}
Apartamento:: ~Apartamento() : Imovel(){}

void Apartamento::setPosicao(string posicao)
{
    this->posicao = posicao;
}
void Apartamento::setNumQuartos(int numQuartos)
{
    this-> numQuartos;
}
void Apartamento::setVagasGaragem(int vagasGaragem)
{
    this-> vagasGaragem = vagasGaragem;
}
void Apartamento::setValorCondominio(double valorCondominio)
{
    this-> valorCondominio = valorCondominio;
}
void Apartamento::setArea(double area)
{
    this->area = area;
}

string Apartamento::getPosicao()
{
    return posicao;
}
int Apartamento::getNumQuartos()
{
    return numQuartos;
}
int Apartamento::getVagasGaragem()
{
    return vagasGaragem;
}
double Apartamento::getValorCondominio()
{
    return valorCondominio;
}
double Apartamento::getArea()
{
    return area;
}


Terreno :: Terreno() : Imovel(){}
Terreno :: ~Terreno() : Imovel(){}

void setArea(double area)
{
    this-> area = area;
}
double getArea()
{
    return area;
}
