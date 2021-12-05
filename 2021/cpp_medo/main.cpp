#include <stdint.h>

#include "lib/commonLib.h"

#include "day1/task.h"
#include "day2/task.h"

void runTaskFunc_rv32(uint8_t byDay,
                      uint8_t byTask,
                      int32_t (*taskFunc)(std::string),
                      std::string strInputFilePath)
{
  auto tsStart = getTimestamp();
  int32_t dwResult = taskFunc(strInputFilePath);
  auto tsEnd = getTimestamp();
  if (dwResult == -1)
  {
    logErr(byDay, byTask, "Task function returned error state!");
    return;
  }
  uint64_t qwElapsed_us = getDiff_us(tsEnd, tsStart);
  logResult(byDay, byTask, dwResult, qwElapsed_us);
}

int main()
{
  runTaskFunc_rv32(1, 1, runDay1Task1, "../data/input_day1.txt");
  runTaskFunc_rv32(1, 2, runDay1Task2, "../data/input_day1.txt");
  runTaskFunc_rv32(2, 1, runDay2Task1, "../data/input_day2.txt");
  runTaskFunc_rv32(2, 2, runDay2Task2, "../data/input_day2.txt");
  return 0;
}