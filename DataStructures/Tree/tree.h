#ifndef __TREE_H
#define __TREE_H
#include <stdbool.h>

#define TTYPE int

typedef struct Node {
	TTYPE data;
	struct Node* left;
	struct Node* right;
}Node;

extern Node* create_new_node(TTYPE data);
extern Node* insert_node(Node* tree_root, TTYPE data);
extern bool search_node(Node* tree_root, TTYPE data);
extern TTYPE find_min(Node* tree_root);
extern TTYPE find_max(Node* tree_root);
extern int find_height(Node* tree_root);
extern int max(int a, int b);
extern void print_tree(Node* tree_root, void (*traversal_method)(Node*));
extern void preorder_traversal(Node* tree_root);
extern void inorder_traversal(Node* tree_root);
extern void postorder_traversal(Node* tree_root);
extern bool is_binary_search_tree(Node* tree_root);
extern bool is_bst_engine(Node* tree_root, int min_val, int max_val);
extern Node* delete_node(Node* tree_root, TTYPE data);
extern Node* get_min(Node* tree_root);

#endif // __TREE_H