#include <iostream>
#include <BinarySearchTree.h>

using namespace std;

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
	cout << endl << endl;
	cout << "Deleting : 60" << endl;
	
	test1.remove(test1.root_,60);
	
	test = test1.in_order_traversal();
	for(int i = 0; i < test.size(); i++){
		
		cout << test[i] << " ";
	}
	cout << endl;
	return 0;
	
}
