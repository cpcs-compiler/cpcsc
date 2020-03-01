#ifndef CPCSC_NODE_H
# define CPCSC_NODE_H

typedef enum
{
	NODE_ROOT,
	NODE_STR,
	NODE_STMTS,
	NODE_TXT,
	NODE_CLS
} node_type_t;

typedef struct node_s
{
	node_type_t	type;
	struct node_s	*left;
	struct node_s	*right;
} node_t;

typedef struct
{
	node_type_t	type;

	char		*value;

} node_str_t;

typedef struct
{
	node_type_t	type;
	node_t		**stmts;
	size_t		len;
} node_stmts_t;

typedef struct
{
	node_type_t	type;

	node_t		*value;

} node_txt_t;

node_t	*new_node(node_type_t, node_t *, node_t *);

node_t	*new_node_str(char *);

node_t	*new_node_stmts(node_t **, size_t, node_t *);

node_t	*new_node_txt(node_t *value);

/* debug utils */
void	dump_nodes(node_t *);

#endif /* !CPCSC_NODE_H */
