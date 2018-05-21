#include <string>
#include <iostream>
#include <fstream>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"

using namespace std;

//Implementação da classe Imovel:

Imovel::Imovel(){}
Imovel::Imovel( int tipoDeImovel,int tipoOferta, double valor, const Endereco &endereco)
{
    this->tipoDeImovel = tipoDeImovel;
    this-> tipoOferta = tipoOferta;
    this-> valor = valor;
    this-> endereco = endereco;
}

double Imovel::getValor()
{
    return valor;
}

int Imovel::getTipoOferta()
{
    return tipoOferta;
}

Endereco Imovel::getEndereco()
{
    return endereco;
}

int Imovel::getTipoDeImovel(){
    return tipoDeImovel;
}

//Implementação da classe Endereco:

Endereco::Endereco() {}
Endereco::Endereco(string logradouro, string bairro, string cidade, string cep, int numero)
{
    this-> logradouro = logradouro;
    this-> bairro = bairro;
    this-> cidade = cidade;
    this-> cep = cep;
    this-> numero = numero;
}

string Endereco::getLogradouro()
{
    return logradouro;
}

string Endereco::getBairro()
{
    return bairro;
}

string Endereco::getCidade()
{
    return cidade;
}

string Endereco::getCep()
{
    return cep;
}

int Endereco::getNumero()
{
    return numero;
}
void Endereco::setLogradouro(string logradouro){
    this -> logradouro = logradouro;
}
void Endereco::setBairro(string bairro){
    this -> bairro = bairro;
}
void Endereco::setCidade(string cidade){
    this -> cidade = cidade;
}
void Endereco::setCep(string cep){
    this -> cep = cep;
}
void Endereco::setNumero(int numero){
    this -> numero = numero;
}

//Implementação da classe Casa:

Casa::Casa() : Imovel(){}
Casa::Casa(int numPavimentos, 
        int numQuartos, 
        double areaTerreno, 
        double areaConstruida, 
        int tipoOferta,
        int tipoDeImovel,
        double valor, 
        const Endereco &endereco) : Imovel(tipoDeImovel,tipoOferta, valor, endereco)
{
    this-> numPavimentos = numPavimentos;
    this-> numQuartos = numQuartos;
    this-> areaTerreno = areaTerreno;
    this-> areaConstruida = areaConstruida;
}

void Casa::setNumPavimentos(int numPavimentos)
{
    this-> numPavimentos = numPavimentos;
}

int Casa::getNumPavimentos()
{
    return numPavimentos;
}

void Casa::setNumQuartos(int numQuartos)
{
    this-> numQuartos = numQuartos;
}

int Casa::getNumQuartos()
{
    return numQuartos;
}

void Casa::setAreaTerreno(double areaTerreno)
{
    this-> areaTerreno = areaTerreno;
}

double Casa::getAreaTerreno()
{
    return numQuartos;
}

void Casa::setAreaConstruida(double areaConstruida)
{
    this-> areaConstruida = areaConstruida;
}

double Casa::getAreaConstruida()
{
    return areaConstruida;
}

string Casa::getDescricao(){
    string descricao = "*****************************************************************\n";
    if(imovel_para_alugar == tipoOferta){
        descricao += "Aluga-se Casa " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";  
        descricao += "Valor do Aluguel = RS " + to_string(valor) + "\n";
    }else if(imovel_para_vender == tipoOferta){
        descricao += "Vende-se Casa " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";      
        descricao += "Valor de Venda = RS " + to_string(valor)+ "\n";
    }
    descricao += "\nNumero de quartos: " + to_string(numQuartos) + " | Número de Pavimentos: " + to_string(numPavimentos) + "\n";
    descricao += "Area do terreno: " + to_string(areaTerreno) + " | Area Construida: " + to_string(areaConstruida) + "\n";
    descricao += "*****************************************************************\n";
    
    return descricao;
}


void Casa::escreveNoArquivo(ofstream &arquivo){  
    string auxiliar ="";
    auxiliar+= to_string(tipoDeImovel) +" "+ to_string(valor)+" "+to_string(tipoOferta)+ " ";
    auxiliar+= endereco.getBairro() +" "+ endereco.getCidade()+ " ";
    auxiliar+= endereco.getCep() +" "+ to_string(endereco.getNumero()) +" "+ endereco.getLogradouro()+ " ";
    auxiliar+= to_string(areaConstruida) +" "+ to_string(areaTerreno) +" "+ to_string(numPavimentos)+" "+ to_string(numQuartos)+ " ";
    arquivo << auxiliar;
}

