#ifndef E_MATRIX
#define E_MATRIX

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <eError.h>

typedef struct eMatrix{
	int rows,cols;
	double **data;
} eMatrix;

void create_matrix(eMatrix *M,int rows, int cols);
void print_matrix(eMatrix *M);
void random_matrix(eMatrix *M);
void zeros_matrix(eMatrix *M);
void ones_matrix(eMatrix *M);
void eye_matrix(eMatrix *M);
void add_matrix(eMatrix *A, eMatrix *B, eMatrix *C);
void diff_matrix(eMatrix *A, eMatrix *B, eMatrix *C);
void times_matrix(eMatrix *A, eMatrix *B, eMatrix *C);
void dot_matrix(eMatrix *A, eMatrix *B, eMatrix *C);
void eval_matrix(eMatrix *A, double fun(double),eMatrix *M);

void check_size(eMatrix *A, eMatrix *B);
#endif
