#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid
 * Binary Search Tree (BST)
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_bst_helper(tree, NULL, NULL));
}

/**
 * is_bst_helper - Helper function to check if a binary tree is a valid BST
 * @node: Current node being checked
 * @min: Pointer to the minimum value allowed for the current node
 * @max: Pointer to the maximum value allowed for the current node
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise
 */
int is_bst_helper(const binary_tree_t *node, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (node == NULL)
		return (1);

	if ((min != NULL && node->n <= min->n) ||
			(max != NULL && node->n >= max->n))
		return (0);

	return ((is_bst_helper(node->left, min, node) && is_bst_helper(node->right, node, max)));
}
