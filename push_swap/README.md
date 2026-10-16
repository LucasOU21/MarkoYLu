*This project has been created as part of the 42 curriculum by mmitrovi, loulivei.*

# Push_swap

## Description
**push_swap** is a 42 project done in pairs. It sorts a stack of integers using two stacks (`a` and `b`) and a limited set of operations (`sa sb ss pa pb ra rb rr rra rrb rrr`), printing the shortest sequence of moves it can find.

## Project structure
```
push_swap/
├── main.c          # entry point: parse, pick strategy, sort
├── push_swap.h     # types and prototypes
├── Makefile
├── libft/          # custom C library
└── src/
    ├── parsing/    # argument parsing, validation, flags
    ├── stack/      # linked-list stack creation, indexing, info
    ├── ops/        # swap, push, rotate, reverse rotate
    ├── disorder/   # disorder metric (0 = sorted, 1 = reversed)
    ├── strats/     # sorting strategies
    └── bench/      # --bench statistics
```

## Instructions

```bash
make            # build push_swap
make clean      # remove object files
make fclean     # remove objects and binary
make re         # rebuild from scratch
```

Run it with unique integers:
```bash
./push_swap 4 67 3 87 23
```

Optional flags:
- `--simple`, `--medium`, `--complex`, `--adaptive` select a strategy (`--adaptive` is the default). Only **one** of these may be given; combining two (e.g. `--simple --medium`) prints `Error`.
- `--bench` prints statistics to stderr. It can be combined with any single strategy flag.

## Algorithms

| Strategy | Complexity | Idea |
|----------|-----------|------|
| Simple | O(n²) | Repeatedly move the next smallest element to `b`, then push all back. |
| Medium | O(n√n) | Split values into √n chunks and push chunk by chunk. |
| Complex | O(n log n) | Sliding-window (k-sort) push to `b`, then bring back the largest first. |
| Adaptive (default) | varies | Measures disorder and picks: < 0.2 simple, 0.2–0.5 medium, otherwise (or > 100 elements) complex. |

Inputs of 2–5 elements use a hardcoded small sort instead.

## Resources
- [Man7 Linux Manual Pages](https://man7.org/linux/man-pages/)
- 42 push_swap subject PDF

### AI usage
AI was used to draft this README and to review argument error handling (non-numeric input, overflow, duplicates). All C code and testing were written and verified by the authors.
