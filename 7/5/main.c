#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
	void* handle;
	void(* fp_output)();

	handle = dlopen("./output.so", RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	fp_output = dlsym(handle, "output");
	if(!fp_output)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);
	}

	fp_output();

	dlclose(handle);
}