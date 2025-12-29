#pragma once
#include <optional>

std::ostream& operator<<(std::ostream& os, const std::optional<int>& opt);

namespace BinarySearchTree {

	class Node {
	private:
		int value;
		Node* leftChild;
		Node* rightChild;
	public:
		Node(int value, Node* leftChild = nullptr,Node * rightChild = nullptr);
		~Node();

		void setValue(int _value);
		int getValue() const;

		void setRightChild(Node* rightChild);
		Node* getRightChild() const;

		void setLeftChild(Node* leftChild);
		Node* getLeftChild() const;
	};


class BSTree
{
private:
	Node* root;
	Node* createNode(int _value);

	Node* insert(Node* node, int _value);
	bool search(Node* node, int value);
	Node* remove(Node* node, int value);
	Node* minimum(Node* node);
	Node* maximum(Node* node);
	void preorder(Node* node);
	void inorder(Node* node);
	void postorder(Node* node);
	void bfs(Node* node);
	void printTree(Node* node, int space = 0, int indent = 5);
public:
	BSTree();
	~BSTree();
	void insert(int value);
	bool search(int value);
	void remove(int value);
	std::optional<int> minimum();
	std::optional<int> maximum();
	void preorder();
	void inorder();
	void postorder();
	void bfs();
	void printTree();
};


}
