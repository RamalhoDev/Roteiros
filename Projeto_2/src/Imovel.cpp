#include <string>
#include <iostream>
#include <fstream>
#include "/home/rcr/Documentos/Backup_Mint/GITS/Roteiros/Projeto_2/includes/Imovel.h"

using namespace std;

//Implementação da classe Imovel:

Imovel::Imovel(){}
Imovel::Imovel(int tipoDeImovel,int tipoOferta, double valor, const Endereco &endereco)
{
    this->tipoDeImovel = tipoDeImovel;
    this-> tipoOferta = tipoOferta;
    this-> valor = valor;
    this-> endereco = endereco;
}

Imovel::Imovel(int tipoDeImovel,int tipoOferta, double valor, const Endereco &endereco, string descricao)
{   
    this->tipoDeImovel = tipoDeImovel;
    this->tipoOferta = tipoOferta;
    this->valor = valor;
    this->endereco = endereco;
    this->descricao = descricao;
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
void Imovel::setDescricao(string descricao){
    this->descricao = descricao;
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
        descricao += "Aluga-se Apartamento " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";  
        descricao += "Valor do Aluguel = RS " + to_string(valor) + " | " ;
    }else if(imovel_para_vender == tipoOferta){
        descricao += "Vende-se Apartamento " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";      
        descricao += "Valor de Venda = RS " + to_string(valor)+ " | " ;
    }
    descricao += "Valor do Condominio = RS "+ to_string(valorCondominio) + "\n";
    descricao += "\nNumero de quartos: " + to_string(numQuartos) + " | Vagas na Garagem: " + to_string(vagasGaragem) + "\n";
    descricao += "Area: " + to_string(area) + " | Posicao: " + posicao + "\n";
    descricao += "*****************************************************************\n";
    
    return descricao;
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







Flat::Flat():Apartamento(){}
Flat::Flat(string ar,
        string internet,
        string tv,
        string lavanderia,
        string limpeza,
        string recepcao,
        string posicao,
        int numQuartos,
        int vagasGaragem, 
        double valorCondominio, 
        double area,
        int tipoOferta,
        int tipoDeImovel, 
        double valor, 
        const Endereco &endereco):Apartamento(posicao, 
                                              numQuartos, 
                                              vagasGaragem, 
                                              valorCondominio, 
                                              area, 
                                              tipoOferta, 
                                              tipoDeImovel, 
                                              valor, 
                                              endereco){

                                                this-> ar = ar;
                                                this-> internet = internet;
                                                this-> tv = tv;
                                                this-> lavanderia = lavanderia;
                                                this-> limpeza = limpeza;
                                                this-> recepcao = recepcao;
                                                
    }
string Flat::getAr(){
    return ar;
}
string Flat::getInternet(){
    return internet;
}
string Flat::getTv(){
    return tv;
}
string Flat::getLavanderia(){
    return lavanderia;
}
string Flat::getLimpeza(){
    return limpeza;
}
string Flat::getRecepcao(){
    return recepcao;
}

void Flat::setAr(string ar){
    this-> ar = ar;
}
void Flat::setInternet(string internet){
    this-> internet = internet;
}
void Flat::setTv(string tv){
    this-> tv = tv;
}
void Flat::setLavanderia(string lavanderia){
    this-> lavanderia = lavanderia;
}
void Flat::setLimpeza(string limpeza){
    this-> limpeza = limpeza;
}
void Flat::setRecepcao(string recepcao){
    this-> recepcao = recepcao;
}

string Flat::getDescricao(){
    
    string descricao = "*****************************************************************\n";
    
    if(imovel_para_alugar == tipoOferta){
        descricao += "Aluga-se Flat " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";  
        descricao += "Valor do Aluguel = RS " + to_string(valor) + " | " ;
    }else if(imovel_para_vender == tipoOferta){
        descricao += "Vende-se Flat " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";      
        descricao += "Valor de Venda = RS " + to_string(valor)+ " | " ;
    }

    descricao += "Valor do Condominio = RS "+ to_string(valorCondominio) + "\n";
    descricao += "Numero de quartos: " + to_string(numQuartos) + " | Vagas na Garagem: " + to_string(vagasGaragem) + "\n";
    descricao += "Area: " + to_string(area) + " | Posicao: " + posicao + "\n";
    descricao += "Ar-condicionado: "+ ar + " | Internet: "+ internet +" | Lavanderia: "+ lavanderia +"\n";
    descricao += "Recepcao: "+recepcao+ " | Limpeza: " + limpeza+ "\n";
    descricao += "*****************************************************************\n";
    
    return descricao;
}






Studio::Studio():Flat(){}
Studio::Studio( string piscina,
                string sauna,
                string ginastica,
                string ar,
                string internet,
                string tv,
                string lavanderia,
                string limpeza,
                string recepcao,
                string posicao,
                int numQuartos,
                int vagasGaragem, 
                double valorConominio, 
                double area,
                int tipoOferta,
                int tipoDeImovel, 
                double valor, 
                const Endereco &endereco):Flat( ar, 
                                                internet,
                                                tv, 
                                                lavanderia, 
                                                limpeza, 
                                                recepcao,
                                                posicao, 
                                                numQuartos, 
                                                vagasGaragem, 
                                                valorCondominio, 
                                                area, 
                                                tipoOferta, 
                                                tipoDeImovel, 
                                                valor,
                                                endereco){
                                                    this->piscina = piscina;
                                                    this->sauna = sauna;
                                                    this->ginastica = ginastica;
                                                }

string Studio::getPiscina(){
    return piscina;
}
string Studio::getSauna(){
    return sauna;
}
string Studio::getGinastica(){
    return ginastica;
}

void Studio::setPiscina(string piscina){
    this->piscina = piscina;
}
void Studio::setSauna(string sauna){
    this->sauna = sauna;
}
void Studio::setGinastica(string ginastica){
    this->ginastica = ginastica;
}

string Studio::getDescricao(){
    
    string descricao = "*****************************************************************\n";
    
    if(imovel_para_alugar == tipoOferta){
        descricao += "Aluga-se Studio " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";  
        descricao += "Valor do Aluguel = RS " + to_string(valor) + " | " ;
    }else if(imovel_para_vender == tipoOferta){
        descricao += "Vende-se Studio " +  to_string(endereco.getNumero()) + " || Rua: " + endereco.getLogradouro()+ "\n";      
        descricao += "Valor de Venda = RS " + to_string(valor)+ " | " ;
    }
    
    descricao += "Valor do Condominio = RS "+ to_string(valorCondominio) + "\n";
    descricao += "Numero de quartos: " + to_string(numQuartos) + " | Vagas na Garagem: " + to_string(vagasGaragem) + "\n";
    descricao += "Area: " + to_string(area) + " | Posicao: " + posicao + "\n";
    descricao += "Ar-condicionado: "+ ar + " | Internet: "+ internet +" | Lavanderia: "+ lavanderia +"\n";
    descricao += "Recepcao: "+recepcao+ " | Limpeza: " + limpeza+ "\n";
    descricao += "Piscina: "+piscina+" | Sauna: "+sauna+" | Sala de Ginastica: "+ginastica+"\n";
    descricao += "*****************************************************************\n";
    
    return descricao;
}


