#include "day1/task.h"
#include "day2/task.h"
#include "day3/task.h"
#include "day4/task.h"
#include "day5/task.h"

#include <chrono>
#include <iostream>

void executeTask_rv32(uint32_t (*taskFun)(), const char *c_pcTaskName)
{
  auto startTick = getTimestamp();
  uint32_t dwSolution = taskFun();
  auto endTick = getTimestamp();
  auto elapsed_us = getDiff_us(endTick, startTick);
  std::cout << c_pcTaskName << ": " << dwSolution
            << " (" << elapsed_us.count() << " us)\n";
}

void executeTask_rv64(uint64_t (*taskFun)(), const char *c_pcTaskName)
{
  auto startTick = getTimestamp();
  uint64_t qwSolution = taskFun();
  auto endTick = getTimestamp();
  auto elapsed_us = getDiff_us(endTick, startTick);
  std::cout << c_pcTaskName << ": " << qwSolution
            << " (" << elapsed_us.count() << " us)\n";
}

int main()
{
  uint32_t dwSolution;

  auto startTickFull = getTimestamp();

  executeTask_rv32(runDay1Task1, "day1_task1");
  executeTask_rv32(runDay1Task2, "day1_task2");
  executeTask_rv32(runDay2Task1, "day2_task1");
  executeTask_rv32(runDay2Task2, "day2_task2");
  executeTask_rv32(runDay3Task1, "day3_task1");
  executeTask_rv64(runDay3Task2, "day3_task2");
  executeTask_rv32(runDay4Task1, "day4_task1");
  executeTask_rv32(runDay4Task2, "day4_task2");
  executeTask_rv32(runDay5Task1, "day5_task1");
  executeTask_rv32(runDay5Task2, "day5_task2");

  auto endTickFull = getTimestamp();
  auto elapsedFull_ms = getDiff_ms(endTickFull, startTickFull);
  std::cout << "All tasks finished in " << elapsedFull_ms.count() << " ms\n";

  return 0;
}