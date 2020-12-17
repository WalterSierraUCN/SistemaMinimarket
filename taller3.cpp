// taller3.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "SistemaMinimarket.h"
#include <ctime>
#pragma once

using namespace std;



void agregarNuevoProducto(SistemaMinimarket* sistema) {
    unsigned t1, t2, t3, t4;
    cout << "ingrese los siguientes datos del producto nuevo: " << endl;
    cout << "codigo de producto: ";
    int codigoProducto;
    cin >> codigoProducto;
    cout << "nombre del producto: ";
    string nombreProducto;
    cin >> nombreProducto;
    cout << "stock del producto: ";
    int stockProducto;
    cin >> stockProducto;
    cout << "precio del producto: ";
    int precio;
    cin >> precio;
    t1 = clock();
   sistema->insertarProducto(codigoProducto, stockProducto, nombreProducto, precio);
   t2 = clock();
   long double tiempoABB = (long double(t2 - t1) / CLOCKS_PER_SEC);
   cout << "Tiempo de ejecucion del ABB: " << tiempoABB << endl;
   t3 = clock();
   sistema->setArbolAVL(sistema->insert(sistema->getArbolAVL(), codigoProducto, nombreProducto, stockProducto, precio));
   t4 = clock();
   long double tiempoAVL = (long double(t4 - t3) / CLOCKS_PER_SEC);
   cout << "Tiempo de ejecucion del AVL: " << tiempoAVL << endl;

}


void menuInicial(SistemaMinimarket* sistema) {

    cout << "Bienvenido al Minimarket" << endl;
    cout << "------------------------" << endl;
    cout << "1. Agregar Producto " << endl;
    cout << "2. Eliminar Producto " << endl;
    cout << "3. Consultar Producto " << endl;
    cout << "4. Listar Productos " << endl;
    cout << "5. Salir " << endl;
    string respuesta;
     cin >> respuesta;
     if (atoi(respuesta.c_str())) {
         while (true) {

             switch (atoi(respuesta.c_str())) {

             case 1:
                 agregarNuevoProducto(sistema);
                 menuInicial(sistema);
                 break;
             case 2:
                 cout << "ingrese codigo de producto: " << endl;
                 int codigoProducto;
                 cin >> codigoProducto;
                 sistema->eliminarNodoxd(sistema->getArbol(), codigoProducto);
                 sistema->setArbolAVL(sistema->deleteNode(sistema->getArbolAVL(), codigoProducto));
                 menuInicial(sistema);
                 break;
             case 3:
                 cout << "inserte codigo de producto a buscar: " << endl;
                 int codigo;
                 cin >> codigo;
                 if (sistema->buscarProducto(sistema->getArbol(), codigo)) {
                     cout << " " << endl;
                 }
                 if(sistema->buscarProductoAVL(sistema->getArbolAVL(), codigo)) {
                     cout << " " << endl;
                 }
                 else {
                     cout << "No se ha encontrado el producto. " << endl;
                 }
                 menuInicial(sistema);
                 break;
             case 4:
                 cout << "---------- ABB ----------" << endl;

                 cout << " INORDER " << endl;
                 sistema->imprimirArbol(sistema->getArbol());
                 cout << endl;
                 cout << " PREORDER " << endl;
                 sistema->preorder(sistema->getArbolAVL());
                 cout << endl;


                 cout << "---------- AVL ----------" << endl;
                 if (sistema->getArbolAVL()== NULL) {
                     cout << "El arbol AVL esta vacio. " << endl;
                     continue;
                 }
                 cout << "AVL :" << endl;
                 sistema->show(sistema->getArbolAVL(), 1);
                 cout << endl;
                 cout << " INORDER " << endl;
                 sistema->inorder(sistema->getArbolAVL());
                 cout << endl;
                 cout << " PREORDER " << endl;
                 sistema->preorder(sistema->getArbolAVL());
                 cout << endl;
                 cout << " POSTORDER " << endl;
                 sistema->postorder(sistema->getArbolAVL());

                 menuInicial(sistema);
                 break;
             case 5:
                 exit(0);

             default:
                 cout << "ingrese opcion valida. " << endl;
                 menuInicial(sistema);
                 break;
             }
         }
     }
     else {
         cout << "ingrese una opcion valida. " << endl;
         cout << "_______________________________" << endl;
         menuInicial(sistema);
     }
}


int main()
{   
    
    SistemaMinimarket* sistema= new SistemaMinimarket();
    sistema->lecturaArchivo();
    menuInicial(sistema);


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
