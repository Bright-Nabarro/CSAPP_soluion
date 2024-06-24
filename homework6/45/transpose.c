//dst and src is a liner array mulitate 
void transpose_org(int* dst, int* src, int dim)
{
	int i, j;
	for(i = 0; i < dim; i++)
		for(j = 0; j < dim; j++)
			dst[j*dim + i] = src[i*dim + j];
}

//one block with 2*2 elements
void transpose_b2(int* dst, int* src, int dim)
{
	int i = 0, j = 0;
	int limit = dim-1;
	for(i = 0; i < limit; i+=2)
	{
		for(j = 0; j < limit; j+=2)
		{
			dst[j*dim + i] = src[i*dim + j];
			dst[(j+1)*dim + i] = src[i*dim + j+1];
			dst[j*dim + i+1] = src[(i+1)*dim + j];
			dst[(j+1)*dim + i+1] = src[(i+1)*dim + j+1];
		}
	}
	int end_i, end_j;
	for(end_i = i; end_i < dim; end_i++)
	{
		for(end_j = 0; end_j < dim; end_j++)
		{
			dst[end_j*dim + end_i] = src[end_i*dim + end_j];
		}
	}
	for(end_i = 0; end_i < dim; end_i++)
	{
		for(end_j = j; end_j < dim; end_j++)
		{
			dst[end_j*dim + end_i] = src[end_i*dim + end_j];
		}
	}
}

//one block with 4*4 elements
void transpose_b4(int* dst, int* src, int dim)
{
	int i = 0, j = 0;
	int limit = dim-3;
	for(i = 0; i < limit; i+=4)
	{
		for(j = 0; j < limit; j+=4)
		{
			//src viewer
			//first line
			dst[j*dim + i] = src[i*dim + j];
			dst[(j+1)*dim + i] = src[i*dim + j+1];
			dst[(j+2)*dim + i] = src[i*dim + j+2];
			dst[(j+3)*dim + i] = src[i*dim + j+3];
			//second line
			dst[j*dim + i+1] = src[(i+1)*dim + j];
			dst[(j+1)*dim + i+1] = src[(i+1)*dim + j+1];
			dst[(j+2)*dim + i+1] = src[(i+1)*dim + j+2];
			dst[(j+3)*dim + i+1] = src[(i+1)*dim + j+3];

			//thrid line
			dst[j*dim + i+2] = src[(i+2)*dim + j];
			dst[(j+1)*dim + i+2] = src[(i+2)*dim + j+1];
			dst[(j+2)*dim + i+2] = src[(i+2)*dim + j+2];
			dst[(j+3)*dim + i+2] = src[(i+2)*dim + j+3];

			//fourth line
			dst[j*dim + i+3] = src[(i+3)*dim + j];
			dst[(j+1)*dim + i+3] = src[(i+3)*dim + j+1];
			dst[(j+2)*dim + i+3] = src[(i+3)*dim + j+2];
			dst[(j+3)*dim + i+3] = src[(i+3)*dim + j+3];
		}
	}
	int end_i, end_j;
	for(end_i = i; end_i < dim; end_i++)
	{
		for(end_j = 0; end_j < dim; end_j++)
		{
			dst[end_j*dim + end_i] = src[end_i*dim + end_j];
		}
	}
	for(end_i = 0; end_i < dim; end_i++)
	{
		for(end_j = j; end_j < dim; end_j++)
		{
			dst[end_j*dim + end_i] = src[end_i*dim + end_j];
		}
	}
}

void transpose_bi(int* dst, int* src, int dim, int block_size)
{
	int i = 0, j = 0;
	int limit = dim - block_size + 1;
	for(i = 0; i < limit; i += block_size)
	{
		for(j = 0; j < limit; j += block_size)
		{
			int a, b;
			int inline_limit_i = i + block_size;
			int inline_limit_j = j + block_size;
			for(a = i; a < inline_limit_i; a++)
			{
				for(b = j; b < inline_limit_j; b++)
				{
					dst[b*dim + a] = src[a*dim + b];
				}
			}
		}
	}

	int end_i, end_j;
	for(end_i = i; end_i < dim; end_i++)
	{
		for(end_j = 0; end_j < dim; end_j++)
		{
			dst[end_j*dim + end_i] = src[end_i*dim + end_j];
		}
	}
	for(end_i = 0; end_i < dim; end_i++)
	{
		for(end_j = j; end_j < dim; end_j++)
		{
			dst[end_j*dim + end_i] = src[end_i*dim + end_j];
		}
	}
}