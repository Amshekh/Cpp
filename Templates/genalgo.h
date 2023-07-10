#ifndef GENALGO_H
#define GENALGO_H

#include <iostream>

template<typename I>
void PrintAll(I begin, I end)
{
	for(I i = begin; i != end; ++i)	
	{
		std::cout << *i << ' ';
	}

	std::cout << std::endl;
}

template<typename I, typename P>
void PrintIf(I begin, I end, P check)
{
	for(I i = begin; i != end; ++i)	
	{
		if(check(*i))
			std::cout << *i << ' ';
	}

	std::cout << std::endl;
}

#endif













