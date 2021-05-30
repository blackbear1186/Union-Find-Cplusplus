#ifndef __UNION_FIND__H__
#define __UNION_FIND__H__

#include <iostream>

using namespace std;

class C_unionFind{
    public:
        C_unionFind();
        ~C_unionFind();
        void initArray(int);
        void unionNumbers(int, int);
        void isConnected(int, int);
        void printArray();

    private:
        int *p_dataArray;
        int p_arraySize;

        void p_initArray(int);
        void p_unionNumbers(int, int);
        bool p_isConnected(int, int);
        void p_printArray();
        int p_verifyRange(int, int);

};


#endif