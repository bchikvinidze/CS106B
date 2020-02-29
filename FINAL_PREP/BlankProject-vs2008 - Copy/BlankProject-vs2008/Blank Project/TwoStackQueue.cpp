#include "TwoStackQueue.h"


TwoStackQueue::TwoStackQueue(){
	allocLength = START_SIZE;
	inLength = 0;
	outLength = 0;
	arr = new int[START_SIZE];
}

TwoStackQueue::~TwoStackQueue(){
	delete []arr;
}

void TwoStackQueue::enqueue(int value){
	if(inLength >= allocLength - outLength){ // e.i. adgili agar maq
		allocLength *= 2;
		int *copy = new int[allocLength];
		for(int i = 0; i < inLength; i++){// gadavakopirot in stack;
			copy[i] = arr[i];
		}
		for(int i = allocLength/2; i > allocLength/2 - outLength; i--){ // gadavakopirot out stack;
			copy[i*2] = arr[i];
		}
		delete []arr;
		arr = copy;
	}
	arr[inLength] = value;
	inLength++;
}
int TwoStackQueue::dequeue(){
	/*for(int i = 0; i < allocLength; i++){
		cout << arr[i] << endl;
	}
	cout << "-------" << endl;*/
	if(outLength > 0){
		int result = arr[allocLength - outLength];
		outLength--;
		return result;
	} else {
		if(inLength > allocLength/2){
			allocLength *= 2;
			int *copy = new int[allocLength];
			for(int i = 0; i < inLength; i++){// gadavakopirot in stack;
				copy[i] = arr[i];
			}
			delete []arr;
			arr = copy;
		}
		for(int i = 0; i < inLength; i++){
			arr[allocLength - 1 - i] = arr[i];
			outLength++;
		}
		inLength = 0;
		return dequeue();
	}
}
int TwoStackQueue::size(){
	return inLength + outLength;
}
bool TwoStackQueue::isEmpty(){
	return size() == 0;
}