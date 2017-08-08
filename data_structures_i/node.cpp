#include <iostream>

using namespace std;

class Node{
	
	public :
		int value_;
		Node* next_;
		
		Node(int n){
			this->value_ = n;
			this->next_ = NULL;
		}
};
	
int main(){
	
	Node sample1(1);
	cout << sample1.value_ << endl;
	cout << sample1.next_ << endl;
	
	return 0;
	
}
