#include "NodoProductoAVL.h"

NodoProductoAVL::NodoProductoAVL() {

}
NodoProductoAVL::NodoProductoAVL(int codigoProductoAVL, string nombreProductoAVL, int stockActualAVL, int precioAVL) {
	this->codigoProductoAVL = codigoProductoAVL;
	this->nombreProductoAVL = nombreProductoAVL;
	this->stockActualAVL = stockActualAVL;
	this->precioAVL = precioAVL;
	this->alturaAVL = 1;
	this->hijoIzqAVL = NULL;
	this->hijoDerAVL = NULL;
	
}

int NodoProductoAVL::getCodigoProductoAVL() {
	return this->codigoProductoAVL;
}
string NodoProductoAVL::getNombreProductoAVL() {
	return this->nombreProductoAVL;
}
int NodoProductoAVL::getStockActualAVL() {
	return this->stockActualAVL;
}
int NodoProductoAVL::getPrecioAVL() {
	return this->precioAVL;
}
int NodoProductoAVL::getAlturaAVL() {

	return this->alturaAVL;
}

void NodoProductoAVL::setCodigoProductoAVL(int codigoProducto) {
	this->codigoProductoAVL = codigoProducto;
}
void NodoProductoAVL::setNombreProductoAVL(string nombreProducto) {
	this->nombreProductoAVL = nombreProducto;
}
void NodoProductoAVL::setStockActualAVL(int stockActual) {
	this->stockActualAVL = stockActual;
}
void NodoProductoAVL::setPrecioAVL(int precio) {
	this->precioAVL = precio;
}
void NodoProductoAVL::setAlturaAVL(int altura) {
	this->alturaAVL = altura;
}
NodoProductoAVL* NodoProductoAVL::getHijoIzqAVL() {
	return this->hijoIzqAVL;
}
NodoProductoAVL* NodoProductoAVL::getHijoDerAVL() {
	return this->hijoDerAVL;
}
void NodoProductoAVL::setHijoIzqAVL(NodoProductoAVL* hijoIzqAVL) {
	this->hijoIzqAVL = hijoIzqAVL;
}
void NodoProductoAVL::setHijoDerAVL(NodoProductoAVL* hijoDerAVL) {
	this->hijoDerAVL = hijoDerAVL;
}
NodoProductoAVL*& NodoProductoAVL::getHijoIzqRefAVL() {
	return this->hijoIzqAVL;
}
NodoProductoAVL*& NodoProductoAVL::getHijoDerRefAVL() {
	return this->hijoDerAVL;
}
void NodoProductoAVL::setHijoIzqRefAVL(NodoProductoAVL*& hijoIzqAVL) {
	this->hijoIzqAVL = hijoIzqAVL;
}
void NodoProductoAVL::setHijoDerRefAVL(NodoProductoAVL*& hijoDerAVL) {
	this->hijoDerAVL = hijoDerAVL;
}