#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*@author   Bartosz Widera
* @brief    Checks the correctness of the loaded line
* @param1   line: Loaded line from console
* @ret      void
*/
void checkValid(char[]);



/*@author   Bartosz Widera
* @brief    Calculates the sum based on the loaded line
* @param1   Line: Loaded line from console
* @param2   result: Number of line
* @ret      void
*/
void calculate(char [],int);



/*@author   Bartosz Widera
* @brief    Gets loaded lines
* @param1   result: Number of line
* @ret      void
*/
void explore(int);



/*@author   Bartosz Widera
* @brief    Displays the results
* @param1   line: Number of lines
* @ret      void
*/
void showResults(int);

#endif // MAIN_H
