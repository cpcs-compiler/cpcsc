#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "node.h"

static void	dump_node_level_print(int level, const char *str, ...)
{
	int i;
	va_list va;

	for (i = 0; i < level; i++)
		putchar(' ');
	va_start(va, str);
	vprintf(str, va);
	va_end(va);
}

static void	dump_node_print(node_t *node, int level)
{
	size_t	idx;

	if (!node)
	{
		dump_node_level_print(level, "[NULL]\n");
		return;
	}

	if (node->type == NODE_STMTS)
	{
		dump_node_level_print(level, "NODE_STMTS: (%ld STMTS)\n",
						((node_stmts_t *)node)->len);
		dump_node_level_print(level, "{\n");
		for (idx = 0; idx < ((node_stmts_t *)node)->len; idx++)
			dump_node_print(((node_stmts_t *)node)->stmts[idx], level + 1);
		dump_node_level_print(level, "}\n");
	}
	else if (node->type == NODE_TXT)
	{
		dump_node_level_print(level, "NODE_TXT\n");
		dump_node_level_print(level, "{\n");
		dump_node_print(((node_txt_t *)node)->value, level + 1);
		dump_node_level_print(level, "}\n");
	}
	else if (node->type == NODE_STR)
	{
		dump_node_level_print(level, "NODE_STR: %s\n", ((node_str_t *)node)->value);
	}
	else if (node->type == NODE_CLS)
	{
		dump_node_level_print(level, "NODE_CLS\n");
	}
	else
	{
		dump_node_level_print(level, "UNKNOW NODE\n");
	}
}

void		dump_nodes(node_t *node)
{
	if (!node) return;

	dump_node_print(node, 0);
}
