//Binary Search Tree
#include "tree.h"
#include <stdio.h>

int main(int argc, char** argv[]) {
	Node* tree_root = NULL;
	tree_root = insert_node(tree_root, 15);
	tree_root = insert_node(tree_root, 10);
	tree_root = insert_node(tree_root, 20);
	tree_root = insert_node(tree_root, 25);

	bool r = search_node(tree_root, 10);
	printf("%d\n", r);

	r = search_node(tree_root, 11);
	printf("%d\n", r);

	int min = find_min(tree_root);
	printf("Min element is %d\n", min);

	int max = find_max(tree_root);
	printf("Max element is %d\n", max);

	int height = find_height(tree_root);
	printf("The height of tree is %d\n", height);

	print_tree(tree_root, inorder_traversal);

	bool k = is_binary_search_tree(tree_root);
	printf("%d\n", k);

	tree_root = delete_node(tree_root, 15);
	print_tree(tree_root, inorder_traversal);
	return 0;
}

