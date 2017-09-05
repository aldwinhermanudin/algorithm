#include <iostream>

using namespace std;

class Node{

	public :
		int value_;
		Node* next_;

		Node(int n){
			value_ = n;
			next_ = NULL;
		}
};

class LinkedList{

	public:
		int length_ = 0;
		Node* head_ = NULL;
		Node* tail_ = NULL;

		void append(int value){

			if (head_ == NULL || tail_ == NULL){
				tail_ = new Node(value);
				head_ = tail_;
			}

			else{
				Node *new_node = new Node(value);
				tail_->next_ = new_node;
				tail_ = new_node;
			}
			length_++;
		}

		void insert(int value, int index){

			if( head_ == NULL || index >= length_ ){
				cout << "Index is not found" << endl;
			}
			else if ( index == 0 ){

				Node *new_node = new Node(value);
				new_node->next_ = head_;
				head_ = new_node;
				length_++;
			}

			else {

				Node *new_node = new Node(value);
				Node *prev_node, *curr_node;
				curr_node = head_;

				for( int i = 0; i < index ; i++ ){
					prev_node = curr_node;
					curr_node = curr_node->next_;
				}

				prev_node->next_ = new_node;
				new_node->next_ =  curr_node;
				length_++;

			}

		}

		void remove(int index){

			if( head_ == NULL || index >= length_ ){
				cout << "Index is not found" << endl;
			}
			else if ( index == 0 ){

				Node *curr_node = head_;
				head_ = head_->next_;
				delete curr_node;
				length_--;
			}

			else {

				Node *prev_node, *curr_node;
				curr_node = head_;

				for( int i = 0; i < index ; i++ ){
					prev_node = curr_node;
					curr_node = curr_node->next_;
				}

				if( curr_node->next_ == NULL ) {

					prev_node->next_ = NULL;
					tail_ = prev_node;
					delete curr_node;
				}
				else {

					prev_node->next_ = curr_node->next_;
					delete curr_node;
				}
				length_--;

			}
		}

		bool contains(int value){

			Node *curr_node = head_;

			while (curr_node != NULL){
				if (curr_node->value_ == value) {
					return true;
				}
				curr_node = curr_node->next_;
			}

			return false;

		}

};

int main(){

	Node newNode(6);
    cout << (newNode.value_) << endl;
    cout << (newNode.next_) << endl;

	LinkedList newList;

    newList.append(5);
    newList.remove(0);
    newList.append(10);
    newList.append(15);
    newList.insert(12, 2);
    newList.insert(1, 0);
    newList.insert(20, 5);
    newList.remove(2);
    newList.remove(6);

    Node* current = newList.head_;
    for(int i = 0; i < newList.length_; i++){
      cout << (current->value_) << " ";
      current = current->next_;
	}
	cout << endl;



	return 0;
}
