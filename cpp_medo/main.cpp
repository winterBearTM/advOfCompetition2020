#include "day1/task.h"
#include "day2/task.h"
#include "day3/task.h"
#include "day4/task.h"
#include "day5/task.h"

#include <chrono>

int main()
{
  uint32_t dwSolution;

  auto startTick = std::chrono::steady_clock::now();
  dwSolution = runDay1Task1();
  auto endTick = std::chrono::steady_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day1_task1: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay1Task2();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day1_task2: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay2Task1();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day2_task1: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay2Task2();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day2_task2: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay3Task1();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day3_task1: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay3Task2();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day3_task2: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay4Task1();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day4_task1: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay4Task2();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day4_task2: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay5Task1();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day5_task1: %d (%ld us)\n", dwSolution, elapsed);

  startTick = std::chrono::steady_clock::now();
  dwSolution = runDay5Task2();
  endTick = std::chrono::steady_clock::now();
  elapsed = std::chrono::duration_cast<std::chrono::microseconds>(endTick - startTick);
  printf("Solution day5_task2: %d (%ld us)\n", dwSolution, elapsed);

  return 0;
}