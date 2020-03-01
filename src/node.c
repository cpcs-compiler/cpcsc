#include <stdlib.h>
#include "node.h"

node_t	*new_node(node_type_t type, node_t *left, node_t *right)
{
	node_t	*node;

	node = (node_t *)malloc(sizeof(node_t));
	if (!node) return (NULL);

	node->type = type;
	node->left = left;
	node->right = right;
	return (node);
}

node_t	*new_node_str(char *str)
{
	node_str_t	*node;

	node = (node_str_t *)malloc(sizeof(node_str_t));
	if (!node) return (NULL);
	node->type = NODE_STR;
	node->value = str;

	return ((node_t *)node);
}

node_t	*new_node_stmts(node_t **stmts, size_t len, node_t *stmt)
{
	node_stmts_t	*node;

	node = (node_stmts_t *)malloc(sizeof(node_stmts_t));
	if (!node) return (NULL);

	node->type = NODE_STMTS;
	if (!stmts)
	{
		stmts = (node_t **)malloc(sizeof(node_t*));
		if (!stmts) return (NULL);
		stmts[0] = stmt;
		len = 1;
	}
	else
	{
		len++;
		stmts = realloc(stmts, len * sizeof(node_t *));
		stmts[len - 1] = stmt;
	}

	node->stmts = stmts;
	node->len = len;

	return ((node_t *)node);
}

node_t	*new_node_txt(node_t *value)
{
	node_txt_t	*node;

	node = (node_txt_t *)malloc(sizeof(node_txt_t));
	if (!node) return (NULL);

	node->type = NODE_TXT;
	node->value = value;

	return ((node_t *)node);
}
