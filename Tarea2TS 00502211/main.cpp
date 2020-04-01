#include <fstream>
#include <iostream>
#include "classes.h"

using namespace std;

void readCoordinates(ifstream &file, int n, item* item_list){
    int e; float r;
    for(int i=0; i<n; i++){
      file >> e >> r;
      item_list[i].setIntFloat(e,r);
    }
}


int main() {
    //para leer el nombre del archivo
    char filename[10];
    //variables que serviran para almacenar valores
    string line;
    mesh m;
    ifstream file;
    float k,Q;
    int nnodes,neltos,ndirich,nneu;

    //validacion si hemos escrito bien el nombre del archivo
    do{
        cout << "Ingrese el nombre del archivo: ";
        cin >> filename;
        file.open(filename);
    }while(!file);

    //lee la primera linea del archivo almacenadas en K Q
    file >> k >> Q;
    // numero de nodos, elementos y ambas condiciones
    file >> nnodes >> neltos >> ndirich >> nneu;
    //Para no guardar la condicion de coordinates
    file >> line;

    m.setParameters(k, Q);
    m.setSizes(nnodes, neltos, ndirich, nneu);
    m.createData();

    readCoordinates(file,nnodes,m.getNodes());

    file.close();

    //nos devuelve nodo por nodo (utilizado como arreglo)
    for(int i=0; i<nnodes; i++){
        cout << m.getNode(i).getX();
        cout << endl;
    }
    return 0;
}
