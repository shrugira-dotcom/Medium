

#include "push_swap.h"

void	medium_algo(t_stack **a, t_stack **b, int n, int count)
{
	t_info	info;

	if (n <= 1)
		return ;
	heap_utils(a, n);
	info.count = n;
	info.k = chunk_count(n);
	chunk_sort(a, b, &info, count);
}

void	chunk_sort(t_stack **a, t_stack **b, t_info *info, int count)
{
	t_a_state	st;
	int			chunk;
	int			base;
	int			extra_chunks;

	st.a = a;
	st.size = info->count;
	st.tail = find_tail(*a);
	base = info->count / info->k;
	extra_chunks = info->count % info->k;
	info->low = 0;
	chunk = 0;
	while (chunk < info->k)
	{
		info->ch_size = base + (chunk < extra_chunks);
		info->up = info->low + info->ch_size;
		process_chunk(&st, b, info, count);
		info->low = info->up;
		chunk++;
	}
	while (*b)
		pa(b, a, count);
}

void	process_chunk(t_a_state *st, t_stack **b, t_info *info, int count)
{
	int	remaining;

	remaining = info->ch_size;
	info->pos = 0;
	while (remaining > 0)
	{
		move_one(st, b, info, count);
		info->pos++;
		remaining--;

	}
}

void	move_one(t_a_state *st, t_stack **b, t_info *info, int count)
{
	int		move_pos;
	int		index;
	int		reverse_b;
	t_rot	r;

	if (!compute_dist(st, info, &move_pos, &index))
		return ;
	r.cost_a = move_pos;
	if (st->size - move_pos < r.cost_a)
		r.cost_a = st->size - move_pos;
	r.depth = insertion_depth(*b, info->pos, index);
	reverse_b = r.depth;
	rotate_extraction(st, b, r.cost_a == move_pos, &r, count);
	while (r.depth-- > 0)
		rb(b, count);
	pb(st->a, b);
	st->size--;
	while (reverse_b-- > 0)
		rrb(b, count);
}

int	compute_dist(t_a_state *st, t_info *info, int *res_pos, int *res_index)
{
	t_stack	*front;
	t_stack	*back;
	int		pos_f;
	int		pos_b;

	pos_b = 0;
	front = scan_front(*st->a, info, &pos_f);
	if (!front)
		return (0);
	back = scan_back(st->tail, info, &pos_b);
	if (pos_b < pos_f)
	{
		*res_pos = st->size - pos_b;
		*res_index = back->index;
	}
	else
	{
		*res_pos = pos_f;
		*res_index = front->index;
	}
	return (1);
}


