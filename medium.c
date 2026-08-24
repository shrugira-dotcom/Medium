

#include "push_swap.h"

void	medium_algo(t_stack **a, t_stack **b, int n)
{
	t_info	info;

	if (n <= 1)
		return ;
	heap_utils(a, n);
	info.count = n;
	info.k = chunk_count(n);
	chunk_sort(a, b, &info);
}

void	chunk_sort(t_stack **a, t_stack **b, t_info *info)
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
		process_chunk(&st, b, info);
		info->low = info->up;
		chunk++;
	}
	while (*b)
		pa(b, a);
}

void	process_chunk(t_a_state *st, t_stack **b, t_info *info)
{
	int	remaining;

	remaining = info->ch_size;
	info->pos = 0;
	while (remaining > 0)
	{
		move_one(st, b, info);
		info->pos++;
		remaining--;

	}
}

void	move_one(t_a_state *st, t_stack **b, t_info *info)
{
	int	move_pos;
	int	index;
	int	depth;
	int cost_a;
	int	reverse_b;

	if (!compute_dist(st, info, &move_pos, &index))
		return ;
	cost_a = move_pos;
	if (st->size - move_pos < cost_a)
		cost_a = st->size - move_pos;
	depth = insertion_depth(*b, info->pos, index);
	reverse_b = depth;
	rotate_extraction(st, b, cost_a == move_pos, &cost_a, &depth);
	while (depth-- > 0)
		rb(b);
	pb(st->a, b);
	st->size--;
	while (reverse_b-- > 0)
		rrb(b);
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

t_stack *scan_front(t_stack *head, t_info *info, int *pos_f)
{
    int i;

    i = 0;
    while (head)
    {
        if (head->index >= info->low && head->index < info->up)
        {
            *pos_f = i;
            return (head);
        }
        i++;
        head = head->next;
    }
    return (NULL);
}

t_stack *scan_back(t_stack *tail, t_info *info, int *pos_b)
{
    int i;

    i = 1;
    while (tail)
    {
        if (tail->index >= info->low && tail->index < info->up)
        {
            *pos_b = i;
            return (tail);
        }
        i++;
        tail = tail->prev;
    }
    return (NULL);
}

int	insertion_depth(t_stack *b, int placed, int index)
{
	int		d;
	t_stack *node;

	d = 0;
	node = b;
	while (node && placed-- > 0)
	{
	if (node->index < index)
			break;
		d++;
	}
	return (d);
}


void	rotate_extraction(t_a_state *st, t_stack **b, int forward, int *cost_a, int *depth)
{
	if (forward)
		merge_forward(st, b, cost_a, depth);
	else
		while ((*cost_a)-- > 0)
		{
			st->tail = st->tail->prev;
			rra(st->a);
		}
}

void	merge_forward(t_a_state *st, t_stack **b, int *cost_a, int *depth)
{
	int	merged;

	merged = *cost_a;
	if (*depth < merged)
		merged = *depth;
	*cost_a -= merged;
	*depth -= merged;
	while (merged-- > 0)
	{
		st->tail = *st->a;
		rr(st->a, b);
	}
	while ((*cost_a)-- > 0)
	{
		st->tail = *st->a;
		ra(st->a);
	}
}

