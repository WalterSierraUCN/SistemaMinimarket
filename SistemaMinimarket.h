#pragma once

#include <fstream>
#include <sstream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "nodoProducto.h"
#include "NodoProductoAVL.h"
#include <iostream>



class SistemaMinimarket
{
private:
	nodoProducto* raiz;
	NodoProductoAVL* raizAVL;
public:
	SistemaMinimarket();
	// ARBOL ABBB
	nodoProducto* getArbol();
	void lecturaArchivo();
	void insertarProducto(int,int,string,int);
	void insertarProductoRec(nodoProducto*&, int, int, string, int);
	bool buscarProducto(nodoProducto*, int);
	void imprimirArbol(nodoProducto*);
	nodoProducto* eliminarNodoxd(nodoProducto*, int);
	void inPreorder(nodoProducto*);
	// ARBOL AVL

	NodoProductoAVL* getArbolAVL();
	void setArbolAVL(NodoProductoAVL*);
	int Altura(NodoProductoAVL* t);
	int difference(NodoProductoAVL* t);
	NodoProductoAVL* rr_rotat(NodoProductoAVL* parent);
	NodoProductoAVL* ll_rotat(NodoProductoAVL* parent);
	NodoProductoAVL* lr_rotat(NodoProductoAVL* parent);
	NodoProductoAVL* rl_rotat(NodoProductoAVL* parent);
	NodoProductoAVL* balance(NodoProductoAVL*);
	NodoProductoAVL* insert(NodoProductoAVL*, int, string, int, int);
	void show(NodoProductoAVL*, int);
	void inorder(NodoProductoAVL*);
	void preorder(NodoProductoAVL*);
	void postorder(NodoProductoAVL*);
	bool buscarProductoAVL(NodoProductoAVL*,int);
	NodoProductoAVL* deleteNode(NodoProductoAVL*, int);
};

