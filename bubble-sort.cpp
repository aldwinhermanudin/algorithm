#include <iostream>
using namespace std;

void Swap(int* a, int* b);
void PrintArray( int* array, int size);

int main(){
	

	int array_size = 12;
	int array_unsorted[array_size] = {5,45,1,3,5,-1,0,13,41,17,31,33}; 
	
	for(int i = 0; i < array_size; i++){
				
		if(array_unsorted[i+1] < array_unsorted[i]){
			Swap(array_unsorted+i, array_unsorted+(i+1));
			for(int j = i; j > 0; j--){
				if(array_unsorted[j] < array_unsorted[j-1]){
					Swap(array_unsorted+j, array_unsorted+(j-1));
				}
			}
		}

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
