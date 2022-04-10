
#include <iostream>
using namespace std;
struct Node
{
	struct Node *left, *right;
	int key;
};
Node* newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return temp;
}

struct Node* insert(struct Node* node, int data)
{
    if (node == NULL)
        return(newNode(data));
    else
    {
        if (data <= node->key)
            node->left = insert(node->left, data);
        else
            node->right = insert(node->right, data);
        return node;
    }
}
int findLevel(Node *root, int k, int level)
{
	if (root == NULL)
		return -1;
	if (root->key == k)
		return level;

	int l = findLevel(root->left, k, level+1);
	return (l != -1)? l : findLevel(root->right, k, level+1);
}

Node *findDistUtil(Node* root, int n1, int n2, int &d1,
							int &d2, int &dist, int lvl)
{
	if (root == NULL) return NULL;
	if (root->key == n1)
	{
		d1 = lvl;
		return root;
	}
	if (root->key == n2)
	{
		d2 = lvl;
		return root;
	}
	Node *left_lca = findDistUtil(root->left, n1, n2,d1, d2, dist, lvl+1);
	Node *right_lca = findDistUtil(root->right, n1, n2,d1, d2, dist, lvl+1);
	if (left_lca && right_lca)
	{
		dist = d1 + d2 - 2*lvl;
		return root;
	}
	return (left_lca != NULL)? left_lca: right_lca;
}

int findDistance(Node *root, int n1, int n2)
{
	int d1 = -1, d2 = -1, dist;
	Node *lca = findDistUtil(root, n1, n2, d1, d2,dist, 1);
	if (d1 != -1 && d2 != -1)
		return dist;
	if (d1 != -1)
	{
		dist = findLevel(lca, n2, 0);
		return dist;
	}
	if (d2 != -1)
	{
		dist = findLevel(lca, n1, 0);
		return dist;
	}

	return -1;
}
int main()
{
	Node * root = NULL;
    root  =  insert(root , 1);
    insert(root , 2);
    insert(root , 5);
    insert(root , 4);
    insert(root , 3);
    insert(root , 9);
    insert(root , 7);
    insert(root , 10);
    insert(root , 6);
    insert(root , 8);
	cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
	cout << " nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << " nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << " nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << " nDist(8, 5) = " << findDistance(root, 8, 5);
	return 0;
}
