#include <iostream>
#include "ChimiMathsVector3.hpp"

// https://www.haroldserrano.com/blog/developing-a-math-engine-in-c-implementing-vectors
int main()
{
  ChimiEngine::ChimiVector3 v(2, 2, 2);

  ChimiEngine::ChimiVector3 normalied = v.normalize();
  return 0;
}