/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:49:18 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/05 17:13:41 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bench_init(t_bench *bench) { ft_bzero(bench, sizeof(t_bench)); }

// Writes a label and then a number to stderr, for example " pa: 5".
// Why: we print "some text + a number" 12 times, so we write it once here.
static void put_count(char *label, int count) {
  ft_putstr_fd(label, 2);
  ft_putnbr_fd(count, 2);
}

static void put_disorder(double disorder) {
  int pct;

  pct = (int)(disorder * 10000 + 0.5);
  ft_putnbr_fd(pct / 100, 2);
  ft_putstr_fd(".", 2);
  if (pct % 100 < 10)
    ft_putstr_fd("0", 2);
  ft_putnbr_fd(pct % 100, 2);
  ft_putstr_fd("%", 2);
}

// Writes how many times each of the 11 operations was used, on two lines.
// Why: it is its own function only to keep bench_print under 25 lines.
static void put_ops(t_bench *bench) {
  ft_putstr_fd("[bench]", 2);
  put_count(" sa: ", bench->sa);
  put_count(" sb: ", bench->sb);
  put_count(" ss: ", bench->ss);
  put_count(" pa: ", bench->pa);
  put_count(" pb: ", bench->pb);
  ft_putstr_fd("\n[bench]", 2);
  put_count(" ra: ", bench->ra);
  put_count(" rb: ", bench->rb);
  put_count(" rr: ", bench->rr);
  put_count(" rra: ", bench->rra);
  put_count(" rrb: ", bench->rrb);
  put_count(" rrr: ", bench->rrr);
  ft_putstr_fd("\n", 2);
}

// Prints the whole report. Called in main only when --bench was given.
// Everything goes to stderr (fd 2) so it never mixes with the operations
// on stdout. disorder is the value measured BEFORE sorting.
void bench_print(t_bench *bench, double disorder, char *strategy) {
  int total;

  total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb +
          bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb +
          bench->rrr;
  ft_putstr_fd("[bench] disorder: ", 2);
  put_disorder(disorder);
  ft_putstr_fd("\n[bench] strategy: ", 2);
  ft_putstr_fd(strategy, 2);
  put_count("\n[bench] total_ops: ", total);
  ft_putstr_fd("\n", 2);
  put_ops(bench);
}
