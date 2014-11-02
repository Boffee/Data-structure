/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include <ostream>

template <class K, class V>
V AVLTree<K, V>::find(const K & key) const
{
	return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node * subtree, const K & key) const
{
	if (subtree == NULL)
		return V();
	else if (key == subtree->key)
		return subtree->value;
	else
	{
		if (key < subtree->key)
			return find(subtree->left, key);
		else
			return find(subtree->right, key);
	}
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node * temp = t->right;
    t->right = temp->left;
    temp->left = t;
    t = temp;
    t->height = t->height - 1;
    t->left->height = max(heightOrNeg1(t->left->left), heightOrNeg1(t->left->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
	// Implemented for you:
	rotateLeft(t->left);
	rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    Node * temp = t->left;
    t->left = temp->right;
    temp->right = t;
    t = temp;
    t->height = t->height - 1;
    t->right->height = max(heightOrNeg1(t->right->left), heightOrNeg1(t->right->right))+1;
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node * & t)
{
	*_out << __func__ << endl; // Outputs the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
	insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node* & subtree, const K & key, const V & value)
{
    if (subtree == NULL){
        subtree = new Node(key, value);
        subtree->height = 0;
        return;
    }
    if (key == subtree->key){
        subtree->value = value;
        return;
    }
    if (key < subtree->key){
        insert(subtree->left, key, value);
        int bal = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
        int balLeft = heightOrNeg1(subtree->left->right) - heightOrNeg1(subtree->left->left);
        if (bal == - 2) {
            if (balLeft == -1) rotateRight(subtree);
            else rotateLeftRight(subtree);
        }
    }
    if (key > subtree->key){
        insert(subtree->right, key, value);
        int bal = heightOrNeg1(subtree->right) - heightOrNeg1(subtree->left);
        int balRight = heightOrNeg1(subtree->right->right) - heightOrNeg1(subtree->right->left);
        if (bal == 2) {
            if (balRight == 1) rotateLeft(subtree);
            else rotateRightLeft(subtree);
        }
    }
    subtree->height = max(heightOrNeg1(subtree->left), heightOrNeg1(subtree->right))+1;
}
