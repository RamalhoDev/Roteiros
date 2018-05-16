#include<string>
#include "Figuras.h"

using namespace std;

FigurasGeometricas::FigurasGeometricas(){}
FigurasGeometricas::FigurasGeometricas(string nome){
    this -> nome = nome;
}
void FigurasGeometricas::setNome(string nome){
    this -> nome = nome;
}

string FigurasGeometricas:: getNome(){
    return nome;
}

Retangulo::Retangulo() : FigurasGeometricas(){}
Retangulo::Retangulo(double area, double base, double altura){
    this -> base = base;
    this -> altura = altura;
    this -> area = area;
}

void Retangulo:: setBase(double base){
    this -> base = base;
}

void Retangulo:: setAltura(double altura){
    this -> altura = altura;
}

double Retangulo:: getArea(){
    return base*altura;
}

double Retangulo:: getAltura(){
    return altura;
}

double Retangulo:: getBase(){
    return base;
}

Circulo::Circulo() : FigurasGeometricas(){}
Circulo::Circulo(double area, double raio){
    this -> raio = raio;
    this -> area = area;
}

//void Circulo:: setArea(double area){
  //  this -> area = Area;
//}

void Circulo:: setRaio(double raio){
    this -> raio= raio;
}

double Circulo:: getRaio(){
    return raio;
}

double Circulo:: getArea(){
    return raio*raio*3.1413;
}

Quadrado::Quadrado() : FigurasGeometricas(){}
Quadrado::Quadrado(/*double area,*/ double base){
    //this -> base = base;
    this -> area = area;
}

//void Quadrado:: setArea(double area){
  //  this -> area = area;
//}

void Quadrado:: setBase(double base){
    this -> base = base;
}

double Quadrado:: getArea(){
    return base*base;
}

double Quadrado:: getBase(){
    return base;
}

Triangulo::Triangulo() : FigurasGeometricas(){}
Triangulo::Triangulo(/*double area,*/ double base, double altura){
    //this -> base = base;
    this -> altura = altura;
    this -> area = area;
}

//void Triangulo:: setArea(double area){
  //  this -> area = area;
//}

void Triangulo:: setBase(double base){
    this -> base = base;
}

void Triangulo:: setAltura(double altura){
    this -> altura = altura;
}

double Triangulo:: getArea(){
    return base*altura;
}

double Triangulo:: getBase(){
    return base;
}

double Triangulo:: getAltura(){
    return altura;
}

FigurasGeometricas::~FigurasGeometricas(){}

