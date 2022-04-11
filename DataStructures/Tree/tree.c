#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

Node* create_new_node(TTYPE data) {
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

Node* insert_node(Node* tree_root, TTYPE data) {
	if(tree_root == NULL) {
		Node* temp = create_new_node(data);
		return temp;
	}
	else if(data <= tree_root->data) {
		tree_root->left = insert_node(tree_root->left, data);
	}
	else {
		tree_root->right = insert_node(tree_root->right, data);
	}
	return tree_root;
}

bool search_node(Node* tree_root, TTYPE data) {
	if(tree_root == NULL) return false;
	if(tree_root->data == data) return true;
	if(data < tree_root->data) {
		return search_node(tree_root->left, data);
	}
	else{
		return search_node(tree_root->right, data);
	}
}

TTYPE find_min(Node* tree_root) {
	assert(tree_root != NULL);
	if(tree_root->left == NULL) return tree_root->data;
	else return find_min(tree_root->left);
}

TTYPE find_max(Node* tree_root) {
	assert(tree_root != NULL);
	if(tree_root->right == NULL) return tree_root->data;
	else return find_max(tree_root->right);
}

int find_height(Node* tree_root) {
	if(tree_root == NULL) return -1;
	int left_tree = find_height(tree_root->left);
	int right_tree = find_height(tree_root->right);
	return max(left_tree, right_tree) + 1;
}

int max(int a, int b) {
	return a >= b ? a : b;
}

void print_tree(Node* tree_root, void (*traversal_method)(Node*)) {
	printf("[ ");
	traversal_method(tree_root);
	printf("]\t");
}

void preorder_traversal(Node* tree_root) {
	if(tree_root == NULL) return;
	printf("%d ", tree_root->data);
	preorder_traversal(tree_root->left);
	preorder_traversal(tree_root->right);
}

void inorder_traversal(Node* tree_root) {
	if(tree_root == NULL) return;
	inorder_traversal(tree_root->left);
	printf("%d ", tree_root->data);
	inorder_traversal(tree_root->right);
}

void postorder_traversal(Node* tree_root) {
	if(tree_root == NULL) return;
	postorder_traversal(tree_root->left);
	postorder_traversal(tree_root->right);
	printf("%d ", tree_root->data);
}

bool is_binary_search_tree(Node* tree_root) {
	return is_bst_engine(tree_root, INT_MIN, INT_MAX);
}

bool is_bst_engine(Node* tree_root, int min_val, int max_val) {
	if(tree_root == NULL) return true;
	if(tree_root->data >= min_val && tree_root->data < max_val && is_bst_engine(tree_root->left, min_val, tree_root->data) && is_bst_engine(tree_root->right, tree_root->data, max_val)) {
		return true;
	}
	return false;
}

extern Node* get_min(Node* tree_root) {
	while(tree_root->left != NULL) tree_root = tree_root->left;
	return tree_root;
}

extern Node* delete_node(Node* tree_root, TTYPE data) {
	if(tree_root == NULL) return tree_root;
	else if(data < tree_root->data) return delete_node(tree_root->left, data);
	else if(data > tree_root->data) return delete_node(tree_root->right, data);
	else {
		if(tree_root->left == NULL && tree_root->right == NULL) {
			free(tree_root);
			return NULL;
		}
		else if(tree_root->left == NULL) {
			Node* temp = tree_root;
			tree_root = tree_root->right;
			free(temp);
			return tree_root;
		}
		else if(tree_root->right == NULL) {
			Node* temp = tree_root;
			tree_root = tree_root->left;
			free(temp);
			return tree_root;
		}
		else {
			Node* temp = get_min(tree_root->right);
			tree_root->data = temp->data;
			tree_root->right = delete_node(tree_root->right, temp->data);
			return tree_root;
		}
	}
}