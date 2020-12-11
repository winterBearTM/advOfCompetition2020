//
// Created by Tadej Medved on 11/12/2020.
//

#include "task.h"

uint32_t walkSlopes(uint32_t dwStepX, uint32_t dwStepY)
{
  const char *c_pcInputFilePath = "../day3/input.txt";
  std::ifstream fileHandle(c_pcInputFilePath);

  std::string strCurrLine;
  uint32_t nMetTrees = 0;
  uint32_t dwMaxRelXPos;
  char cCurrMapPos;

  uint32_t dwCurrYPos = 0;
  uint32_t dwCurrXPos = 0;

  bool bIgnoreFirstLine = true;

  while (std::getline(fileHandle, strCurrLine))
  {
    if (bIgnoreFirstLine)
    {
      dwCurrYPos++;
      bIgnoreFirstLine = false;
      continue;
    }

    if ((dwCurrYPos % dwStepY) != 0)
    {
      dwCurrYPos++;
      continue;
    }
    dwCurrYPos++;

    dwCurrXPos += dwStepX;
    dwMaxRelXPos = strCurrLine.length();
    if (dwCurrXPos > (dwMaxRelXPos - 1))
    {
      dwCurrXPos = dwCurrXPos % dwMaxRelXPos;
    }

    cCurrMapPos = strCurrLine.at(dwCurrXPos);

    if (cCurrMapPos == '#')
    {
      nMetTrees++;
    }
  }
  fileHandle.close();

  return nMetTrees;
}

uint32_t runDay3Task1()
{
  return walkSlopes(3, 1);
}

uint64_t runDay3Task2()
{
  uint64_t dwResult;

  dwResult = walkSlopes(1, 1);
  dwResult *= walkSlopes(3, 1);
  dwResult *= walkSlopes(5, 1);
  dwResult *= walkSlopes(7, 1);
  dwResult *= walkSlopes(1, 2);

  return dwResult;
}