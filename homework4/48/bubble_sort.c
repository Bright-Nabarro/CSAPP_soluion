#define COUNT 10 
long g_data[COUNT] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
void bubble_sort(long* data, long* end)
{
	long* ptr, *last;
	for(last = end-1; last != data; last--)
	{
		//last = %rsi ptr = %rax
		for(ptr = data; ptr != last; ptr++)
		{
			if(*(ptr+1) < *ptr)
			{
				long t = *(ptr+1);
				*(ptr+1) = *ptr;
				*ptr = t;
			}
		}
	}
}

int main(void)
{
	bubble_sort(g_data, g_data + COUNT);
}