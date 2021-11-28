#pragma section REPRO

/**
 * @file c2a_round.c
 * @brief 四捨五入．C89にroundはないので
 */
#include "c2a_round.h"

int c2a_round(double input)
{
  return (int)(input + 0.5);
}

#pragma section
