#pragma once
#include <string>

using namespace std;
class nodoProducto
{
private:
	int codigoProducto;
	string nombreProducto;
	int stockActual;
	int precio;
	nodoProducto* hijoIzq;
	nodoProducto* hijoDer;



public:
	nodoProducto();
	nodoProducto(int,string,int,int);	
	int getCodigoProducto();
	string getNombreProducto();
	int getStockActual();
	int getPrecio();
	void setCodigoProducto(int);
	void setNombreProducto(string);
	void setStockActual(int);
	void setPrecio(int);
	nodoProducto* getHijoIzq();
	nodoProducto* getHijoDer();
	void setHijoIzq(nodoProducto* hijoIzq);
	void setHijoDer(nodoProducto* hijoDer);
	nodoProducto*& getHijoIzqRef();
	nodoProducto*& getHijoDerRef();
};