#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h> // removeeeeeeeeeeee
//ALL HELPER FUNCTIONS SHOULD BE STATIC?

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	int				above_median;
	double			disorder;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_info
{
	int				ch_size;
	int				up;
	int				low;
	int				pos;
	int				count;
	int				k;
}	t_info;


typedef	struct s_a_state
{
	t_stack	**a;
	t_stack	*tail;
	int		size;
}	t_a_state;

typedef	struct s_rot
{
	int	cost_a;
	int	depth;
	int	forward;
}	t_rot;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

//MAIN

int main(int argc,char **argv);


//PARSING

static void	init_loop(char **split_args, t_stack **stack_a);
void	init_stack_a(int argc, char **argv, t_stack **stack_a);

//PARSING_UTILS

void	ft_error(t_stack **stack, char **arr);
int		check_spaces(char *str);
long	ft_atoi_strict(char *str, t_stack **stack, char **arr);
long	atoi_loop(char *str,t_stack **stack,char **arr,int sign);
void	check_duplicates(t_stack **stack);

//SPLIT

size_t	counter(const char *s, char c);
void	free_split(char **d, size_t j);
int		fill_split(char **d, const char *s, char c);
char	**ft_split(const char *s, char c);
char	*get_word(const char *s, size_t start, size_t end);

//STACK UTILS

t_stack	*stack_new(int value);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack **stack);
void	free_string_array(char **arr);

// ******************Remove********************************

void ft_print_stack(t_stack *stack);  // TO REMOVE
void ft_print_index(t_stack *stack); // TO REMOVE
//***********************Remove***************************
//SIMPLE ALGO

void    ft_simple_algo(t_stack **a, t_stack **b, int *counts);
int		ft_stack_size(t_stack *ab);
int		find_min_pos(t_stack *a);
void    simple_sort_to_b(int pos, int size, t_stack **a, t_stack **b, int *counts);

//MEDIUM1

void	medium_algo(t_stack **a, t_stack **b, int n, int *count);
void	chunk_sort(t_stack **a, t_stack **b, t_info *info, int *count);
void	process_chunk(t_a_state *st, t_stack **b, t_info *info, int *count);
void	move_one(t_a_state *st, t_stack **b, t_info *info, int *count);
int		compute_dist(t_a_state *st, t_info *info, int *res_pos, int *res_index);

//MEDIUM2

t_stack *scan_front(t_stack *head, t_info *info, int *pos_f);
t_stack *scan_back(t_stack *tail, t_info *info, int *pos_b);
int	insertion_depth(t_stack *b, int placed, int index);
void	rotate_extraction(t_a_state *st, t_stack **b, t_rot *r, int *count);
void	merge_forward(t_a_state *st, t_stack **b, t_rot *r, int *count);

//MEDIUM UTILS

int  	chunk_count(int n);
t_stack *find_tail(t_stack *a);

//HEAP FUNCTIONS

void	heap_utils(t_stack **a, int size);
void	sort_heap(t_stack **arr, int size);
void	sift_down(t_stack **arr, int size, int i);
void	assign_index(t_stack **arr, int size);
void	add_pos(t_stack	**a);


//OPERATIONS

void	ft_swap(t_stack **ab);
void    sa(t_stack **a, int *counts);
void    sb(t_stack **b, int *counts);
void    ss(t_stack **a, t_stack **b, int *counts);
void    pa(t_stack **b, t_stack **a, int *counts);
void    pb(t_stack **a, t_stack **b, int *counts);
void    ft_rotate(t_stack **ab);
void    ra(t_stack **a, int *counts);
void    rb(t_stack **b, int *counts);
void    rr(t_stack **a, t_stack **b, int *counts);
void    ft_reverse_rotate(t_stack **a);
void    rra(t_stack **a, int *counts);
void    rrb(t_stack **b, int *counts);
void    rrr(t_stack **a, t_stack **b, int *counts);

//COMPLEX ALGO

void	quick_sort_b(t_stack **a, t_stack **b, int size, int *counts);
void	quick_sort_a(t_stack **a, t_stack **b, int size, int *counts);
int		get_pivot(t_stack *a, int size);

//COMPLEX_HELP

void	loop_a(t_stack **a, t_stack **b, int pivot, int size,
		int *smaller, int *bigger, int *counts);
void	loop_b(t_stack **a, t_stack **b, int pivot, int size,
		int *smaller, int *bigger, int *counts);
int		pivot_loop(t_stack *a, int *stackar, int size);

//ADAPTIVE

void	ft_adaptive(t_stack **a, t_stack **b, int size, int *counts);
double	ft_disorder(t_stack *a, int size);

//SELECTOR

static int	is_flag(char *str);
void	execute_strategy(int argc, char **argv, t_stack **a, t_stack **b, int size);



//ROOT

int root(int num);
int	ft_isqrt(int n);

#endif
