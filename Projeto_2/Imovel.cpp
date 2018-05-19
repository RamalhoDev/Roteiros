#include<string>
#include "Imovel.h"

using namespace std;

Imovel::Imovel();
Imovel::~Imovel();
Imovel::Imovel(int imovel_para_alugar, int imovel_para_vender, int tipoOferta, double valor, const Endereco &endereco)
{
    this-> imovel_para_alugar = imovel_para_alugar;
    this-> imovel_para_vender = imovel_para_vender;
    this-> tipoOferta = tipoOferta;
    this-> valor = valor;
    this-> endereco = endereco;
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
Endereco :: Endereco(string logradouro, string bairro, string cidade, string cep, int numero) : Imovel()
{
    this-> logradouro = logradouro;
    this-> bairro = bairro;
    this-> cidade = cidade;
    this-> cep = cep;
    this-> numero = numero;
}

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
Casa:: Casa(int numPavimentos, int numQuartos, double areaTerreno, double areaConstruida) : Imovel()
{
    this-> numPavimentos = numPavimentos;
    this-> numQuartos = numQuartos;
    this-> areaTerreno = areaTerreno;
    this-> areaConstruida = areaConstruida;
}

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
Apartamento:: Apartamento(string posicao, int numQuartos, int vagasGaragem, double valorCondominio, double area) : Imovel()
{
    this-> posicao = posicao;
    this-> numQuartos = numQuartos;
    this-> vagasGaragem = vagasGaragem;
    this-> valorCondominio = valorCondominio;
    this-> area = area;
}

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
Terreno:: Terreno(double area) : Imocel()
{
    this-> area = area;
}

void setArea(double area)
{
    this-> area = area;
}
double getArea()
{
    return area;
}
