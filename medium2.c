#include "push_swap.h"


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
	node = node->next;
	}
	return (d);
}


void	rotate_extraction(t_a_state *st, t_stack **b, t_rot *r, int *count)
{
	if (r->forward)
		merge_forward(st, b, r, count);
	else
		while ((r->cost_a)-- > 0)
		{
			st->tail = st->tail->prev;
			rra(st->a, count);
		}
}

void	merge_forward(t_a_state *st, t_stack **b, t_rot *r, int *count)
{
	int	merged;

	merged = r->cost_a;
	if (r->depth < merged)
		merged = r->depth;
	r->cost_a -= merged;
	r->depth -= merged;
	while (merged-- > 0)
	{
		st->tail = *st->a;
		rr(st->a, b, count);
	}
	while ((r->cost_a)-- > 0)
	{
		st->tail = *st->a;
		ra(st->a, count);
	}
}
