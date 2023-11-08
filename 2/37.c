#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>

void* copy_elements(void* ele_src[], int ele_cnt, size_t ele_size)
{
	void* result = malloc(ele_cnt * ele_size);
	if (result == NULL)
		/*malloc failed*/
		return NULL;
	char* next = (char*)result;
	for(int i=0; i<ele_cnt; i++)
	{
		memcpy(next, ele_src[i], ele_size);
		next += ele_size;
	}
	return result;
}

void* copy_elements_fixed(void* ele_src[], int ele_cnt, size_t ele_size)
{
	void* result = malloc(ele_cnt * ele_size);
	if (result == NULL)
		/*malloc failed*/
		return NULL;
	uint64_t required_size = ele_cnt * (uint64_t) ele_size;
	size_t request_size = (size_t) required_size;
	if(required_size != request_size)
		return NULL;
	char* next = (char*)result;
	for(int i=0; i<ele_cnt; i++)
	{
		memcpy(next, ele_src[i], ele_size);
		next += ele_size;
	}
	return result;
}
