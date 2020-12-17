#pragma once
#include <string>
using namespace std;

class NodoProductoAVL
{
private:
	int codigoProductoAVL;
	string nombreProductoAVL;
	int stockActualAVL;
	int precioAVL; 
	int alturaAVL;
	NodoProductoAVL* hijoIzqAVL;
	NodoProductoAVL* hijoDerAVL;

public:

	NodoProductoAVL();
	NodoProductoAVL(int,string,int,int);
	int getCodigoProductoAVL();
	string getNombreProductoAVL();
	int getStockActualAVL();
	int getPrecioAVL();
	int getAlturaAVL();
	void setCodigoProductoAVL(int);
	void setNombreProductoAVL(string);
	void setStockActualAVL(int);
	void setPrecioAVL(int);
	void setAlturaAVL(int);
	NodoProductoAVL* getHijoIzqAVL();
	NodoProductoAVL* getHijoDerAVL();
	void setHijoIzqAVL(NodoProductoAVL* hijoIzqAVL);
	void setHijoDerAVL(NodoProductoAVL* hijoDerAVL);
	NodoProductoAVL*& getHijoIzqRefAVL();
	NodoProductoAVL*& getHijoDerRefAVL();
	void setHijoIzqRefAVL(NodoProductoAVL*&);
	void setHijoDerRefAVL(NodoProductoAVL*&);
	
};

