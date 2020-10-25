#include <eMatrix.h>

int main(){
  eMatrix A,B;
  create_matrix(&A,3,3);
  random_matrix(&A);
  dot_matrix(&B,&A,&A);
  print_matrix(&A);
  print_matrix(&B);
  return 0;
}
