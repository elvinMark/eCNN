#ifndef E_TENSOR
#define E_TENSOR

#include <eMatrix.h>

typedef struct eTensor{
	int num_elems;
	eMatrix elems;
}eTensor;

void create_tensor(eTensor *T, int num_elems);

#endif