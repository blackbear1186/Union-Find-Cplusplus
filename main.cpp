#include "UnionFind.h"
#include "weightedUnion.h"
#include "customErrorClass.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){

    //C_unionFind myClass;
    C_weightedUnion myClass;

    try {
         // initialize initArray to a given size
    myClass.initArray(10);
    //myClass.printArray();
    myClass.weightedUnion(9, 4);
    myClass.weightedUnion(4, 2);
    myClass.weightedUnion(5, 9);
    myClass.weightedUnion(7, 5);

    myClass.printArray();
    myClass.isConnected(9, 2);
    myClass.isConnected(4, 9);
    myClass.isConnected(5, 4);

    } catch (MyException &e) {
        cout << e.what() << endl;
    }

   

    return 0;
}