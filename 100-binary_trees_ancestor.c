#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 * If no common ancestor was
 * found, return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);
	ancestor = first;

	while (ancestor)
	{
		const binary_tree_t *search = second;

		while (search)
		{
			if (ancestor == search)
				return ((binary_tree_t *)ancestor);
			search = search->parent;
		}
		ancestor = ancestor->parent;
	}
	return (NULL);
}
