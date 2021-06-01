#ifndef __UNION_FIND__H__
#define __UNION_FIND__H__

#include <iostream>

using namespace std;

class C_weightedUnion{
    public:
        C_weightedUnion();
        ~C_weightedUnion();
        void initArray(int);
        void weightedUnion(int, int);
        void isConnected(int, int);
        void printArray();


    private:
        int *p_dataArray;
        int p_arraySize;
        int *p_weight;

        void p_initArray(int);
        void p_weightedUnion(int, int);
        bool p_isConnected(int, int);
        void p_printArray();
        int p_verifyRange(int, int);
        int p_findRoot(int);

};


#endif