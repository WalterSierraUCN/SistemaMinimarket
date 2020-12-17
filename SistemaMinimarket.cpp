#include "SistemaMinimarket.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>


/**
*
* **************************************** ARBOL BINARIO DE BUSQUEDA ***************************************    
* Funcion para leer el archivo .txt
*/
    
 SistemaMinimarket::SistemaMinimarket() {
     this->raiz = NULL;
     this->raizAVL = NULL;

}
 
 nodoProducto* SistemaMinimarket::getArbol() {
     return this->raiz;
 }
 
 
 void SistemaMinimarket::lecturaArchivo() {

    string linea;
    string codigoProducto="";
    string nombreProducto="";
    string stockActual="";
    string valor="";

    ifstream archivoTxt;
    archivoTxt.open("Productos.txt");

    while (getline(archivoTxt, linea)) {

        stringstream ss(linea);
            
        while (!ss.eof()) {
            getline(ss, codigoProducto, ',');
            getline(ss, nombreProducto, ',');
            getline(ss, stockActual, ',');
            getline(ss, valor, ',');


            int codigo = stoi(codigoProducto);
            int precio = stoi(valor);
            int stock = stoi(stockActual);


            
            

             insertarProducto(codigo, stock, nombreProducto, precio);
             this->raizAVL = insert(this->raizAVL, codigo, nombreProducto, stock, precio);
             
        }
    }

}

/**
Funcion que inserta un nodo por la izquierda o por la derecha dependiendo del numero del codigo del producto.
*/
void SistemaMinimarket::insertarProducto(int codigoProducto, int stockProducto, string nombreProducto, int precio) {

    insertarProductoRec(this->raiz, codigoProducto, stockProducto, nombreProducto, precio);
    
}
void SistemaMinimarket::insertarProductoRec(nodoProducto*& arbol, int codigoProducto, int stockProducto, string nombreProducto, int precio) {
    if (!arbol) {
        arbol = new nodoProducto(codigoProducto, nombreProducto, stockProducto, precio);
    }
    else if (codigoProducto == arbol->getCodigoProducto()) {
        return;
    }
    else if (codigoProducto < arbol->getCodigoProducto()) {
        return insertarProductoRec(arbol->getHijoIzqRef(), codigoProducto, stockProducto, nombreProducto, precio);
    }
    else {
        return insertarProductoRec(arbol->getHijoDerRef(), codigoProducto, stockProducto, nombreProducto, precio);
    }
}

void SistemaMinimarket::imprimirArbol(nodoProducto* nodo) {
    if (nodo != NULL) {
        imprimirArbol(nodo->getHijoIzq());
        cout << nodo->getCodigoProducto() << " ";
        imprimirArbol(nodo->getHijoDer());
    }
}

bool SistemaMinimarket ::buscarProducto(nodoProducto* nodo, int codigoProductoBuscar){
    if(!nodo){
        return false;
	}else if(nodo->getCodigoProducto() == codigoProductoBuscar){
        cout << "El producto del ABB: " << endl;
        cout << nodo->getCodigoProducto() << ", " << nodo->getNombreProducto() << ", " << nodo->getStockActual() << ", " << nodo->getPrecio() << endl;
            return true;

	}else if(nodo->getCodigoProducto() > codigoProductoBuscar){
        return buscarProducto(nodo->getHijoIzq(), codigoProductoBuscar);

	}else if(nodo->getCodigoProducto() < codigoProductoBuscar){
        return buscarProducto(nodo->getHijoDer(), codigoProductoBuscar);
	}

    return false;
}


nodoProducto* minimo(nodoProducto* arbol) {
    while (arbol->getHijoIzq() != NULL) {
        arbol = arbol->getHijoIzq();
    }
    return arbol;
}

