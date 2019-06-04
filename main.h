#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


/*@author   Bartosz Widera
* @brief    Checking a correct number of number and operations
* @param1    Line: Load line from console
* @ret      void
*/
void checkValid(char);


/*@author   Bartosz Widera
* @brief    Calculates the sum based on the sorted order of actions
* @param1   operation: Array with sort operations
* @param2   position: Array with sort positions of operations
* @param3   line: Load line from console
* @param4   result: Number of line
* @ret      void
*/
void calculate(char *,int *,char,int);


/*@author   Bartosz Widera
* @brief    Sorting tables ( Priority mathematical operations)
* @param1   operation: Allocated array ready for sorting( operations)
* @param2   position: Allocated array ready for sorting ( positions of operations)
* @ret      void
*/
void orderOperation(char *,int *);



/*@author   Bartosz Widera
* @brief    gets loaded lines and reads individual operations
* @param1   operation: Unallocated array with sort operations
* @param2   position_of_oper: Unallocated array with sort positions of operations
* @param3   result: Number of line
* @ret      void
*/
void explore(int *, char *,int);



/*@author   Bartosz Widera
* @brief    Displays the result
* @param1   line: Number of line
* @ret      void
*/
void showResults(int);

