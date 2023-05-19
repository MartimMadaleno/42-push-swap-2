// #include "push_swap.h"

// void	update_moves(t_list **list_a, t_list **list_b, t_list *tmp_a,
// 	t_list *tmp_b, int *total_moves, int *vis, int *moves_a, int *moves_b)
// {
// 	int	moves_a_tmp;
// 	int	moves_b_tmp;
// 	int	tmp_vis;

// 	moves_b_tmp = get_op(*list_b, tmp_b->index);
// 	tmp_vis = find_vis(*list_a, tmp_b->index);
// 	moves_a_tmp = get_op(*list_a, tmp_vis);
// 	if (*total_moves > getPositive(moves_a_tmp) + getPositive(moves_b_tmp))
// 	{
// 		*total_moves = getPositive(moves_a_tmp) + getPositive(moves_b_tmp);
// 		*vis = tmp_vis;
// 		*moves_a = moves_a_tmp;
// 		*moves_b = moves_b_tmp;
// 	}
// }

// void	process_moves(t_list **list_a, t_list **list_b, int *moves_a,
// 	int *moves_b, void (*run_function)(void (*)(), t_list **, t_list **, int))
// {
// 	int	tmp_move;

// 	if (*moves_a < 0 && *moves_b < 0)
// 		(*moves_a >= *moves_b) ? run_function(do_rr, list_a, list_b, -*moves_a),
// 			tmp_move = *moves_a : run_function(do_rr, list_a, list_b, -*moves_b),
// 			tmp_move = *moves_b;
// 	else if (*moves_a > 0 && *moves_b > 0)
// 		(*moves_a <= *moves_b) ? run_function(do_rrr, list_a, list_b, *moves_a),
// 			tmp_move = *moves_a : run_function(do_rrr, list_a, list_b, *moves_b),
// 			tmp_move = *moves_b;
// 	*moves_a -= tmp_move;
// 	*moves_b -= tmp_move;
// }

// void	run_remaining_moves(t_list **list_a, t_list **list_b, int *moves_a,
// 	int *moves_b, void (*run_function)(void (*)(), t_list **, t_list **, int))
// {
// 	if (*moves_a < 0)
// 		run_function(do_ra, list_a, list_b, -*moves_a);
// 	else if (*moves_a > 0)
// 		run_function(do_rra, list_a, list_b, *moves_a);
// 	if (*moves_b < 0)
// 		run_function(do_rb, list_a, list_b, -*moves_b);
// 	else if (*moves_b > 0)
// 		run_function(do_rrb, list_a, list_b, *moves_b);
// 	do_pa(list_a, list_b);
// }

// void	sort_last_b(t_list **list_a, t_list **list_b)
// {
// 	int	moves_a;
// 	int	moves_b;
// 	int	total_moves;
// 	int	vis;
// 	t_list	*tmp_b;

// 	total_moves = 1000;
// 	tmp_b = *list_b;
// 	while (tmp_b)
// 	{
// 		update_moves(list_a, list_b, *list_a, tmp_b,
// 			&total_moves, &vis, &moves_a, &moves_b);
// 		tmp_b = tmp_b->next;
// 	}
// 	process_moves(list_a, list_b, &moves_a, &moves_b, run_function);
// 	run_remaining_moves(list_a, list_b, &moves_a, &moves_b, run_function);
// }