#include "task.h"

#include <iostream>

uint32_t findIncreases(std::vector<uint32_t> vData, uint32_t dwGrpSize)
{
  uint32_t nIncreases = 0;
  uint32_t dwCurrNum;
  uint32_t dwBufSize = dwGrpSize + 1;
  
  uint32_t adwSumBuf[dwBufSize];
  bool abActive[dwBufSize];
  for (uint8_t byIdx = 0; byIdx < dwBufSize; byIdx++)
  {
    abActive[byIdx] = false;
    adwSumBuf[byIdx] = 0;
  }
  
  int8_t byHaltedIdx = dwGrpSize;
  int8_t byPrevHaltedIdx;
  
  for (uint32_t dwIdx = 0; dwIdx <= vData.size(); dwIdx++)
  {
    if (dwIdx >= dwGrpSize)
    {
      byPrevHaltedIdx = byHaltedIdx;
      byHaltedIdx = ++byHaltedIdx % (dwBufSize);
      abActive[byPrevHaltedIdx] = true;
      abActive[byHaltedIdx] = false;
      if (dwIdx > dwGrpSize)
      {
        if (adwSumBuf[byHaltedIdx] > adwSumBuf[byPrevHaltedIdx])
        {
          nIncreases += 1;
        }
        adwSumBuf[byPrevHaltedIdx] = 0;
      }
    }
    else
    {
      abActive[dwIdx] = true;
    }
    
    if (dwIdx == vData.size())
    {
      break;
    }
    dwCurrNum = vData.at(dwIdx);
    for (uint8_t byActiveIdx = 0; byActiveIdx < dwBufSize; byActiveIdx++)
    {
      if (abActive[byActiveIdx])
      {
        adwSumBuf[byActiveIdx] += dwCurrNum;
      }
    }
  }
  
  return nIncreases;
}

int32_t runDay1Task1(std::string strInputFilePath)
{
  std::vector<uint32_t> rvData;
  
  bool bResult = readListOfIntsFromFile(strInputFilePath, rvData);
  
  if (!bResult)
  {
    return -1;
  }
  return findIncreases(rvData, 1);
}

int32_t runDay1Task2(std::string strInputFilePath)
{
  std::vector<uint32_t> rvData;
  
  bool bResult = readListOfIntsFromFile(strInputFilePath, rvData);
  
  if (!bResult)
  {
    return -1;
  }
  return findIncreases(rvData, 3);
}