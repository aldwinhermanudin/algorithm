#include <iostream>
#include <vector>

using namespace std;

class Node{
	
	public :
		
		int value_ = 0;
		Node *left_child_ = NULL;
		Node *right_child_ = NULL;
		Node(int n){
			
			value_ = n;
		}
	
	
};

class BinarySearchTree{
	
	private :
	
		vector<int> traversed_bst;
		
		void in_order_traversal(Node *&entry_node){
			if(entry_node != NULL){
				in_order_traversal(entry_node->left_child_);
				traversed_bst.push_back(entry_node->value_);
				in_order_traversal(entry_node->right_child_);			
			}
		}
		void pre_order_traversal(Node *&entry_node){
			if(entry_node != NULL){
				traversed_bst.push_back(entry_node->value_);
				pre_order_traversal(entry_node->left_child_);
				pre_order_traversal(entry_node->right_child_);			
			}
		}
		void post_order_traversal(Node *&entry_node){
			if(entry_node != NULL){
				post_order_traversal(entry_node->left_child_);
				post_order_traversal(entry_node->right_child_);
				traversed_bst.push_back(entry_node->value_);
							
			}
		}
		
		void insert_recursive( Node *&entry_node, int value ){
			
			if( entry_node == NULL ){
				
				entry_node = new Node(value);
				
			} else if ( value <= entry_node->value_ ){
				
				insert_recursive(entry_node->left_child_, value);
			} else {
				
				insert_recursive(entry_node->right_child_, value);
			}
			
		}
	
		bool search_recursive(Node *&entry_node, int value){
			
			if ( entry_node == NULL){
				
				return false;
			}
			else if ( value == entry_node->value_ ){
				
				return true;
			}
			else if( value <= entry_node->value_ ){
				
				return search_recursive(entry_node->left_child_, value);
			}
			else{
				
				return search_recursive(entry_node->right_child_, value);
			}
			
		}
	
	public :
	
		int size_ = 0;
		Node *root_ = NULL;
		
		void insert(int value){
			
			Node *new_node = new Node(value);
			Node *current_node = root_;
			
			if (root_ == NULL){				
				root_ =  new_node;
			} 
			else {
				
				while ( current_node != NULL ){

					if ( value <= current_node->value_){
						if( current_node->left_child_ == NULL ) {
							current_node->left_child_ = new_node;
							break;
						} 
						current_node = current_node->left_child_;
						
					}
					else {
						if( current_node->right_child_ == NULL ) {
							current_node->right_child_ = new_node;
							break;
						} 
						current_node = current_node->right_child_;
					}
				}
			}
			size_++;
		}
		
		bool search(int value){
			
			Node *current_node = root_;
			do{
				if ( current_node->value_ == value ) return true;
				
				else if ( value <= current_node->value_ ){
					current_node = current_node->left_child_;
				} 
				
				else {
					current_node = current_node->right_child_;
				}
				
			}
			while (current_node != NULL);
			
			return false;
		}
		
		Node* remove(Node* &entry_node,int value){
			
			if(entry_node == NULL){
				
				return entry_node;
			}
			else if (value < entry_node->value_ ){
				cout << entry_node->value_ << endl;
				entry_node->left_child_ = remove(entry_node->left_child_, value);
				return entry_node;
			}
			
			else if ( value > entry_node->value_ ){
				cout << entry_node->value_ << endl;
				entry_node->right_child_ =  remove(entry_node->right_child_, value);
				return entry_node;
			}
			
			else {
				cout << entry_node->value_ << endl;
				if( entry_node->left_child_ == NULL && entry_node->right_child_ == NULL ){
					
					delete entry_node;
					return NULL;
				}
				else if( entry_node->right_child_ == NULL ){
					
					Node *temp_node = entry_node->left_child_;
					delete entry_node;
					return temp_node;
				}
				else if( entry_node->left_child_ == NULL ){
					
					Node *temp_node = entry_node->right_child_;
					delete entry_node;
					return temp_node;
				}
				else{
					
					Node *temp_node = new Node(find_min(entry_node->right_child_));
					temp_node->left_child_  = entry_node->left_child_;
					temp_node->right_child_ = remove(entry_node->right_child_, temp_node->value_);
					delete entry_node;
					return temp_node;
				}
			}
		}
		
		int find_min(Node *entry_node){
			
			Node *current_node = entry_node;
			
			if(entry_node == NULL){
				
				return -1;
			}
			
			while ( current_node != NULL ){
				if(current_node->left_child_ == NULL) return current_node->value_;
				current_node = current_node->left_child_;				
			}
			
		}
		
		int find_min(){
			return find_min(root_);
		}
		
		void insert_recursive( int value ){
			insert_recursive( root_, value);
		}
				
		bool search_recursive(int value){
			search_recursive(root_, value);
		}
		
		vector<int> in_order_traversal(){
			traversed_bst.clear();
			in_order_traversal(root_);	
			return traversed_bst;
		}
		
