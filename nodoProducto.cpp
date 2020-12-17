#include "nodoProducto.h"

nodoProducto::nodoProducto() {

}

nodoProducto::nodoProducto(int codigoProducto, string nombreProducto, int stockActual, int precio){
	this->codigoProducto = codigoProducto;
	this->nombreProducto = nombreProducto;
	this->stockActual = stockActual;
	this->precio = precio;
	this->hijoIzq = NULL;
	this->hijoDer = NULL;
}


int nodoProducto::getCodigoProducto(){
	return this->codigoProducto;
}
string nodoProducto::getNombreProducto(){
	return this->nombreProducto;
}
int nodoProducto::getStockActual(){
	return this->stockActual;
}
int nodoProducto::getPrecio(){
	return this->precio;
}
void nodoProducto::setCodigoProducto(int codigoProducto){
	this->codigoProducto = codigoProducto;
}
void nodoProducto::setNombreProducto(string nombreProducto){
	this->nombreProducto = nombreProducto;
}
void nodoProducto::setStockActual(int stockActual){
	this->stockActual = stockActual;
}
void nodoProducto::setPrecio(int precio){
	this->precio = precio;
}
nodoProducto* nodoProducto::getHijoIzq(){
	return this->hijoIzq;
}
nodoProducto* nodoProducto::getHijoDer(){
	return this->hijoDer;
}
void nodoProducto::setHijoIzq(nodoProducto* hijoIzq){
	this->hijoIzq = hijoIzq;
}
void nodoProducto::setHijoDer(nodoProducto* hijoDer){
	this->hijoDer = hijoDer;
}
nodoProducto*& nodoProducto::getHijoIzqRef(){
	return this->hijoIzq;
}
nodoProducto*& nodoProducto::getHijoDerRef(){
	return this->hijoDer;
}
