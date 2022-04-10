#include<bits/stdc++.h>
using namespace std;

class BST {
	int data;
	BST *left, *right;

public:
	BST();
	BST(int);
	BST* Insert(BST*, int);
	void Inorder(BST*);
    void mirror(BST*);
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


void BST::mirror(BST* node)
{
	if (node == NULL)
		return;
	else
	{
		BST* temp;
		mirror(node->left);
		mirror(node->right);
		temp	 = node->left;
		node->left = node->right;
		node->right = temp;
	}
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

void BST ::Inorder(BST* root)
{
	if (!root) {
		return;
	}
	Inorder(root->left);
	cout << root->data << endl;
	Inorder(root->right);
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

	cout << "Inorder traversal of the constructed"
		<< " tree is" << endl;
	b.Inorder(root);
	b.mirror(root);
	cout << "\nInorder traversal of the mirror tree"
		<< " is \n";
	b.Inorder(root);
}

