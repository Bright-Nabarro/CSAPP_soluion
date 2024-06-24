#include <stdbool.h>

#ifdef FLOAT
typedef double data_t;
#else
typedef long data_t;
#endif


typedef struct {
	long len;
	data_t* data;
} vec_rec, * vec_ptr;

vec_ptr new_vec(long len);

bool get_vec_element(vec_ptr v, long index, data_t* dest);

long vec_length(vec_ptr v);

data_t* get_vec_start(vec_ptr u);