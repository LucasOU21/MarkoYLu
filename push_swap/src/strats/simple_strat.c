/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:13 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/25 17:44:14 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// How many steps from the top is the node with this index? Top = 0.
static int	index_position(t_node *a, int index)
{
	int	pos;

	pos = 0;
	while (a && a->index != index)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

// Brings the node at position pos to the top of A the shortest way:
// upper half -> ra (pos times), lower half -> rra (size - pos times).
static void	bring_to_top(t_node **a, int pos, int size, t_bench *bench)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a, bench);
			pos++;
		}
	}
}

// Selection sort with two stacks, O(n^2) operations.
// Find the smallest (index 0), bring it to the top, pb. Then index 1, 2...
// The last one left in A is the biggest, so it stays. Then pa everything
// back: B gives them from biggest to smallest, so A ends up sorted.
// assign_index must be called before this.
void	simple_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size - 1)
	{
		bring_to_top(a, index_position(*a, i), size - i, bench);
		pb(a, b, bench);
		i++;
	}
	while (*b)
		pa(a, b, bench);
}

/*
EXPLANATION OF THE SIMPLE STRATEGY (selection sort with two stacks)

The idea: take the smallest number out of A and put it in B, then the next
smallest, and so on. When A has only the biggest number left, bring
everything back from B. A is then sorted.

We never look at value here, only at index. assign_index (called in main)
gave every node its rank: 0 for the smallest, 1 for the next, ... n-1 for
the biggest. So "find the smallest" just means "find index 0".

--- index_position(a, index) ---
Walks down the stack from the top and counts the steps until it finds the
node with the index we want. Top = position 0, the one below = 1, etc.
Example: A is 5 4 3 2 1 (indexes 4 3 2 1 0). Index 0 is at position 4.

--- bring_to_top(a, pos, size, bench) ---
Moves the node at position pos up to the top, the shortest way.
  - If it is in the upper half (pos <= size / 2): do ra, pos times.
    Each ra sends the top to the bottom, so our node climbs one step.
  - If it is in the lower half: do rra, (size - pos) times.
    Each rra brings the bottom to the top, so it is faster from below.
Example: size 5, pos 4 -> lower half -> 1 rra instead of 4 ra.
size here is how many nodes are STILL in A, not the original size.

--- simple_sort(a, b, bench) ---
size = how many numbers we have. i = the index we are looking for now.
Loop while i < size - 1:
  1. index_position finds where index i is in A.
  2. bring_to_top moves it to the top. We pass size - i because A has
     already lost i nodes (they are in B).
  3. pb pushes it to B.
  4. i++ -> now look for the next smallest.
We stop at size - 1 because the last node left in A is the biggest one,
there is no need to push it and bring it back.
Then: while B is not empty, pa. B has the biggest of its numbers on top
(it was pushed last), so they land in A from big to small, each one on
top of the previous. Result: smallest on top, A sorted.

--- Example: 3 1 2 (indexes 2 0 1) ---
  i = 0: index 0 is at pos 1, size 3 -> upper half -> ra.  A: 1 2 3
         pb.                                               A: 2 3   B: 1
  i = 1: index 1 is at pos 0 -> nothing to rotate.
         pb.                                               A: 3     B: 2 1
  stop (only the biggest is left in A)
  pa pa.                                                   A: 1 2 3
Output: ra pb pb pa pa (5 operations)

--- Why it is O(n^2) ---
For each of the n numbers we may rotate up to n / 2 times to bring it to
the top. So the number of operations grows with n * n, not with n.
100 numbers -> up to about 1700 ops. 500 numbers -> up to about 34000 ops.
5 times more numbers = about 20-25 times more operations.
*/
