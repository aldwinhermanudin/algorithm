#include <iostream>
#include <vector>

using namespace std;

class MergeSort {
			
	public :
	
		int *compute( int* input, int input_size ){
		
			int* merged_array = new int[input_size];
			int *arr_left = NULL, *arr_right = NULL, *arr_temp = NULL;
			
			if ( input_size < 2 ) return NULL; //(optional) safety check
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

class QuickSort {
	
	private :
	
		int *output_ = NULL;
		int size_ =  0;
		
	public :
	
		int *compute( int *input, int size ){
			
			/* clear old data */
			delete [] output_;
			output_ = NULL;
			
			size_ = size;
			output_ = input;
			divide(0, size - 1);
			return output_;
		}
		
		void divide( int begin, int end ){
			
			int size = end - begin + 1;
			int pivot = end;
			int assigner = begin;
			
			if ( size < 1 ) return; //(optional) safety check
			
			for(int runner = begin; runner <= end; runner++){
				if( output_[runner] <= output_[pivot] ){
					swap(output_[assigner], output_[runner]);
					assigner++;
				}			
			}
			
			pivot = assigner - 1;
			int left_begin = begin;
			int left_end = pivot - 1;
			int left_size = left_end - left_begin + 1;
			
			int right_begin = pivot + 1;
			int right_end = end;
			int right_size = right_end - right_begin + 1;
			
			if( left_size > 1 ){
				
				divide( left_begin, left_end );
			}
			if( right_size > 1 ){
				
				divide( right_begin, right_end );
			}
		}
		
		void swap( int &a, int &b ){
			int c = a;
			a = b;
			b = c;
		}
		
	
};

void PrintList(int *input, int size){
	cout << "[";
	for ( int i = 0; i < size; i++ ){
		
		cout << " " << input[i] << " ";
	}
	cout << "]";
}
int main(){
	
	MergeSort test;
	QuickSort test2; 
	int array[20] = {13,23,13,13,24,-65,45,23,14,2312,6,7,-2,1,76,123,90,1238,9,10};
	int *merged_array;
	
	cout << " Unsorted Array " << endl;
	PrintList(array, 20);
	cout << endl << endl;
	
	cout << " Merge Sort " << endl;
	merged_array = test.compute(array, 20);
	PrintList(merged_array, 20);
	
	cout << endl << endl;
	
	cout << " Quick Sort " << endl;
	merged_array = test2.compute(array, 20);
	PrintList(merged_array, 20);
	cout << endl;
	
}
