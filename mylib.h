#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdint.h>
#include <math.h>

enum direc {Left=0,Right};


extern void larger_of(double *x, double *y);
extern void test_delete_space(const char *str, int str_len);
extern int is_within(const char *str, int str_len, char c);
extern void sort_merge(int *a,int n);
extern void find_nMin(int *arr,int n);
// extern void mult_Karatsuba(uint64_t x, uint64_t y,int n, uint64_t *res);
extern __int128 mult_Karatsuba(uint64_t x, uint64_t y,int n);
extern void  mult_recur(uint64_t *a, uint64_t *b, int n, uint64_t *res);
//p1 point to target str, p2 point to substr
extern int find_subStringNum(char const *p1, char const *p2);

