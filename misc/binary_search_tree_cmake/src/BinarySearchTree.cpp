#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(){
	
	size_ = 0;
	root_ = NULL;
}

void BinarySearchTree::in_order_traversal(Node *&entry_node){
	
	if(entry_node != NULL){
		in_order_traversal(entry_node->left_child_);
		traversed_bst.push_back(entry_node->value_);
		in_order_traversal(entry_node->right_child_);			
	}
}

void BinarySearchTree::pre_order_traversal(Node *&entry_node){
	
	if(entry_node != NULL){
		traversed_bst.push_back(entry_node->value_);
		pre_order_traversal(entry_node->left_child_);
		pre_order_traversal(entry_node->right_child_);			
	}
}
void BinarySearchTree::post_order_traversal(Node *&entry_node){
	
	if(entry_node != NULL){
		post_order_traversal(entry_node->left_child_);
		post_order_traversal(entry_node->right_child_);
		traversed_bst.push_back(entry_node->value_);							
	}
}

void BinarySearchTree::insert(int value){
			
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
		
bool BinarySearchTree::search(int value){
			
	Node *current_node = root_;
	do{
		if ( current_node->value_ == value ) return true;
			
		else if ( value <= current_node->value_ ){
			current_node = current_node->left_child_;
		} 	
		else {
			current_node = current_node->right_child_;
		}
			
	} while (current_node != NULL);
			
	return false;
}		
		
Node* BinarySearchTree::remove(Node* &entry_node,int value){
			
	if(entry_node == NULL){
		
		return entry_node;
	}
	else if (value < entry_node->value_ ){
		entry_node->left_child_ = remove(entry_node->left_child_, value);
		return entry_node;
	}
			
	else if ( value > entry_node->value_ ){
		entry_node->right_child_ =  remove(entry_node->right_child_, value);
		return entry_node;
	}
			
	else {
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
		
int BinarySearchTree::find_min(Node *entry_node){
			
	Node *current_node = entry_node;		
	if(entry_node == NULL){
				
		return -1;
	}
			
	while ( current_node != NULL ){
		if(current_node->left_child_ == NULL) return current_node->value_;
		current_node = current_node->left_child_;				
	}
}
		
int BinarySearchTree::find_min(){
	return find_min(root_);
}
		
void BinarySearchTree::insert_recursive( int value ){
	insert_recursive( root_, value);
}
				
bool BinarySearchTree::search_recursive(int value){
	search_recursive(root_, value);
}
		
std::vector<int> BinarySearchTree::in_order_traversal(){
	traversed_bst.clear();
	in_order_traversal(root_);	
	return traversed_bst;
}
		
std::vector<int> BinarySearchTree::pre_order_traversal(){
	traversed_bst.clear();
	pre_order_traversal(root_);	
	return traversed_bst;
}

std::vector<int> BinarySearchTree::post_order_traversal(){
	traversed_bst.clear();
	post_order_traversal(root_);	
	return traversed_bst;
}
		
void BinarySearchTree::insert_recursive( Node *&entry_node, int value ){
			
	if( entry_node == NULL ){
		
		entry_node = new Node(value); 
	} 
	else if ( value <= entry_node->value_ ){
	
		insert_recursive(entry_node->left_child_, value);
	} 
	else {
			
		insert_recursive(entry_node->right_child_, value);
	}

}
	
bool BinarySearchTree::search_recursive(Node *&entry_node, int value){
			
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
