#include "UnionFind.h"
#include "customErrorClass.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    C_unionFind myClass;

    try {
         // initialize initArray to a given size
    myClass.initArray(10);
    myClass.printArray();
    myClass.unionNumbers(9, 4);
    myClass.unionNumbers(4, 2);
    myClass.unionNumbers(7, 5);
    myClass.unionNumbers(5, 2);
    myClass.printArray();
    myClass.isConnected(9, 2);
    myClass.isConnected(4, 9);
    myClass.isConnected(5, 4);

    } catch (MyException &e) {
        cout << e.what() << endl;
    }

   

    return 0;
}