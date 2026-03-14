# Monte Carlo Simulations

Three randomized simulation programs demonstrating Monte Carlo techniques and probabilistic analysis.

## Programs

### `area.c` — Circle area estimation

Estimates the area of a unit circle (≈ π) by sampling random points in a 3×3 bounding box and counting how many fall inside the circle. Runs with increasing step counts from 1 to 100,000,000.

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o area area.c -lm
./area
```

### `game.c` — Dice gambling simulation

Simulates a dice game 10,000 times:
- Start with $5, pay $1 per roll
- Roll 2d6: total ≤7 → lose; 8-11 → win $2; 12 → win $6
- Stop at $0 (bust) or $20 (win)

Reports the empirical win probability and average game length.

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o game game.c
./game
```

### `twoUp.c` — Two Up coin game

Simulates 125 rounds of Two Up (Australian coin toss game): flip two coins, only count rounds where both show the same face. Heads-heads wins the bet; tails-tails loses.

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o twoUp twoUp.c
./twoUp
```
