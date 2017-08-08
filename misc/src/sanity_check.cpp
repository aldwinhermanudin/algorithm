#include <iostream>
#include <stdio.h>
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

int main(){
	
	Box test1;	
	Box test2(10,20,30);
	Box *test3 = new Box(70,80,90);
	
	PrintBox(test1);
	SetBoxByReference(test1,40,50,60);
	PrintBox(test1);
	
	PrintBox(test2);
	SetBoxByPointer(&test2,100,200,300);
	PrintBox(test2);
	
	PrintBox(*test3);
	SetBoxByPointer(test3,700,800,900);
	PrintBox(*test3);
	delete test3;
	
	int *ptr_test = NULL;
	printf("%s \n", (ptr_test == NULL ? "Pointer is NULL" : " Pointer is not NULL"));
	ptr_test = &(test1.length_);
	printf("%s \n", (ptr_test == NULL ? "Pointer is NULL" : " Pointer is not NULL"));
	cout << *ptr_test << endl;
	
	return 0;
}

// Passing by Value
void PrintBox(Box input){
	
	cout << " " << input.length_<< " " << input.width_<< " " << input.height_ << endl;
}

// Passing by Reference
void SetBoxByReference(Box &input, int l, int w, int h){
	
	input.length_ = l;
	input.width_ = w;
	input.height_ = h;
}

// Passing by Pointer
void SetBoxByPointer(Box *input, int l, int w, int h){
	
	input->length_ = l;
	input->width_ = w;
	input->height_ = h;
}
