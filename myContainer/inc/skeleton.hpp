//
// Created by jaewkim on 2022/08/28.
//

#ifndef MYCONTAINER_SKELETON_HPP
#define MYCONTAINER_SKELETON_HPP

{
Node *deleteNode(Node *root, int key) {
	// Find the node and delete it
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else {
		if ((root->left == NULL) || (root->right == NULL)) {
			Node *temp = root->left ? root->left : root->right;
			if (temp == NULL) {
				temp = root;
				root = NULL;
			} else
				*root = *temp;
			free(temp);
		} else {
			Node *temp = nodeWithMimumValue(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	
	if (root == NULL)
		return root;
	
	// Update the balance factor of each node and
	// balance the tree
	root->height = 1 + max(height(root->left),
						   height(root->right));
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1) {
		if (getBalanceFactor(root->left) >= 0) {
			return rightRotate(root);
		} else {
			root->left = leftRotate(root->left);
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) {
		if (getBalanceFactor(root->right) <= 0) {
			return leftRotate(root);
		} else {
			root->right = rightRotate(root->right);
			return leftRotate(root);
		}
	}
	return root;
}
};

#endif //MYCONTAINER_SKELETON_HPP
