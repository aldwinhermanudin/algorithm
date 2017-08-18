#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{

	public :
		string key_;
		int value_;
		Node* next_;

		Node(string key, int value){
			key_ = key;
			value_ = value;
			next_ = NULL;
		}
};

class LinkedList{

	public:
		int length_ = 0;
		Node* head_ = NULL;
		Node* tail_ = NULL;

		void append(string key, int value){

			if (head_ == NULL || tail_ == NULL){
				tail_ = new Node(key, value);
				head_ = tail_;
			}

			else{
				Node *new_node = new Node(key, value);
				tail_->next_ = new_node;
				tail_ = new_node;
			}
			length_++;
		}

		bool insert(string key, int value, int index){

			if( head_ == NULL || index >= length_ ){
				cout << "Index is not found" << endl;
				return false;
			}
			else if ( index == 0 ){

				Node *new_node = new Node(key, value);
				new_node->next_ = head_;
				head_ = new_node;
			}

			else {

				Node *new_node = new Node(key, value);
				Node *prev_node, *curr_node;
				curr_node = head_;

				for( int i = 0; i < index ; i++ ){
					prev_node = curr_node;
					curr_node = curr_node->next_;
				}

				prev_node->next_ = new_node;
				new_node->next_ =  curr_node;
			}

			length_++;
			return true;

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

		Node* get_node(string key){

			Node *curr_node = head_;
			while (curr_node != NULL){
				if ((!(curr_node->key_.compare(key)))) {
					return curr_node;
				}
				curr_node = curr_node->next_;
			}

			return NULL;
		}

		int get_index(string key){

			Node *curr_node = head_;
			int counter = 0;
			while (curr_node != NULL){
				if ((!(curr_node->key_.compare(key)))) {
					return counter;
				}
				counter++;
				curr_node = curr_node->next_;
			}

			return -1;
		}

		void print(){
			Node *curr_node = head_;
			int counter = 0;
			while (curr_node != NULL){
				cout << "[" << counter << "] " << "Key : "  << curr_node->key_ << " | Value : " << curr_node->value_ << endl;
				curr_node = curr_node->next_;
				counter++;
			}
		}

};

class HashTable{

	//private:
	public:
		vector<LinkedList> storage_;
		float bucket_ = 8;
		float size_ = 0;

	//public:

		HashTable(){
			storage_.resize(bucket_);
		}

		// Time Complexity:
		// Auxiliary Space Complexity:
		unsigned int hash(string key, int buckets){

			unsigned int len = key.length();
			unsigned int hash = 5381;
			unsigned int i = 0;

			for (i = 0; i < len; i++){
				hash = ((hash << 5) + hash) + (key[i]);
			}

			return hash%buckets;
		}

		// Time Complexity:
		// Auxiliary Space Complexity:
		void insert(string key, int value){

			resize();
			int index = hash(key, bucket_);
			if( storage_[index].head_ != NULL && storage_[index].get_index(key) != -1 ){

				storage_[index].get_node(key)->value_ = value;
			}
			else{

				storage_[index].append(key, value);
				size_++;
			}
		}

		// Time Complexity:
		// Auxiliary Space Complexity:
		int remove(string key){

			int index = hash(key, bucket_);
			if( storage_[index].head_ != NULL ){
				int chain_index = storage_[index].get_index(key);
				if(chain_index != -1){
					int value = storage_[index].get_node(key)->value_;
					storage_[index].remove(chain_index);
					size_--;
					return value;
				}
			}
					return -1;
		}

		// Time Complexity:
		// Auxiliary Space Complexity:
		int retrieve(string key){

			int index = hash(key, bucket_);
			if( storage_[index].head_ != NULL ){
				Node* temp_data = storage_[index].get_node(key);
				if( temp_data != NULL ) return temp_data->value_;
			}

			return -1;
		}

		void resize(){

				if ( (size_ / bucket_) >= 0.75 ){
					cout << "Resized" << endl;
					vector<LinkedList> temp_storage(storage_);
					int temp_bucket = bucket_;

					bucket_ = 2 * bucket_;
					storage_.clear();
					storage_.resize(bucket_);
					size_ = 0;

					for(int i = 0; i < temp_bucket; i++){
						Node *curr_node = temp_storage[i].head_;
          	while (curr_node != NULL){
	        		insert(curr_node->key_, curr_node->value_);
							curr_node = curr_node->next_;
            }
          }
				}
		}

		void print(){
			for(int i = 0; i < bucket_; i++){
      	Node *curr_node = storage_[i].head_;
				while (curr_node != NULL){
					cout << "[" << i << "] " << "Key : "  << curr_node->key_ << " | Value : " << curr_node->value_ << endl;
					curr_node = curr_node->next_;
				}
			}
		}
};

int main(int argc, char** argv){

	/*
	HashTable test;
	LinkedList test2;

	test2.append("aldwin", 20);
	test2.append("akbar", 11);
	test2.append("hermanudin", 1995);

	cout << "Date : " << test2.get_node("aldwin")->value_ << endl;
	cout << "Month : " << test2.get_node("akbar")->value_ << endl;
	cout << "Year : " << test2.get_node("hermanudin")->value_ << endl;

	test2.print();
	test2.insert("dean",11,1);
	cout << endl;
	cout << (test2.get_node("dean") == NULL ? "no key" : "key available") << endl;
	test2.print();
	test2.remove(test2.get_index("dean"));
	cout << (test2.get_node("dean") == NULL ? "no key" : "key available") << endl;
	cout << endl;
	test2.print();
	cout << test.hash("akbar", 100) << endl;
	*/
	
	HashTable newHash;
	cout << "Start Inseert" << endl;
	newHash.insert("hello", 5);
	newHash.insert("great", 1231);
	newHash.insert("asd", 102);
	newHash.insert("b", 21);
	newHash.insert("c", 32);
	newHash.insert("mahdi", 12);
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;
	newHash.print();
	newHash.insert("adriel", 10);
	cout << endl;
	newHash.print();
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;
	newHash.insert("aldwin", 123);
	cout << endl;
	newHash.print();
	newHash.insert("akbar", 321);
	newHash.insert("hermanudin", 222);
	newHash.insert("dean", 444);

	cout << newHash.hash("hello", 8) << endl;

	newHash.print();
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;

	cout << endl;
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;
	newHash.print();

	cout << endl;
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;
	newHash.print();
	newHash.insert("akbar", 123);
	newHash.insert("hermanudin", 123);
	cout << endl;
	newHash.print();
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;

	newHash.insert("asdf", 123);
	newHash.insert("asdfaa", 123);
	cout << endl;
	newHash.print();
	cout << "Hash size: "<< newHash.size_ << " | Hash bucket: " << newHash.bucket_ << endl;

	return 0;
}
