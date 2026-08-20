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

//MAIN



//PARSING

void	init_stack_a(int argc, char **argv, t_stack **stack_a);

//PARSING_UTILS

void	ft_error(t_stack **stack, char **arr);
int		check_spaces(char *str);
long	ft_atoi_strict(char *str, t_stack **stack, char **arr);
void	check_duplicates(t_stack **stack);

//SPLIT

size_t	counter(const char *s, char c);
char	*get_word(const char *s, size_t start, size_t end);
void	free_split(char **d, size_t j);
int		fill_split(char **d, const char *s, char c);
char	**ft_split(const char *s, char c);

//STACK UTILS

t_stack	*stack_new(int value);
void	ft_stack_add_back(t_stack **lst, t_stack *new);
void	free_stack(t_stack **stack);
void	free_string_array(char **arr);

// ******************Remove****************


void ft_print_stack(t_stack *stack);  // TO REMOVE
void ft_print_index(t_stack *stack); // TO REMOVE

//SIMPLE ALGO

void    ft_simple_algo(t_stack **a, t_stack **b);
int		ft_stack_size(t_stack *ab);
int		find_min_pos(t_stack *a);
void    simple_sort_to_b(int pos, int size, t_stack **a, t_stack **b);

//MEDIUM ALGO

void	medium_algo(t_stack **a, t_stack **b, int argc);
void	process_chunk(t_stack **a, t_stack **b, t_info *c_info, int size);
int		find_chunk_pos(t_stack *a, t_info *c_info, int size);
void	next_chunk(t_info *c_info, t_stack **b, t_stack **a);
void	intermittent_bsort(t_stack **b, t_stack **a, t_info *c_info);
void    sort_to_a(int pos, int size, t_stack **b, t_stack **a);

//HEAP FUNCTIONS

void	heap_utils(t_stack **a, int size);
void	sort_heap(t_stack **arr, int size);
void	sift_down(t_stack **arr, int size, int i);
void	assign_index(t_stack **arr, int size);
void	add_pos(t_stack	**a);


//OPERATIONS

//MOVES1

void    ft_swap(t_stack **ab);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);

//MOVES2

void    pa(t_stack **b, t_stack **a);
void    pb(t_stack **a, t_stack **b);

//MOVES3

void    ft_rotate(t_stack **ab);
void    ra(t_stack **a);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);

//MOVES4

void    ft_reverse_rotate(t_stack **a);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);


//COMPLEX ALGO

void	quick_sort_b(t_stack **a, t_stack **b, int size);
void	quick_sort_a(t_stack **a, t_stack **b, int size);
int		find_max_val(t_stack *a, int size);
int		find_min_val(t_stack *a, int size);
int		get_pivot(t_stack *a, int size);
long	get_avg(t_stack *a, int size);


//ADAPTIVE

void	ft_adaptive(t_stack **a, t_stack **b, int size);
double	ft_disorder(t_stack *a, int size);

//SELECTOR

static int	is_flag(char *str);
void	execute_strategy(int argc, char **argv, t_stack **a, t_stack **b, int size);



//ROOT

int root(int num);
int	ft_isqrt(int n);

#endif