nodoProducto* SistemaMinimarket::eliminarNodoxd(nodoProducto* nodoProducto, int codigoProductoBorrar) {

    // 0 hijos 
    if (nodoProducto==NULL) {
        return nodoProducto;
    }

    // si tiene 2 hijos
    else if (codigoProductoBorrar < nodoProducto->getCodigoProducto()) {
        nodoProducto->setHijoIzq(eliminarNodoxd(nodoProducto->getHijoIzq(), codigoProductoBorrar));
    }
    else if (codigoProductoBorrar > nodoProducto->getCodigoProducto()) {
        nodoProducto->setHijoDer(eliminarNodoxd(nodoProducto->getHijoDer(), codigoProductoBorrar));
    }
    else {

            if (nodoProducto->getHijoDer()==NULL && nodoProducto->getHijoIzq()==NULL    ) {
                delete nodoProducto;
                nodoProducto = NULL;
                return nodoProducto;    
            }
            else if(nodoProducto->getHijoIzq()==NULL){

                struct nodoProducto* temp=nodoProducto;
                nodoProducto = nodoProducto->getHijoDer();
                delete temp;
                return nodoProducto;

            }
            else if (nodoProducto->getHijoDer() == NULL) {
                struct nodoProducto* temp = nodoProducto;
                nodoProducto = nodoProducto->getHijoIzq();
                delete temp;
                return nodoProducto;
            }
            else {
                struct nodoProducto* temp = minimo(nodoProducto->getHijoDer());
                nodoProducto->setCodigoProducto(temp->getCodigoProducto());
                nodoProducto->setHijoDer(eliminarNodoxd(nodoProducto->getHijoDer(), temp->getCodigoProducto()));
            }
            
    }
    return nodoProducto;
}


void SistemaMinimarket::inPreorder(nodoProducto* root) //function for ptinting the BST in pre-order
{
    if (root == NULL) {
        return;
    }
    
    cout << root->getCodigoProducto()<<", " <<root->getNombreProducto()<<", "<<root->getStockActual()<<", "<<"$"<<root->getPrecio() <<"." "\n";

    
    inPreorder(root->getHijoIzq());

    
    inPreorder(root->getHijoDer());
};
		
//**************************************************** AVL ********************************************************************

NodoProductoAVL* SistemaMinimarket::getArbolAVL() {
    return this->raizAVL;
}
void SistemaMinimarket::setArbolAVL(NodoProductoAVL* nuevaRaiz) {
    this->raizAVL = nuevaRaiz;
}

