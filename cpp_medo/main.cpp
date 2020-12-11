#include "day1/task.h"
#include "day2/task.h"


int main()
{
  uint32_t dwSolution;
  dwSolution = runDay1Task1();
  printf("Solution day1_task1: %d\n", dwSolution);
  dwSolution = runDay1Task2();
  printf("Solution day1_task2: %d\n", dwSolution);
  dwSolution = runDay2Task1();
  printf("Solution day2_task1: %d\n", dwSolution);
  dwSolution = runDay2Task2();
  printf("Solution day2_task2: %d\n", dwSolution);
  return 0;
}