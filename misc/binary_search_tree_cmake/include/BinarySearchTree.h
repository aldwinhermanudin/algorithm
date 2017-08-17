#include <vector>
#include "Node.h"

class BinarySearchTree{
	
	private :
	
		std::vector<int> traversed_bst;
		
		void in_order_traversal(Node *&entry_node);
		void pre_order_traversal(Node *&entry_node);
		void post_order_traversal(Node *&entry_node);
		void insert_recursive( Node *&entry_node, int value );
		bool search_recursive(Node *&entry_node, int value);
	
	public :
	
		int size_;
		Node *root_;
		
		BinarySearchTree();		
		void insert(int value);		
		bool search(int value);		
		Node* remove(Node* &entry_node,int value);		
		int find_min(Node *entry_node);
		int find_min();
		
		void insert_recursive( int value );				
		bool search_recursive(int value);		
		std::vector<int> in_order_traversal();		
		std::vector<int> pre_order_traversal();
		std::vector<int> post_order_traversal();
		
		
};
