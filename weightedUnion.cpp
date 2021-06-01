#include "weightedUnion.h"
#include "customErrorClass.h"

using namespace std;

enum RETURN_STATES{
    NO_ERROR, 
    INFO,
    WARNING,
    FAILED,
};

C_weightedUnion::C_weightedUnion(){
        this->p_dataArray = NULL;
        this->p_weight = NULL;
        this->p_arraySize = 0;
}

C_weightedUnion::~C_weightedUnion(){
        delete[] this->p_dataArray;
}
    
void C_weightedUnion::initArray(int initSize){
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

int C_weightedUnion::p_findRoot(int num){
    /*
    while( num != this->p_dataArray[num]){
        num = this->p_dataArray[num];
    }
    return num;
    */

   if (num == this->p_dataArray[num]){
       return num;
   } else {
       int root = 0;
       root = p_findRoot(this->p_dataArray[num]);
       return root;
   }
}

void C_weightedUnion::weightedUnion(int numOne, int numTwo){

    int retValue = 0;
    // set retValue equal to value return from verifyRange based
    // on sucess or failure integer (-1 for failure, 0 for success)
    retValue = this->p_verifyRange(numOne, numTwo);

    // If retValue does not equal 0(success integer from verifyRange)
    // throw Exception, otherwise call union function
    if( 0 != retValue){
        throw MyException("ERROR: Provided value(s) is not in range of array.");
    } else {
            // if the numbers are less the array size call union function
            this->p_weightedUnion(numOne, numTwo);

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

void C_weightedUnion::isConnected(int numOne, int numTwo){

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

void C_weightedUnion::printArray(){
	if(NULL == this->p_dataArray){
        throw MyException("WARNING: No array to print.");
    } else {
        this->p_printArray();
    }
}


void C_weightedUnion::p_initArray(int initSize){
	if( 0 > initSize){
        throw MyException("ERROR: Cannot create array with negative value.");
    } else {
        // create p_dataArray and dynamic store in memory
        this->p_dataArray = new int[initSize];
        // Create p_weight array to keep track of the size of each tree
        this->p_weight = new int[initSize];

        // set p_arraySize equal to array size input by user as parameter
        this->p_arraySize = initSize;

        //Or use this syntax
        /*
            this->p_arraySize = initSize;
            this->p_dataArray = new[this->p_arraySize]
        */

        // initializes empty p_dataArray and p_weight array with n through n - 1 elements.
        for(int index = 0; index < this->p_arraySize; ++index){
            this->p_dataArray[index] = index;
            this->p_weight[index] = 0;
        }
    }
}

void C_weightedUnion::p_weightedUnion(int numOne, int numTwo){

    int rootNum1 = this->p_findRoot(numOne);
    int rootNum2 = this->p_findRoot(numTwo);

    // if rootNum1 tree is smaller or equal to rootNum2 tree, then merge rootNum1 tree with rootNum2 tree
    if(this->p_weight[rootNum1] <= this->p_weight[rootNum2]){
        this->p_dataArray[rootNum1] = rootNum2;

        // if the size of root number 1 is equal to zero, set rootNum2 to 1
        if( 0 == this->p_weight[rootNum1]){
            this->p_weight[rootNum2] = 1;
        } else {
            // increase size of root number 2 by size of root number 1 and subtract 1
            this->p_weight[rootNum2] += this->p_weight[rootNum1] - 1;
        }
    } else {
        // if rootNum1 tree is greater than rootNum2, then merge rootNum2 tree with rootNum1 tree
        this->p_dataArray[rootNum2] = rootNum1;

        if(0 == this->p_weight[rootNum2]){
            this->p_weight[rootNum1] = 1;
        } else {
            this->p_weight[rootNum1] += this->p_weight[rootNum2] - 1;
        }
    }
    return;
}

bool C_weightedUnion::p_isConnected(int numOne, int numTwo){
    bool connectionVerified = false;

    // if the value of numOne equals to numTwo return true
	if(this->p_findRoot(numOne) == this->p_findRoot(numTwo)){
        connectionVerified = true;
    }

    return connectionVerified;
}

void C_weightedUnion::p_printArray(){
	for(int index = 0; index < this->p_arraySize; ++index){
        cout << "array["<<index<<"] = "<< this->p_dataArray[index] << endl;
    }
}

int C_weightedUnion::p_verifyRange(int numOne, int numTwo){

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