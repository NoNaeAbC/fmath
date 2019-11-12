#pragma once

#include <stddef.h>
#include <cstdint>
#include <cstdlib>
//#include <mkl.h>

#define CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE 1

#define CN_NOT_IMPLEMENTED -1
#define CN_ERROR_ZERO 1

typedef struct CN_simple_signed_double {
	uint32_t type = CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE;
	double real_value;
	double complex_value;

}Double;


typedef void* CN_number;


CN_number CN_create_double(const double real, const double complex);
void CN_delete_double(CN_number double_);
int add(CN_number a, CN_number b, CN_number result);
int subtract(CN_number a, CN_number b, CN_number result);
int multiply(CN_number a, CN_number b, CN_number result);
int divide(CN_number a, CN_number b, CN_number result);
void CN_get_real(CN_number number, void* real);
void CN_get_complex(CN_number number, void* complex);
