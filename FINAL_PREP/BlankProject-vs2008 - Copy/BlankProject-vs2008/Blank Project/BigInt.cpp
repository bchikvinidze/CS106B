#include "BigInt.h"

BigInt::BigInt(string number)
{
	if(number[0] == '-'){
		isNegative = true;
		
	} else {
		isNegative = false;
		head = new Node;
		for(int i = 0; i < number.size(); i++){
			
		}
	}
}

BigInt::~BigInt()
{
}

string BigInt::toString(){

}
