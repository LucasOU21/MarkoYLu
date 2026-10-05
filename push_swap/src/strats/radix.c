#include "push_swap.h"

// Radix sort nad indexima (0..n-1). Za svaki bit, od najnizeg:
//   bit == 0 -> pb (salji u B),  bit == 1 -> ra (ostavi u A, na dno).
// Posle prolaza vrati sve iz B u A (pa). Poslednji bit daje sortiran stek.
// size ostaje isti u svakom prolazu, zato ga cuvamo ranije (A se menja).
void	radix_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	bit;
	int	j;

	size = stack_size(*a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> bit) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			j++;
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
}