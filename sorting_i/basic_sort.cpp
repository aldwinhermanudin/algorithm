#include <iostream>

using namespace std;

void Swap(int &a, int &b){

	int c = b;
	b = a;
	a = c;
}

void PrintArray( int* array, int size){
	
	cout << "[";
	for(int i = 0; i < size; i++){
		cout << " " << array[i] << " ";
	}
	cout << "]" << endl;
	
}

void bubble( int *array_unsorted, int array_size ){
	
	for(int i = 1; i < array_size; i++){
		for(int j = i; j > 0; j--){
			if(array_unsorted[j-1] > array_unsorted[j]){
				Swap(array_unsorted[j-1], array_unsorted[j]);
			}
		}
	}	
}

void selection( int *array_unsorted, int array_size ){
	
	for(int i = 0; i < array_size; i++){
		int min_index = i;
		for(int j = i+1; j < array_size; j++){
			if(array_unsorted[j] < array_unsorted[min_index]){
				min_index = j;
			}
		}
		
		if ( min_index != i ){
			Swap(array_unsorted[i],array_unsorted[min_index]);
		}
	}
}

void insertion ( int *array_unsorted, int array_size ){
	
	int hold_number;
	for(int i = 1; i < array_size; i++){
		hold_number = array_unsorted[i];
		for(int j = i-1 ; j >= 0 ; j--){
			if(hold_number < array_unsorted[j]){
				array_unsorted[j+1] = array_unsorted[j];
				array_unsorted[j] = hold_number;				
			}
		}
	} 
}

int main (){
	
	int array_size = 12;
	int array_unsorted1[array_size] = {5,45,1,3,5,-1,0,13,41,17,31,33}; 
	int array_unsorted2[array_size] = {5,45,1,3,5,-1,0,13,41,17,31,33}; 
	int array_unsorted3[array_size] = {5,45,1,3,5,-1,0,13,41,17,31,33}; 
	
	PrintArray( array_unsorted1, array_size );
	cout<< endl << "= Bubble Sort =" << endl;
	bubble( array_unsorted1, array_size );
	PrintArray( array_unsorted1, array_size );
	
	cout<< endl << "= Selection Sort =" << endl;
	selection( array_unsorted2, array_size );
	PrintArray( array_unsorted2, array_size );
	
	cout<< endl << "= Insertion Sort =" << endl;
	insertion( array_unsorted3, array_size );
	PrintArray( array_unsorted3, array_size );
		
	return 0;
}
