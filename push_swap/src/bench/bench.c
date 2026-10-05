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

// Imena za ispis. Redosled MORA da bude isti kao u enum-u t_op u push_swap.h.
// "static const" niz nije globalna promenljiva koja se menja, samo tabela.
static const char	*g_names[OP_COUNT] = {"sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr"};

// Postavlja sve brojace na 0. Zovi je jednom u main-u pre sortiranja.
void	bench_init(t_bench *bench)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		bench->ops[i] = 0;
		i++;
	}
}

// Zbir svih operacija = ukupan broj izvrsenih operacija.
int	bench_total(t_bench *bench)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < OP_COUNT)
	{
		sum += bench->ops[i];
		i++;
	}
	return (sum);
}

// Ispisuje broj na zadati fd. ft_itoa alocira string, pa ga moramo free.
static void	put_num(int n, int fd)
{
	char	*s;

	s = ft_itoa(n);
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	free(s);
}

// Ispisuje disorder kao procenat sa 2 decimale (npr. 0.4512 -> "45.12%").
// pct je disorder * 10000 kao ceo broj: 4512. Deljenje sa 100 daje celi deo
// (45), ostatak sa 100 daje decimale (12). Ako je ostatak < 10 dodajemo
// nulu ispred, da 5 ne postane "45.5" umesto "45.05".
static void	put_percent(double disorder)
{
	int	pct;

	pct = (int)(disorder * 10000);
	put_num(pct / 100, 2);
	ft_putchar_fd('.', 2);
	if (pct % 100 < 10)
		ft_putchar_fd('0', 2);
	put_num(pct % 100, 2);
	ft_putchar_fd('%', 2);
}

// Ispisuje svu statistiku na STDERR (fd 2), da se ne pomesa sa operacijama
// na stdout. Zove se samo kad je zadat --bench.
void	bench_print(t_bench *bench, double disorder, char *strategy)
{
	int	i;

	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n[bench] total ops: ", 2);
	put_num(bench_total(bench), 2);
	ft_putstr_fd("\n[bench] ", 2);
	i = 0;
	while (i < OP_COUNT)
	{
		ft_putstr_fd((char *)g_names[i], 2);
		ft_putstr_fd(": ", 2);
		put_num(bench->ops[i], 2);
		if (i < OP_COUNT - 1)
			ft_putstr_fd("  ", 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
}