		vector<int> pre_order_traversal(){
			traversed_bst.clear();
			pre_order_traversal(root_);	
			return traversed_bst;
		}
		vector<int> post_order_traversal(){
			traversed_bst.clear();
			post_order_traversal(root_);	
			return traversed_bst;
		}
		
		
};



int main (){
	
	/*
	cout << "-----node class-----\n";
    cout << "creation of a node" << endl;
    Node* testNode = new Node(5);
    cout << "1.0: " << (testNode != NULL) << endl;
    cout << "1.1: " << (testNode->value_ == 5)<< endl;
    cout << "1.2: " << (testNode->left_child_ == NULL)<< endl;
    cout << "1.3: " << (testNode->right_child_ == NULL)<< endl;

    cout << "\nassigning values and children"<<endl;
    testNode->value_ = 3;
    cout << "2.0: " << (testNode->value_ == 3)<< endl;
    Node *leftNode = new Node(1);
    Node *rightNode = new Node(5);
    cout << "2.1: " << (testNode->left_child_ == NULL)<< endl;
    cout << "2.2: " << (testNode->right_child_ == NULL)<< endl;
    testNode->left_child_ = leftNode;
    testNode->right_child_ = rightNode;
    cout << "2.3: " << (testNode->left_child_->value_ == 1)<< endl;
    cout << "2.4: " << (testNode->right_child_->value_ == 5)<< endl;

    cout << "\n\n-----binary search tree class-----\n";
    cout << "creation of a binary search tree" << endl;
    BinarySearchTree *testTree = new BinarySearchTree();
    cout << "3.0: " << (testTree != NULL)<< endl;
    cout << "3.1: " << (testTree->root_ == NULL)<< endl;
    cout << "3.2: " << (testTree->size_ == 0)<< endl;

	
    cout << "\ninsert first node" << endl;
    (testTree)->insert(5);
    cout << "4.0: " << (testTree->size_ == 1)<< endl;
    cout << "4.1: " << (testTree->root_->value_ == 5)<< endl;
    cout << "4.2: " << (testTree->root_->left_child_ == NULL)<< endl;
    cout << "4.3: " << (testTree->root_->right_child_ == NULL)<< endl;
	
    cout << "\ninsert a second node" << endl;
    testTree->insert(10);
    cout << "5.0: " << (testTree->size_ == 2) << endl;
    cout << "5.1: " << (testTree->root_->value_ == 5) << endl;
    cout << "5.2: " << (testTree->root_->left_child_ == NULL) << endl;
    cout << "5.3: " << (testTree->root_->right_child_ != NULL) << endl;
    cout << "5.4: " << (testTree->root_->right_child_->value_ == 10) << endl;

    cout << endl;
    testTree->insert(3);
    testTree->insert(1);
    testTree->insert(4);
    testTree->insert(7);
    testTree->insert(11);
    cout << ("\nsearch method") << endl;
    cout << "6.0: " << (testTree->search(3) == true) << endl;
    cout << "6.1: " << (testTree->search(1) == true) << endl;
    cout << "6.2: " << (testTree->search(4) == true) << endl;
    cout << "6.3: " << (testTree->search(7) == true) << endl;
    cout << "6.4: " << (testTree->search(11) == true) << endl;
    cout << "6.5: " << (testTree->search(14) == false) << endl;
    cout << "6.6: " << (testTree->search(6) == false) << endl;
    */
    
	/* Aldwin Test Code */
	Node testNode(1);
    Node leftNode(2);
    Node rightNode(3);
    cout << testNode.value_<< endl;
    cout << leftNode.value_<< endl;
    cout << rightNode.value_<< endl;
    
    BinarySearchTree test1;
    
    test1.insert(50);
    test1.insert(45);
    test1.insert_recursive(40);
    test1.insert_recursive(48);
    test1.insert(30);
    test1.insert(35);
    test1.insert(20);
    test1.insert(25);
    test1.insert_recursive(60);
    test1.insert_recursive(55);
    test1.insert_recursive(70);
    test1.insert_recursive(65);
    test1.insert_recursive(80);
    test1.insert_recursive(75);
    
    cout << endl << (test1.search(60)? "True" : "False");
	cout << endl << (test1.search(55)? "True" : "False");
	cout << endl << (test1.search_recursive(10)? "True" : "False");
	cout << endl << (test1.search_recursive(8)? "True" : "False");
	cout << endl << "Minimum Value is : " << test1.find_min();
	cout << endl;
	vector<int> test = test1.in_order_traversal();
	for(int i = 0; i < test.size(); i++){
		
		cout << test[i] << " ";
	}
	cout << endl;
	
	test1.remove(test1.root_,60);
	
	test = test1.in_order_traversal();
	for(int i = 0; i < test.size(); i++){
		
		cout << test[i] << " ";
	}
	cout << endl;
	return 0;
	
}
