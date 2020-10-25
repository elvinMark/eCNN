#include <eMatrix.h>

void create_matrix(eMatrix *M,int rows, int cols){
  int i;
  M->rows = rows;
  M->cols = cols;
  M->data = (double **) malloc(sizeof(double*)*rows);
  for(i=0;i<rows;i++)
    M->data[i] = (double *)malloc(sizeof(double)*cols);
}

void print_matrix(eMatrix *M){
  int i,j;
  for(i=0;i<M->rows;i++){
    for(j=0;j<M->cols;j++)
      printf("%lf ",M->data[i][j]);
    printf("\n");
  }
}

void random_matrix(eMatrix *M){
  int i,j;
  for(i=0;i<M->rows;i++)
    for(j=0;j<M->cols;j++)
      M->data[i][j] = (rand()%1000)/1000.0;
}

void zeros_matrix(eMatrix *M){
  int i,j;
  for(i=0;i<M->rows;i++)
    for(j=0;j<M->cols;j++)
      M->data[i][j] = 0;
}

void ones_matrix(eMatrix *M){
  int i,j;
  for(i=0;i<M->rows;i++)
    for(j=0;j<M->cols;j++)
      M->data[i][j] = 1;
}
void eye_matrix(eMatrix *M){
  int i,j;
  for(i=0;i<M->rows;i++)
    for(j=0;j<M->cols;j++){
      if(i!=j)
	M->data[i][j] = 0;
      else
	M->data[i][j] = 1;
    }
}

void add_matrix(eMatrix *A, eMatrix *B, eMatrix *C){
  int i,j;
  check_size(B,C);
  create_matrix(A,B->rows,B->cols);
  for(i=0;i<B->rows;i++)
    for(j=0;j<B->cols;j++)
      A->data[i][j] = B->data[i][j] + C->data[i][j];
}

void diff_matrix(eMatrix *A, eMatrix *B, eMatrix *C){
  int i,j;
  check_size(B,C);
  create_matrix(A,B->rows,B->cols);
  for(i=0;i<B->rows;i++)
    for(j=0;j<B->cols;j++)
      A->data[i][j] = B->data[i][j] - C->data[i][j];
}

void times_matrix(eMatrix *A, eMatrix *B, eMatrix *C){
  int i,j;
  check_size(B,C);
  create_matrix(A,B->rows,B->cols);
  for(i=0;i<B->rows;i++)
    for(j=0;j<B->cols;j++)
      A->data[i][j] = B->data[i][j] * C->data[i][j];
}

void dot_matrix(eMatrix *A, eMatrix *B, eMatrix *C){
  int i,j,k;
  double s;
  if(B->cols != C->rows){
    print_error("Size of matrices are not align");
    exit(0);
  }
  create_matrix(A,B->rows,C->cols);
  for(i=0;i<B->rows;i++){
    for(j=0;j<C->cols;j++){
      s = 0;
      for(k=0;k<B->cols;k++)
	s += B->data[i][k] * C->data[k][j];
      A->data[i][j] = s;
    }
  }
}

void eval_matrix(eMatrix *A, double fun(double),eMatrix *M){
  int i,j;
  create_matrix(A,M->rows,M->cols);
  for(i=0;i<M->rows;i++)
    for(j=0;j<M->cols;j++)
      A->data[i][j] = fun(M->data[i][j]);
}

void check_size(eMatrix *A, eMatrix *B){
  if(A->rows != B->rows || A->cols != B->cols){
    print_error("Sizes of matrices are different");
    exit(0);
  }
}
