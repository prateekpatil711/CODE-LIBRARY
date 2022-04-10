#include <bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	Node *left, *right;
};

struct Node* newNode(int key)
{
	Node* temp = new Node;
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


int findLargestSubtreeSumUtil(struct Node* root, int& ans)
{

	if (root == NULL)	
		return 0;
	int currSum = root->key +findLargestSubtreeSumUtil(root->left, ans)	+ findLargestSubtreeSumUtil(root->right, ans);
	ans = max(ans, currSum);
	return currSum;
}

int findLargestSubtreeSum(struct Node* root)
{
	if (root == NULL)	
		return 0;
	int ans = INT_MIN;
	findLargestSubtreeSumUtil(root, ans);
	return ans;
}


int main()
{
	 struct Node* root = NULL;
     root = insert(root, 1);
	 insert(root,-2);
	 insert(root,3);
	 insert(root,4);
	 insert(root,5);
	 insert(root,-6);
     insert(root,2);

	cout << findLargestSubtreeSum(root);
	return 0;
}



