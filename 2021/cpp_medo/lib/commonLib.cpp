#include "commonLib.h"

bool readListOfIntsFromFile(std::string strPath, std::vector<uint32_t> &rvList)
{
  std::fstream fileHandler;
  try
  {
    fileHandler.open(strPath, std::ios_base::in);
    std::string strEntry;
    uint32_t dwEntry;
    while (!fileHandler.eof())
    {
      fileHandler >> strEntry;
      dwEntry = std::stoi(strEntry, nullptr);
      rvList.push_back(dwEntry);
    }
    fileHandler.close();
  }
  catch (std::exception &rex)
  {
    if (fileHandler.is_open())
    {
      fileHandler.close();
    }
    return false;
  }
  return true;
}

bool readListOfStrsFromFile(std::string strPath, std::vector<std::string> &rvList)
{
  std::fstream fileHandler;
  try
  {
    fileHandler.open(strPath, std::ios_base::in);
    std::string strEntry;
    while (!fileHandler.eof())
    {
      fileHandler >> strEntry;
      rvList.push_back(strEntry);
    }
    fileHandler.close();
  }
  catch (std::exception &rex)
  {
    if (fileHandler.is_open())
    {
      fileHandler.close();
    }
    return false;
  }
  return true;
}

std::chrono::time_point<std::chrono::steady_clock> getTimestamp()
{
  std::chrono::time_point<std::chrono::steady_clock> tickNow;
  tickNow = std::chrono::steady_clock::now();
  return tickNow;
}

uint64_t getDiff_us(std::chrono::time_point<std::chrono::steady_clock> tickA,
                    std::chrono::time_point<std::chrono::steady_clock> tickB)
{
  std::chrono::microseconds elapsed_us;
  elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(tickA - tickB);
  
  uint64_t qwElapsed_us = elapsed_us.count();
  return qwElapsed_us;
}

void logErr(uint8_t byDay, uint8_t byTask, std::string strMsg)
{
  printf("E [DAY%02d_TASK%d]: %s\n", byDay, byTask, strMsg.c_str());
}


void logInf(uint8_t byDay, uint8_t byTask, std::string strMsg)
{
  printf("I [DAY%02d_TASK%d]: %s\n", byDay, byTask, strMsg.c_str());
}

void logResult(uint8_t byDay, uint8_t byTask, int32_t dwResult, uint64_t qwDuration_us)
{
  printf("I [DAY%02d_TASK%d]: Result: %d (elapsed: %llu us)\n", byDay, byTask, dwResult, qwDuration_us);
}

void logResult(uint8_t byDay, uint8_t byTask, int64_t qwResult, uint64_t qwDuration_us)
{
  printf("I [DAY%02d_TASK%d]: Result: %lld (elapsed: %llu us)\n", byDay, byTask, qwResult, qwDuration_us);
}