#include <stdlib.h>
#include <stdio.h>
#include "node.h"

static void	dump_node_print(node_t *node)
{
	switch (node->type)
	{
		case NODE_STMTS:
			printf("NODE_STMTS: (%ld) STMT\n",
					((node_stmts_t *)node)->len);
			break;
		default:
			printf("??? node ???\n");
			break;
	}
}

void		dump_nodes(node_t *node)
{
	size_t	idx;

	if (!node) return;

	if (node->type == NODE_STMTS)
	{
		dump_node_print(node);
		for (idx = 0; idx < ((node_stmts_t *)node)->len; idx++)
			dump_nodes(((node_stmts_t *)node)->stmts[idx]);
	}
}
