#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
			
	public :
	
		int *compute( int* input, int input_size ){
		
			int* merged_array = new int[input_size];
			int *arr_left = NULL, *arr_right = NULL, *arr_temp = NULL;
			
			if ( input_size < 2 ) return NULL; // safety check
			if ( input_size  == 2 ){
				
				arr_temp = merge(input, 1, input+1, 1);
			}
			else if ( input_size == 3){
					
				arr_right = compute(input+1, 2);
				arr_temp = merge(input, 1, arr_right ,2);
			}				
			else{
					
				int left = input_size / 2;
				int right = input_size - left;
					
				arr_left = compute(input, left);
				arr_right = compute(input+left,right);
				arr_temp = merge(arr_left, left, arr_right,right);			
			}
				
			copy(arr_temp, arr_temp+input_size, merged_array);
			delete []arr_left;
			delete []arr_right;
			delete []arr_temp;
			return merged_array;
		}
		 
		int *merge( int *array1, int size_array1, int *array2, int size_array2 ){
			
			int size_merged_array = size_array1+size_array2;
			int *merged_array = new int[size_array1+size_array2]; 
			
			int i,j = 0,k = 0;
			for( i = 0; i < size_merged_array; i++ ){
				
				if ( j < size_array1 && k < size_array2 ){
					if( array1[j] < array2[k] ){
						merged_array[i] = array1[j];
						j++;
					}	
					else {
						merged_array[i] = array2[k];
						k++;
					}
				}
				else {
					
					if( j != size_array1 ){
						merged_array[i] = array1[j];
						j++;
					}
					else if( k != size_array2 ){
						merged_array[i] = array2[k];
						k++;						
					}
					
				}
			}
			
			return merged_array;
		}
	
};

int main(){
	
	MergeSort test;
	int array1[1] = {12};
	int array2[5] = {6,7,8,9,10};
	int array3[] = {6,7,-2,1,76,123,90,1238,9,10};
	
	for ( int i = 0; i < 10; i++ ){
		
		cout << array3[i] << " ";
	}
	cout << endl;
	int *merged_array = test.compute(array3, 10);

	for ( int i = 0; i < 10; i++ ){
		
		cout << merged_array[i] << " ";
	}
	cout << endl;
}
