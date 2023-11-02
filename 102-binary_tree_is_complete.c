#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise. If tree is NULL, return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int is_last_level = 0;
	int front = 0, rear = 0;

	 binary_tree_t *current = NULL;
	 binary_tree_t *queue[10000];

	if (tree == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (rear - front > 0)
	{
		current = queue[front++];

		if (current == NULL && !is_last_level)
			return (0);
		if (current)
		{
			queue[rear++] = current->left;
			queue[rear++] = current->right;
		}
		else
			is_last_level = 1;
	}
	return (1);
}
