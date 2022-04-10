#include <iostream>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Preorder(BST*);
};

// Default Constructor definition.
BST ::BST()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

// Parameterized Constructor definition.
BST ::BST(int value)
{
	data = value;
	left = right = NULL;
}

// Insert function definition.
BST* BST ::Insert(BST* root, int value)
{
	if (!root) {
		return new BST(value);
	}
	if (value > root->data) {
		root->right = Insert(root->right, value);
	}
	else {
		root->left = Insert(root->left, value);
	}
	return root;
}

void BST ::Preorder(BST* root)
{
	if (!root) {
		return;
	}
	Preorder(root->left);
    Preorder(root->right);
	cout << root->data << endl;
	
}

// Driver code
int main()
{
	BST b, *root = NULL;
	root = b.Insert(root, 50);
	b.Insert(root, 30);
	b.Insert(root, 20);
	b.Insert(root, 40);
	b.Insert(root, 70);
	b.Insert(root, 60);
	b.Insert(root, 80);

	b.Preorder(root);
	return 0;
}

