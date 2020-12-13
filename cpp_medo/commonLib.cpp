//
// Created by Tadej Medved on 11/12/2020.
//

#include "commonLib.h"

std::chrono::time_point<std::chrono::steady_clock> getTimestamp()
{
  std::chrono::time_point<std::chrono::steady_clock> tickNow;
  tickNow = std::chrono::steady_clock::now();
  return tickNow;
}

std::chrono::microseconds getDiff_us(std::chrono::time_point<std::chrono::steady_clock> tickA,
                                     std::chrono::time_point<std::chrono::steady_clock> tickB)
{
  std::chrono::microseconds elapsed_us;
  elapsed_us = std::chrono::duration_cast<std::chrono::microseconds>(tickA - tickB);
  return elapsed_us;
}

std::chrono::milliseconds getDiff_ms(std::chrono::time_point<std::chrono::steady_clock> tickA,
                                     std::chrono::time_point<std::chrono::steady_clock> tickB)
{
  std::chrono::milliseconds elapsed_ms;
  elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(tickA - tickB);
  return elapsed_ms;
}

void readListOfIntsFromFile(const char *c_pcFilePath,
                            std::vector<uint32_t> &vectOfValues)
{
  std::ifstream fileHandle(c_pcFilePath);

  std::string strCurrNumber = "";
  uint32_t dwCurrNumber;

  while (std::getline(fileHandle, strCurrNumber))
  {
    dwCurrNumber = std::stoi(strCurrNumber);
    vectOfValues.push_back(dwCurrNumber);
  }

  fileHandle.close();
}
