#include <stdio.h>

struct avl_tree {
	int 		data;
	avl_tree 	*left_avl;
	avl_tree 	*right_avl;
	unsigned int 	height
};
