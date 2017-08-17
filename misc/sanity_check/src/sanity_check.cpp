#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class Box{
	
	public :
		int length_ = 0;
		int width_ = 0;
		int height_ = 0;
		Box(){};
		Box(int l, int w, int h){
			this->length_ = l;
			this->width_ = w;
			this->height_ = h;
		}
	
};

void PrintBox(Box input);
void SetBoxByReference(Box &input, int l, int w, int h);
void SetBoxByPointer(Box *input, int l, int w, int h);
Box SetBox(int l, int w, int h);

int main(){
	
	/* instantiate object */
	Box test1;	
	Box test2(10,20,30);
	Box *test3 = new Box(70,80,90);
	
	/* Pass by reference */
	PrintBox(test1);
	SetBoxByReference(test1,40,50,60);
	PrintBox(test1);
	
	/* Pass by pointer using non-pointer object */
	PrintBox(test2);
	SetBoxByPointer(&test2,100,200,300);
	PrintBox(test2);
	
	/* Pass by pointer using pointer object */
	PrintBox(*test3);
	SetBoxByPointer(test3,700,800,900);
	PrintBox(*test3);
	delete test3;
	
	/* Pass by value */
	Box test4 = SetBox(312,123,321);
	Box test5 = test4;
	PrintBox(test4);
	PrintBox(test5);
	
	int *ptr_test = NULL;
	printf("%s \n", (ptr_test == NULL ? "Pointer is NULL" : " Pointer is not NULL"));
	ptr_test = &(test1.length_);
	printf("%s \n", (ptr_test == NULL ? "Pointer is NULL" : " Pointer is not NULL"));
	cout << *ptr_test << endl;
	
	/* Pointer arithmetic */
	int array1[5] = {1,23,4,56,789};
	int array2[5];
	copy(array1, array1+5, array2);
	for( int i = 0; i < 5; i++ ){
		cout << array2[i] << " ";
	}
	cout << endl;
	cout << *(array1) << endl;
	int input_size = 7;
	int left = input_size / 2;
	int right = input_size - left;
	cout << "Total : " << input_size << endl;
	cout << "Left : " << left << " Right : " << right << endl;
	
	/* string compare */
	
	string string_a = "this is string";
	string string_b = "is this string";
	string string_c = "this is string";
	cout << ((!string_a.compare(string_b)? "String is the same" : "String is not the same")) << endl;
	cout << ((!string_a.compare(string_c)? "String is the same" : "String is not the same")) << endl;
	
	return 0;
}

/* Passing by Value */
void PrintBox(Box input){
	
	cout << " " << input.length_<< " " << input.width_<< " " << input.height_ << endl;
}

/* Passing by Reference */
void SetBoxByReference(Box &input, int l, int w, int h){
	
	input.length_ = l;
	input.width_ = w;
	input.height_ = h;
}

/* Passing by Pointer */
void SetBoxByPointer(Box *input, int l, int w, int h){
	
	input->length_ = l;
	input->width_ = w;
	input->height_ = h;
}

/* Passing by value */
Box SetBox(int l, int w, int h){
	
	return Box(l,w,h);
}
