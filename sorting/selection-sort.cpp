#include <iostream>
#include <limits.h>
using namespace std;

void Swap(int* a, int* b);
void PrintArray( int* array, int size);

int main(){
	

	int array_size = 12;
	int array_unsorted[array_size] = {5,1,3,5,-1,0,13,41,17,45,31,33}; 
	
	for(int i = 0; i < array_size; i++){
		int min = INT_MAX;
		int min_index;
		for(int j = i; j < array_size; j++){
			if(array_unsorted[j] < min){
				min = array_unsorted[j];
				min_index = j;
			}
		}
		Swap(array_unsorted+i,array_unsorted+min_index);
	}
	PrintArray(array_unsorted, 12);
		

	return 0;
}
void Swap(int* a, int* b){

	int c = *b;
	*b = *a;
	*a = c;
}

void PrintArray( int* array, int size){
	
	for(int i = 0; i < size; i++){
		cout << array[i] << endl;
	}
	
}
