#include<iostream>
#include <cassert>

#include "Linked_List.h"
#include "DoublyLinkedList.h"
#include "BSTree.h"

void testLinkedList();
void testDoublyLinkedList();
void testBStree();

int main() {
	
	testLinkedList();
	testDoublyLinkedList();
	testBStree();

	return 0;
}
void testLinkedList() {
	singly::Linked_List list;
	std::cout << "----------[TEST] Linked List ----------" << std::endl;
	// Empty list
	list.show_list();
	list.pop_front();
	list.pop_back();
	
	//ADD ELEMENTS
	list.push_back(50);
	list.push_back(20);
	list.push_front(10);
	std::cout << "Exptected: 10	50	20" << std::endl;
	std::cout << "Got: \t";
	list.show_list();
	//REMOVE ELEMENT
	list.pop_front();
	std::cout << "Exptected: 50	20" << std::endl;
	std::cout << "Got: \t";
	list.show_list();

	list.pop_back();
	std::cout << "Exptected: 50" << std::endl;
	std::cout << "Got: \t";
	list.show_list();

	list.clear_list();
	std::cout << "Exptected:" << std::endl;
	std::cout << "Got: \t";
	list.show_list();

	std::cout << "[OK] Linked List tests passed!" << std::endl;
	std::cout << std::endl;
}
void testDoublyLinkedList() {
	doubly::DoublyLinkedList list;
	std::cout << "----------[TEST] Doubly Linked List ----------" << std::endl;
	//Add Element
	list.pushBack(50);
	list.pushBack(100);
	list.pushFront(10);
	list.insertAt(25, 2);
	std::cout << "Expected: 10	25	50	100" << std::endl;
	std::cout << "Got: \t";
	list.print();
	//Remove element
	list.removeAt(2);
	std::cout << "Expected: 10	50	100" << std::endl;
	std::cout << "Got: \t";
	list.print();

	list.popBack();
	list.popFront();
	std::cout << "Expected: 50" << std::endl;
	std::cout << "Got: \t";
	list.print();
	//Clear 
	list.clear();
	list.removeAt(53);
	list.print();
	std::cout << "[OK] Doubly Linked List tests passed!" << std::endl;
	std::cout<<std::endl;
}
void testBStree() {
	std::cout << "----------[TEST] Binary Search Tree ----------" << std::endl;
	BinarySearchTree::BSTree tree;
	//Add element
	tree.insert(5);
	tree.insert(3);
	tree.insert(8);
	tree.insert(1);
	tree.insert(4);
	tree.printTree();
	//Search
	assert(tree.search(5));
	assert(tree.search(3));
	assert(tree.search(1));
	// Min // Max
	assert(tree.minimum() == 1);
	assert(tree.maximum() == 8);
	//Remove element
	tree.remove(1);
	assert(!tree.search(1));
	tree.remove(3);
	assert(!tree.search(3));
	//Traversal
	std::cout << "Inorder (sorted): ";
	tree.inorder();
	std::cout << std::endl;
	std::cout << "BFS: \t";
	tree.bfs();
	tree.printTree();
	std::cout << "[OK] BST tests passed!" << std::endl;
	std::cout << std::endl;
}