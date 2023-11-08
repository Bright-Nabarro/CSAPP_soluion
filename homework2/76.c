#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *m_calloc(size_t nmemb, size_t size)
{
	if (nmemb == 0 || size == 0)
		return NULL;
	uint64_t r64 = (uint64_t)nmemb * size;
	size_t r = nmemb * size;
	if (r != r64)
		return NULL;
	void *p_result = malloc(r);
	if (p_result == NULL)
		return NULL;
	memset(p_result, 0, r);
	return p_result;
}

int main(void)
{
	void *p;
	p = m_calloc(0x1234, 1);
	assert(p != NULL);
	free(p);

	p = m_calloc(SIZE_MAX, 2);
	assert(p == NULL);
	free(p);

	p = m_calloc(0, 1);
	assert(p == NULL);
	free(p);
	return 0;
}
