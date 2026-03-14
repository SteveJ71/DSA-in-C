# Curve Length Approximation

Approximates the arc length of a curve using numerical integration over 1,000,000 steps.

The arc length formula for a curve f(x) over [a, b] is approximated as:

```
L ≈ Σ sqrt(Δx² + Δy²)
```

where Δx is the step size and Δy = f(x) − f(x_prev).

Demonstrates passing a **function pointer** as a parameter — `curveLength` works on any `double → double` function.

## Demo

Two curves are computed:
1. `sin(x)` from 0 to π  → arc length ≈ **3.8202**
2. `sqrt(1 - x²)` from -1 to 1 → upper semicircle, arc length ≈ **π/2 × 2 = π ≈ 3.1416**

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o curve_length curve_length.c -lm
./curve_length
```
