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
    myClass.printArray();
    myClass.isConnected(9, 2);
    myClass.isConnected(3, 2);

    } catch (MyException &e) {
        cout << e.what() << endl;
    }

   

    return 0;
}