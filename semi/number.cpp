#include "lib.h"






	CN_number CN_create_double(const double real,const double complex)
	{
		CN_number return_value = malloc(sizeof(Double));
		((Double*)return_value)->type = CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE;
		((Double*)return_value)->real_value = real;
		((Double*)return_value)->complex_value = complex;
		return return_value;
		
	}

	void CN_delete_double(CN_number double_)
	{
		free(double_);
	}


	void CN_get_real(CN_number number,void* real)
	{
		switch (*(int *)number)
		{
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			double number_real = ((Double*)number)->real_value;
			*((double *)real) = number_real;
			break;
		}
		
	}

	void CN_get_complex(CN_number number, void* complex)
	{
		switch (*(int*)number)
		{
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			double number_complex = ((Double*)number)->complex_value;
			*((double*)complex) = number_complex;
			break;
		}

	}

// addition

	int CN_add_simple_double(Double* a, CN_number b,CN_number result) {
		uint32_t type_b = *(uint32_t*)b;
		switch (type_b) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			((Double *)result)->type = CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE;
			Double *b_cast = (Double*)b;
			((Double*)result)->real_value = b_cast->real_value +a->real_value;
			((Double*)result)->complex_value = b_cast->complex_value+a->complex_value;
			return 0;
			break;
		}
		
		return CN_NOT_IMPLEMENTED;
	}

	int add(CN_number a, CN_number b, CN_number result) {

		uint32_t type_a = *(uint32_t*)a;
		switch (type_a) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			
			return CN_add_simple_double((Double*)a, b,result);
			break;
		}

		return CN_NOT_IMPLEMENTED;

	}



	// subtraction


	int CN_sub_simple_double(Double* a, CN_number b, CN_number result) {
		uint32_t type_b = *(uint32_t*)b;
		switch (type_b) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			((Double*)result)->type = CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE;
			Double* b_cast = (Double*)b;
			((Double*)result)->real_value =   a->real_value- b_cast->real_value;
			((Double*)result)->complex_value =   a->complex_value- b_cast->complex_value;
			return 0;
			break;
		}

		return CN_NOT_IMPLEMENTED;
	}

	int subtract(CN_number a, CN_number b, CN_number result) {

		uint32_t type_a = *(uint32_t*)a;
		switch (type_a) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:

			return CN_sub_simple_double((Double*)a, b, result);
			break;
		}

		return CN_NOT_IMPLEMENTED;

	}


	//multiply

	int CN_mul_simple_double(Double* a, CN_number b, CN_number result) {
		uint32_t type_b = *(uint32_t*)b;
		switch (type_b) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			((Double*)result)->type = CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE;
			Double* b_cast = (Double*)b;
			((Double*)result)->real_value = b_cast->real_value * a->real_value - b_cast->complex_value * a->complex_value;
			((Double*)result)->complex_value = b_cast->complex_value * a->real_value + a->complex_value* b_cast->real_value;
			return 0;
			break;
		}

		return CN_NOT_IMPLEMENTED;
	}

	int multiply(CN_number a, CN_number b, CN_number result) {

		uint32_t type_a = *(uint32_t*)a;
		switch (type_a) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:

			return CN_mul_simple_double((Double*)a, b, result);
			break;
		}

		return CN_NOT_IMPLEMENTED;

	
	}

	//divide
	int CN_div_simple_double(Double* a, CN_number b, CN_number result) {
		uint32_t type_b = *(uint32_t*)b;
		switch (type_b) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:
			((Double*)result)->type = CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE;
			Double* b_cast = (Double*)b;
			if(b_cast->complex_value==0&&b_cast->real_value==0)
			{
				return CN_ERROR_ZERO;
			}
			
			((Double*)result)->real_value =	(  b_cast->real_value    * a->real_value
												 + b_cast->complex_value * a->complex_value)
												 /(b_cast->complex_value * b_cast->complex_value
												 + b_cast->real_value    * b_cast->real_value);
			
			((Double*)result)->complex_value = (  b_cast->real_value     * a->complex_value
												 - b_cast->complex_value  * a->real_value)
												 / (b_cast->complex_value * b_cast->complex_value
												 + b_cast->real_value     * b_cast->real_value);


			
			return 0;
			break;
		}

		return CN_NOT_IMPLEMENTED;
	}

	int divide(CN_number a, CN_number b, CN_number result) {

		uint32_t type_a = *(uint32_t*)a;
		switch (type_a) {
		case CN_STRUCTURE_TYPE_SIMPLE_SIGNED_DOUBLE:

			return CN_div_simple_double((Double*)a, b, result);
			break;
		}

		return CN_NOT_IMPLEMENTED;


	}

