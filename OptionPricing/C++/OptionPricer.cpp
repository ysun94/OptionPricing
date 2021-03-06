// OptionPricer.cpp : Defines the entry point for the console application.
// S(n, i) = S_0 * (1+U)^i * (1+D)^(n-i) at step n and node i in the binomial tree *stock price*
// S_0 > 0 and U > D > -1 and n >= i >= 0
// if R is a risk-free rate, the model admots no arbitrage whenever D<R<U
// The price H(n, i) at each time step n and node i of an *European option*


#include "stdafx.h"
#include "BinomialModel.h"
#include "Option.h"
#include <iostream>

int main()
{
	BinomialModel model(100.0, 0.2, -0.1,0.1);
	Call call;
	call.setK(110);
	call.setN(10);
	Put put;
	put.setK(100);
	put.setN(10);

	std::cout << call.PriceByCRR(model) << std::endl;
	std::cout << call.PriceBySnell(model) << std::endl;
	
	std::cout << put.PriceByCRR(model) << std::endl;
	std::cout << put.PriceBySnell(model) << std::endl;
	
	
	
	/*
	 * The outputs are
	 * 57.8269
	 * 57.8269
	 * 0.16084
	 * 3.30542
	 */
    return 0;
}

