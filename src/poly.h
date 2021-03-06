#pragma once
#include <stdint.h>
#include <stdbool.h>

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#ifndef DEG_THRESHOLD
#define DEG_THRESHOLD 1000
#endif


// Represent a polynom of degree deg
typedef struct poly_u {
    uint32_t *coef;  // Coef list
    uint32_t deg;    // Polynom degree
} poly_u;

// Print a polynomial
void print_poly_u(poly_u *);

// Allocate a polynomial
poly_u *alloc_poly_u(uint32_t);

// Free a polynomial
void free_poly_u(poly_u *);

// Naive polynomial multiplication
poly_u *mulpu(poly_u *, poly_u *);

// P*X^n multiplication
void mulpx(uint32_t, poly_u *, bool);

// Add two polynomials
void addpu(poly_u *, poly_u *, poly_u *);

// Polynomial equality
bool equal_poly_u(poly_u *, poly_u *);

// Polynomial multiplication with first order decomposition
poly_u *mulpuk1(poly_u *, poly_u *);

// Polynomial cut
void cutpu(uint32_t, uint32_t, poly_u *, poly_u *);

// Negates a polynomial
void negp(poly_u *);

// Recursive multiplication
poly_u *mulpukrt(poly_u *, poly_u *, uint32_t);
poly_u *mulpukr(poly_u *, poly_u *);
