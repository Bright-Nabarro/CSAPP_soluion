void transpose_org(int* dst, int* src, int dim);

void transpose_b2(int* dst, int* src, int dim);

void transpose_b4(int* dst, int* src, int dim);

void transpose_bi(int* dst, int* src, int dim, int block_size);

void effective_transpose(int *dst, int *src, int dim, int block_size);