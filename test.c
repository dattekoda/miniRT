
// #include <stdlib.h>
// #include <stdio.h>

// typedef enum e_element_type
// {
// 	AMBIENT,
// 	CAMERA,
// 	LIGHT,
// 	SPHERE,
// 	PLANE,
// 	CYLINDER,
// 	DISK,
// 	CONE,
// 	TRIANGLE,
// 	TREE,
// 	NOTHING
// }	t_element_type;

// typedef struct s_hitter
// {
// 	t_element_type	type;
// }	t_hitter;

// typedef struct s_sphere
// {
// 	// int			data;
// 	t_hitter	hitter;
// 	double		radius;
// }	t_sphere;

// typedef struct s_tree
// {
// 	t_hitter	hitter;
// 	t_hitter	*lhs;
// 	t_hitter	*rhs;
// }	t_tree;

// void	print_hitter(t_hitter *hitter)
// {
// 	if (!hitter)
// 	{
// 		printf("it is null\n");
// 		return ;
// 	}
// 	static const char *string_table[] = {
// 		"AMBIENT",
// 		"CAMERA",
// 		"LIGHT",
// 		"SPHERE",
// 		"PLANE",
// 		"CYLINDER",
// 		"DISK",
// 		"CONE",
// 		"TRIANGLE",
// 		"TREE",
// 		"NOTHING"
// 	};
// 	printf("type:%s \n", string_table[hitter->type]);
// 	// print_vec(hitter->aabb.centroid);
// 	printf("hitter: %p\n", hitter->type);
// }

// void	print_tree(t_hitter *node)
// {
// 	if (!node)
// 		return ;
// 	print_hitter(node);
// 	if (node->type != TREE)
// 		return ;
// 	t_tree	*tree = (t_tree *)node;
// 	print_tree(tree->lhs);
// 	print_tree(tree->rhs);
// }

// // int main(void)
// // {
// // 	t_sphere	*left_sphere = malloc(sizeof(t_hitter));
// // 	t_sphere	*right_left_sphere = malloc(sizeof(t_hitter));
// // 	t_tree		*right_tree = malloc(sizeof(t_tree));
// // 	t_tree		*root = malloc(sizeof(t_tree));

// // 	left_sphere->hitter.type = SPHERE;
// // 	right_left_sphere->hitter.type = SPHERE;
// // 	right_tree->hitter.type = TREE;
// // 	right_tree->lhs = (t_hitter *)right_left_sphere;
// // 	root->hitter.type = TREE;
// // 	root->lhs = (t_hitter *)left_sphere;
// // 	root->rhs = (t_hitter *)right_tree;

// // 	print_tree((t_hitter *)root);
// // }