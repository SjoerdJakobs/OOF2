#pragma once
#include "AllocationMetrics.h"

AllocationMetrics e_AllocationMetrics;
#ifdef _DEBUG

/**
*this is some old code to keep track of memory usage just incase vld doesnt work somehow, please forgive these suppression
*/
#pragma warning(suppress: 28251)
#pragma warning(suppress: 6387)
void* operator new(size_t size)
{
	/*if(size > 24)
	{
		std::cout << "allocating " << size << " bytes\n";		
	}*/
    e_AllocationMetrics.TotalAllocated += (uint32_t)size;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
	/*if (size > 24)
	{
		std::cout << "deleting " << size << " bytes\n";
	}*/
    e_AllocationMetrics.TotalFreed += (uint32_t)size;
    return free(memory);
}
#endif