int SistemaMinimarket::Altura(NodoProductoAVL* t) {
    int h = 0;
    if (t != NULL) {
        int l_height = Altura(t->getHijoIzqAVL());
        int r_height = Altura(t->getHijoDerAVL());
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int height2(NodoProductoAVL* N)
{
    if (N == NULL)
        return 0;
    return N->getAlturaAVL();
}
int SistemaMinimarket::difference(NodoProductoAVL* t) {
    int l_height = Altura(t->getHijoIzqAVL());
    int r_height = Altura(t->getHijoDerAVL());
    int b_factor = l_height - r_height;
    return b_factor;
}
NodoProductoAVL* SistemaMinimarket::rr_rotat(NodoProductoAVL* parent) {
    NodoProductoAVL* t;
    t = parent->getHijoDerAVL();
    parent->setHijoDerAVL(t->getHijoIzqAVL());
    t->setHijoIzqAVL(parent);
    return t;
}
NodoProductoAVL* SistemaMinimarket::ll_rotat(NodoProductoAVL* parent) {
    NodoProductoAVL* t;
    t = parent->getHijoIzqAVL();
    parent->setHijoIzqAVL(t->getHijoDerAVL());
    t->setHijoDerAVL(parent);
    return t;
}
NodoProductoAVL* SistemaMinimarket::lr_rotat(NodoProductoAVL* parent) {
    NodoProductoAVL* t;
    t = parent->getHijoIzqAVL();
    parent->setHijoIzqAVL(rr_rotat(t));
    return ll_rotat(parent);
}
NodoProductoAVL* SistemaMinimarket::rl_rotat(NodoProductoAVL* parent) {
    NodoProductoAVL* t;
    t = parent->getHijoDerAVL();
    parent->setHijoDerAVL(ll_rotat(t));
    return rr_rotat(parent);
}
NodoProductoAVL* SistemaMinimarket::balance(NodoProductoAVL* t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->getHijoIzqAVL()) > 0)
            t = ll_rotat(t);
        else
            t = lr_rotat(t);
    }
    else if (bal_factor < -1) {
        if (difference(t->getHijoDerAVL()) > 0)
            t = rl_rotat(t);
        else
            t = rr_rotat(t);
    }
    return t;
}
NodoProductoAVL* SistemaMinimarket::insert(NodoProductoAVL* r, int codigo, string nombre, int stock, int precio) {
    if (r == NULL) {
        r = new NodoProductoAVL(codigo, nombre, stock, precio);
        return r;
    }
    else if (codigo < r->getCodigoProductoAVL()) {
        r->setHijoIzqAVL(insert(r->getHijoIzqAVL(), codigo, nombre, stock, precio));
        r = balance(r);
    }
    else if (codigo >= r->getCodigoProductoAVL()) {
        r->setHijoDerAVL(insert(r->getHijoDerAVL(), codigo, nombre, stock, precio));
        r = balance(r);
    } return r;
}
void SistemaMinimarket::show(NodoProductoAVL* p, int l) {
    int i;
    if (p != NULL) {
        show(p->getHijoDerAVL(), l + 1);
        cout << " ";
        if (p == this->raizAVL)
            cout << "Raiz -> ";
        for (i = 0; i < l && p != this->raizAVL; i++)
            cout << " ";
        cout << p->getCodigoProductoAVL();
        show(p->getHijoIzqAVL(), l + 1);
    }
}
void SistemaMinimarket::inorder(NodoProductoAVL* t) {
    if (t == NULL)
        return;
    inorder(t->getHijoIzqAVL());
    cout << t->getCodigoProductoAVL() << " ";
    inorder(t->getHijoDerAVL());
}
void SistemaMinimarket::preorder(NodoProductoAVL* t) {
    if (t == NULL)
        return;
    cout << t->getCodigoProductoAVL() << " ";
    preorder(t->getHijoIzqAVL());
    preorder(t->getHijoDerAVL());
}
void SistemaMinimarket::postorder(NodoProductoAVL* t) {
    if (t == NULL)
        return;
    postorder(t->getHijoIzqAVL());
    postorder(t->getHijoDerAVL());
    cout << t->getCodigoProductoAVL() << " ";
}
bool SistemaMinimarket::buscarProductoAVL(NodoProductoAVL* raizAVL, int codigoProductoBuscar) {

    if (!raizAVL) {
        return false;
    }
    else if (raizAVL->getCodigoProductoAVL() == codigoProductoBuscar) {
        cout << "Producto del AVL: " << endl;
        cout << raizAVL->getCodigoProductoAVL() <<", "<<raizAVL->getNombreProductoAVL()<<", "<<raizAVL->getStockActualAVL()<<", "<<raizAVL->getPrecioAVL() << endl;
        return true;

    }
    else if (raizAVL->getCodigoProductoAVL() > codigoProductoBuscar) {
        return buscarProductoAVL(raizAVL->getHijoIzqAVL(), codigoProductoBuscar);

    }
    else if (raizAVL->getCodigoProductoAVL() < codigoProductoBuscar) {
        return buscarProductoAVL(raizAVL->getHijoDerAVL(), codigoProductoBuscar);
    }

    return false;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
NodoProductoAVL* minValueNode(NodoProductoAVL* node)
{
    NodoProductoAVL* current = node;

    /* loop down to find the leftmost leaf */
    while (current->getHijoIzqAVL() != NULL)
        current = current->getHijoIzqAVL();

    return current;
}
// A utility function to right 
// rotate subtree rooted with y  
// See the diagram given above.  
NodoProductoAVL* rightRotate(NodoProductoAVL* y)
{
    NodoProductoAVL* x = y->getHijoIzqAVL();
    NodoProductoAVL* T2 = x->getHijoDerAVL();

    // Perform rotation  
    x->setHijoDerAVL(y);
    y->setHijoIzqAVL(T2);

    // Update heights  
    y->setAlturaAVL(max(height2(y->getHijoIzqAVL()),
        height2(y->getHijoDerAVL())) + 1);
    x->setAlturaAVL(max(height2(x->getHijoIzqAVL()),
        height2(x->getHijoDerAVL())) + 1);

    // Return new root  
    return x;
}

// A utility function to left  
// rotate subtree rooted with x  
// See the diagram given above.  
NodoProductoAVL* leftRotate(NodoProductoAVL* x)
{
    NodoProductoAVL* y = x->getHijoDerAVL();
    NodoProductoAVL* T2 = y->getHijoIzqAVL();

    // Perform rotation  
    y->setHijoIzqAVL( x);
    x->setHijoDerAVL(T2);

    // Update heights  
    x->setAlturaAVL(max(height2(x->getHijoIzqAVL()),
        height2(x->getHijoDerAVL())) + 1);
    y->setAlturaAVL(max(height2(y->getHijoIzqAVL()),
        height2(y->getHijoDerAVL())) + 1);

    // Return new root  
    return y;
}
// Get Balance factor of node N  
int getBalance(NodoProductoAVL* N)
{
    if (N == NULL)
        return 0;
    return height2(N->getHijoIzqAVL()) -
        height2(N->getHijoDerAVL());
}
NodoProductoAVL* SistemaMinimarket::deleteNode(NodoProductoAVL* root, int codigo)
{

    // STEP 1: PERFORM STANDARD BST DELETE  
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller  
    // than the root's key, then it lies 
    // in left subtree  
    if (codigo < root->getCodigoProductoAVL())
        root->setHijoIzqAVL(deleteNode(root->getHijoIzqAVL(), codigo));

    // If the key to be deleted is greater  
    // than the root's key, then it lies  
    // in right subtree  
    else if (codigo > root->getCodigoProductoAVL())
        root->setHijoDerAVL(deleteNode(root->getHijoDerAVL(), codigo));

    // if key is same as root's key, then  
    // This is the node to be deleted  
    else
    {
        // node with only one child or no child  
        if ((root->getHijoIzqAVL() == NULL) ||
            (root->getHijoDerAVL() == NULL))
        {
            NodoProductoAVL* temp = root->getHijoIzqAVL() ?
                root->getHijoIzqAVL() :
                root->getHijoDerAVL();

            // No child case  
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case  
                *root = *temp; // Copy the contents of  
                               // the non-empty child  
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder  
            // successor (smallest in the right subtree)  
            NodoProductoAVL* temp = minValueNode(root->getHijoDerAVL());

            // Copy the inorder successor's  
            // data to this node  
            root->setCodigoProductoAVL(temp->getCodigoProductoAVL());

            // Delete the inorder successor  
            root->setHijoDerAVL(deleteNode(root->getHijoDerAVL(),
                temp->getCodigoProductoAVL()));
        }
    }

    // If the tree had only one node 
    // then return  
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  
    root->setAlturaAVL(1 + max(height2(root->getHijoIzqAVL()),
        height2(root->getHijoDerAVL())));

    // STEP 3: GET THE BALANCE FACTOR OF  <
    // THIS NODE (to check whether this  
    // node became unbalanced)  
    int balance = getBalance(root);

    // If this node becomes unbalanced,  
    // then there are 4 cases  

    // Left Left Case  
    if (balance > 1 &&
        getBalance(root->getHijoIzqAVL()) >= 0)
        return rightRotate(root);

    // Left Right Case  
    if (balance > 1 &&
        getBalance(root->getHijoIzqAVL()) < 0)
    {
        root->setHijoIzqAVL(leftRotate(root->getHijoIzqAVL()));
        return rightRotate(root);
    }

    // Right Right Case  
    if (balance < -1 &&
        getBalance(root->getHijoDerAVL()) <= 0)
        return leftRotate(root);

    // Right Left Case  
    if (balance < -1 &&
        getBalance(root->getHijoDerAVL()) > 0)
    {
        root->setHijoDerAVL(rightRotate(root->getHijoDerAVL()));
        return leftRotate(root);
    }

    return root;
}