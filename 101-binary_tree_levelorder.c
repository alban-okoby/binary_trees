#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_levelorder - Performs level-order traversal on a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = malloc(
			sizeof(binary_tree_t *) * binary_tree_size(tree));
	int front = 0, rear = 0;
	
	if (tree == NULL || func == NULL)
                return;
	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];
		func(current->n);

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}
	free(queue);
}

