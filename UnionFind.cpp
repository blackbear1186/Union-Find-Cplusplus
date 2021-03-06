#include "UnionFind.h"
#include "customErrorClass.h"

using namespace std;

enum RETURN_STATES{
    NO_ERROR, 
    INFO,
    WARNING,
    FAILED,
};

C_unionFind::C_unionFind(){
        this->p_dataArray = NULL;
        this->p_arraySize = 0;
}

C_unionFind::~C_unionFind(){
        delete[] this->p_dataArray;
}
    
void C_unionFind::initArray(int initSize){
    // exception to prevent user from intializing the array more than once
	if(NULL != this->p_dataArray){
        throw MyException("WARNING: Cannot initialize array twice; not re-initializating.");
    } else {
        try {
            this->p_initArray(initSize);

        } catch (MyException &e){
            cout << e.what() << endl;
        }
    }
}

int C_unionFind::p_find(int num){
    while( num != this->p_dataArray[num]){
        num = this->p_dataArray[num];
    }
    return num;
}

void C_unionFind::unionNumbers(int numOne, int numTwo){

    int rootNum1 = this->p_find(numOne);
    int rootNum2 = this->p_find(numTwo);

    int retValue = 0;
    // set retValue equal to value return from verifyRange based
    // on sucess or failure integer (-1 for failure, 0 for success)
    retValue = this->p_verifyRange(numOne, numTwo);

    // If retValue does not equal 0(success integer from verifyRange)
    // throw Exception, otherwise call union function
    if( 0 != retValue){
        throw MyException("ERROR: Provided value(s) is not in range of array.");
    } else {
            // If the two elements enter have the same value ignore
            if(rootNum1 == rootNum2){
                return;
            }
            // if the numbers are less the array size call union function
            this->p_unionNumbers(numOne, numTwo);

    }

    if(numOne < this->p_arraySize){
        if(numTwo < this->p_arraySize){
        } else {
            
            throw MyException("ERROR: Second value outside bounds of array.");                     
        }
    } else {
        throw MyException("ERROR: First value outside the bounds of the array.");
    }
}

void C_unionFind::isConnected(int numOne, int numTwo){

    bool verifyConnection = false;

	int retValue = 0;
    // set retValue equal to value return from verifyRange based
    // on sucess or failure integer (-1 for failure, 0 for success)
    retValue = this->p_verifyRange(numOne, numTwo);

    // If retValue does not equal 0(success integer from verifyRange)
    // throw Exception, otherwise call union function
    if( 0 != retValue){
        throw MyException("ERROR: Provided value(s) is not in range of array.");
    } else {
        // set verifyConnection equal to boolean returned from p_isConnected
        verifyConnection = this->p_isConnected(numOne, numTwo);

        if(verifyConnection){
            cout << numOne << " and " << numTwo << " are: CONNECTED" << endl;
        } else {
            cout << numOne << " and " << numTwo << " are: NOT CONNECTED" << endl;
        }

    }

}

void C_unionFind::printArray(){
	if(NULL == this->p_dataArray){
        throw MyException("WARNING: No array to print.");
    } else {
        this->p_printArray();
    }
}


void C_unionFind::p_initArray(int initSize){
	if( 0 > initSize){
        throw MyException("ERROR: Cannot create array with negative value.");
    } else {
        // create p_dataArray and dynamic store in memory
        this->p_dataArray = new int[initSize];

        // set p_arraySize equal to array size input by user as parameter
        this->p_arraySize = initSize;

        //Or use this syntax
        /*
            this->p_arraySize = initSize;
            this->p_dataArray = new[this->p_arraySize]
        */

        for(int index = 0; index < this->p_arraySize; ++index){
            this->p_dataArray[index] = index;
        }
    }
}

void C_unionFind::p_unionNumbers(int numOne, int numTwo){

    for (int index = 0; index < this->p_arraySize; ++index){
        // if p_dataArray[index] equals numTwo, then assign that value in
        if(this->p_dataArray[index] == numOne){
            this->p_dataArray[index] = numTwo;
            // connected INDEX to numTwonumOne for debugging

        }
    }
	
    this->p_dataArray[numOne] = numTwo;


}

bool C_unionFind::p_isConnected(int numOne, int numTwo){
    bool connectionVerified = false;

    // if the value of numOne equals to numTwo return true
	if(this->p_find(numOne) == this->p_find(numTwo)){
        connectionVerified = true;
    }

    return connectionVerified;
}

void C_unionFind::p_printArray(){
	for(int index = 0; index < this->p_arraySize; ++index){
        cout << "array["<<index<<"] = "<< this->p_dataArray[index] << endl;
    }
}

int C_unionFind::p_verifyRange(int numOne, int numTwo){

    // negative one is a failure condition
    int retVal = -1;
    // if both numbers are less than the p_arraySize success
    // else negative is return as failure
    if(numOne < this->p_arraySize){
        if(numTwo < this->p_arraySize){
            // zero is a success condition
            retVal = 0;
        } 
    }
    return retVal;
}