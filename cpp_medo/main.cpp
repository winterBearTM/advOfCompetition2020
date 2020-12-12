#include "day1/task.h"
#include "day2/task.h"
#include "day3/task.h"
#include "day4/task.h"


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
  dwSolution = runDay3Task1();
  printf("Solution day3_task1: %d\n", dwSolution);
  dwSolution = runDay3Task2();
  printf("Solution day3_task2: %d\n", dwSolution);
  dwSolution = runDay4Task1();
  printf("Solution day4_task1: %d\n", dwSolution);
  dwSolution = runDay4Task2();
  printf("Solution day4_task2: %d\n", dwSolution);
  return 0;
}