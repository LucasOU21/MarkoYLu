#include "push_swap.h"

// Chunk size = square root of n, rounded up, without math.h.
// 9 -> 3, 100 -> 10, 500 -> 23.
static int chunk_size(int n) {
  int chunk;

  chunk = 1;
  while (chunk * chunk < n)
    chunk++;
  return (chunk);
}

// How many steps from the top of B is the node with the biggest index?
// Top = 0.
static int max_position(t_node *b) {
  int pos;
  int max_pos;
  int max;

  pos = 0;
  max_pos = 0;
  max = -1;
  while (b) {
    if (b->index > max) {
      max = b->index;
      max_pos = pos;
    }
    pos++;
    b = b->next;
  }
  return (max_pos);
}

// Brings the biggest node of B to the top of B the shortest way:
// upper half -> rb (pos times), lower half -> rrb (size - pos times).
static void max_to_top(t_node **b, t_bench *bench) {
  int pos;
  int size;

  pos = max_position(*b);
  size = stack_size(*b);
  if (pos <= size / 2) {
    while (pos > 0) {
      rb(b, bench);
      pos--;
    }
  } else {
    while (pos < size) {
      rrb(b, bench);
      pos++;
    }
  }
}

// Chunk sort with two stacks, O(n * sqrt(n)) operations.
// Phase 1: push A to B chunk by chunk (smallest chunk first).
// Phase 2: bring back to A, always the biggest of B first.
// assign_index must be called before this.
void medium_sort(t_node **a, t_node **b, t_bench *bench) {
  int chunk;
  int limit;
  int pushed;

  chunk = chunk_size(stack_size(*a));
  limit = chunk;
  pushed = 0;
  while (*a) {
    if ((*a)->index < limit) {
      pb(a, b, bench);
      pushed++;
      if (pushed == limit)
        limit += chunk;
    } else
      ra(a, bench);
  }
  while (*b) {
    max_to_top(b, bench);
    pa(a, b, bench);
  }
}

/*
EXPLANATION OF THE MEDIUM STRATEGY (chunk sort with two stacks)

The idea (same as practice/chunk_sort.c, but with stacks): cut the numbers
into groups ("chunks") by size. Push the group of the smallest numbers to B,
then the next group, and so on. B is then "sorted by blocks": small numbers
at the bottom, big numbers on top. Then bring everything back to A, always
the biggest one first.

Like simple_sort, we only look at index, never at value. Index 0 is the
smallest number, n-1 the biggest. That is why chunks are easy: chunk 1 is
indexes 0..chunk-1, chunk 2 is the next ones, and negative numbers are no
problem (the array version in practice/ breaks with negatives).

--- chunk_size(n) ---
We want sqrt(n) but math.h is not allowed. So we count up: 1, 2, 3 ...
until chunk * chunk is not smaller than n anymore.
Example n = 9:  1*1=1 <9, 2*2=4 <9, 3*3=9 not <9 -> stop, chunk = 3.
Example n = 10: 3*3=9 <10, 4*4=16 -> chunk = 4 (rounded up).

--- max_position(b) ---
Walks down B and remembers where it saw the biggest index.
max starts at -1 so the first node always wins (indexes start at 0).
Example: B is 7 8 5 (indexes 6 7 4) -> the biggest is at position 1.

--- max_to_top(b, bench) ---
Same trick as bring_to_top in simple_sort, but for B and for the max:
upper half -> rb, lower half -> rrb, whichever is shorter.

--- medium_sort(a, b, bench) ---
chunk  = how many numbers are in one chunk.
limit  = "I am now pushing every index SMALLER than this".
pushed = how many nodes are already in B.

PHASE 1 (first while): look at the top of A.
  - index < limit  -> it belongs to the chunk we are collecting -> pb.
  - otherwise      -> not yet -> ra (it goes to the bottom of A, we will
                      see it again later).
  The line "if (pushed == limit) limit += chunk" is the important one:
  there are exactly `limit` numbers with index smaller than limit
  (indexes 0, 1, ... limit-1). So when pushed reaches limit, the chunk is
  complete and we open the next chunk by making limit bigger.
  For the last chunk, limit can be bigger than n. No problem: then every
  node left in A is "smaller than limit", all get pushed, A becomes empty
  and the loop stops.

PHASE 2 (second while): B is not empty ->
  max_to_top puts the biggest of B on top, pa sends it to A.
  The next biggest lands on top of it, and so on. The smallest comes last,
  so it ends on top. A is sorted.

--- Example: 7 2 9 1 5 8 3 6 4 (indexes 6 1 8 0 4 7 2 5 3), chunk = 3 ---
Phase 1, limit = 3 (want indexes 0 1 2 = values 1 2 3):
  ra pb ra pb ra ra pb      A: 6 4 7 9 5 8        B: 3 1 2
limit = 6 (values 4 5 6):
  pb pb ra ra pb            A: 8 7 9              B: 5 4 6 3 1 2
limit = 9 (values 7 8 9):
  pb pb pb                  A: (empty)            B: 9 7 8 5 4 6 3 1 2
Phase 2:
  pa                        9 was on top
  rb pa                     8 was at position 1
  rrb pa                    7 was at the bottom: 1 rrb instead of 6 rb
  rb rb pa                  6
  rrb rrb pa                5
  pa pa                     4, 3
  rb pa                     2
  pa                        1                     A: 1 2 3 4 5 6 7 8 9
31 operations. The full table is in notes/pseudocode.txt.

--- Why it is O(n * sqrt(n)) ---
Phase 1: there are about sqrt(n) chunks. To collect one chunk we go
through A at most once, so at most n operations. sqrt(n) chunks * n.
Phase 2: the biggest number left is always in the top block of B (or
among the few nodes we just rotated to the bottom), so it is about
sqrt(n) steps away, never n steps. n numbers * sqrt(n) steps.
Both phases: n * sqrt(n).
*/