//Implementação da classe Apartamento:
Apartamento::Apartamento() : Imovel(){}
Apartamento::Apartamento(string posicao, 
                          int numQuartos, 
                          int vagasGaragem, 
                          double valorCondominio, 
                          double area,
                          int tipoOferta, 
                          int tipoDeImovel,
                          double valor, 
                          const Endereco &endereco) : Imovel(tipoDeImovel,tipoOferta, valor, endereco){
    this-> posicao = posicao;
    this-> numQuartos = numQuartos;
    this-> vagasGaragem = vagasGaragem;
    this-> valorCondominio = valorCondominio;
    this-> area = area;
}

void Apartamento::setPosicao(string posicao){
    this->posicao = posicao;
}

void Apartamento::setNumQuartos(int numQuartos){
    this-> numQuartos = numQuartos;
}

void Apartamento::setVagasGaragem(int vagasGaragem){
    this-> vagasGaragem = vagasGaragem;
}

void Apartamento::setValorCondominio(double valorCondominio){
    this-> valorCondominio = valorCondominio;
}

void Apartamento::setArea(double area){
    this->area = area;
}

string Apartamento::getPosicao(){
    return posicao;
}

int Apartamento::getNumQuartos(){
    return numQuartos;
}

int Apartamento::getVagasGaragem(){
    return vagasGaragem;
}

double Apartamento::getValorCondominio(){
    return valorCondominio;
}

double Apartamento::getArea(){
    return area;
}
string Apartamento::getDescricao(){
    string descricao = "*****************************************************************\n";
    if(imovel_para_alugar == tipoOferta){
        descricao += "Aluga-se Casa " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";  
        descricao += "Valor do Aluguel = RS " + to_string(valor) + "\n";
    }else if(imovel_para_vender == tipoOferta){
        descricao += "Vende-se Casa " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";      
        descricao += "Valor de Venda = RS " + to_string(valor)+ "\n";
    }
    descricao += "Valor do Condominio = RS "+ to_string(valorCondominio) + "\n";
    descricao += "\nNumero de quartos: " + to_string(numQuartos) + " | Vagas na Garagem: " + to_string(vagasGaragem) + "\n";
    descricao += "Area do terreno: " + to_string(area) + " | Posicao: " + posicao + "\n";
    descricao += "*****************************************************************\n";
    
    return descricao;
}


void Apartamento::escreveNoArquivo(ofstream &arquivo){
    string auxiliar = "";
    auxiliar+= to_string(tipoDeImovel) + " " + to_string(valor) +" "+to_string(tipoOferta)+ " ";
    auxiliar+= endereco.getBairro() +" "+ endereco.getCidade()+ " ";
    auxiliar+= endereco.getCep() +" "+ to_string(endereco.getNumero()) +" "+ endereco.getLogradouro()+ " ";
    auxiliar+= posicao +" "+ to_string(numQuartos) +" "+to_string(vagasGaragem)+ " " +  to_string(area)+" "+ to_string(valorCondominio)+" ";
    arquivo << auxiliar;
}

//Implementação da classe Terreno:
Terreno::Terreno() : Imovel(){}

Terreno::Terreno(double area,
                  int tipoOferta,
                  int tipoDeImovel, 
                  double valor, 
                  const Endereco &endereco) : Imovel(tipoDeImovel,tipoOferta, valor, endereco){
    this-> area = area;
}

void Terreno::setArea(double area)
{
    this-> area = area;
}

double Terreno::getArea()
{
    return area;
}
string Terreno::getDescricao(){
    string descricao = "*****************************************************************\n";
    if(imovel_para_alugar == tipoOferta){
        descricao += "Aluga-se Terreno " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";  
        descricao += "Valor do Aluguel = RS " + to_string(valor) + "\n";
    }else if(imovel_para_vender == tipoOferta){
        descricao += "Vende-se Terreno " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";      
        descricao += "Valor de Venda = RS " + to_string(valor)+ "\n";
    }
    descricao += "\nArea : "+to_string(area)+ "\n";
    descricao += "*****************************************************************\n";
    return descricao;
}

void Terreno::escreveNoArquivo(ofstream &arquivo){
    string auxiliar ="";
    auxiliar+= to_string(tipoDeImovel) +" "+ to_string(valor)+" "+to_string(tipoOferta) + " ";
    auxiliar+= endereco.getBairro() +" "+ endereco.getCidade()+ " ";
    auxiliar+= endereco.getCep() +" "+ to_string(endereco.getNumero()) +" "+ endereco.getLogradouro()+" ";
    auxiliar+= to_string(area)+ " ";
    arquivo<<auxiliar;
}

