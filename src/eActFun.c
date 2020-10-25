#include <eActFun.h>

double sigmoid(double x){
  return 1/(exp(-x) + 1)
}

double tanh(double x){
  return (1 - exp(-x))/(exp(-x) + 1);
}

double relu(double x){
  if(x>0)
    return x;
  return 0;
}

double leaky_relu(double x){
  if(x>0)
    return x;
  return 0.001*x;
}

double linear(double x){
  return x;
}
