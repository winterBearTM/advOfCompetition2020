#include "task.h"


uint32_t findIncreases(std::vector<uint32_t> vData, bool bGroupByThree)
{
  uint32_t dwPrev = 0;
  uint32_t nIncreases = 0;
  bool bFirstEntry = true;
  for (uint32_t dwCurr : vData)
  {
    if (bFirstEntry)
    {
      bFirstEntry = false;
    }
    else
    {
      if (dwCurr > dwPrev)
      {
        nIncreases++;
      }
    }
    dwPrev = dwCurr;
  }
}

int32_t runDay1Task1(std::string strInputFilePath)
{
  uint8_t byDay = 1;
  uint8_t byTask = 1;
  
  std::vector<uint32_t> rvData;
  
  bool bResult = readListOfIntsFromFile(strInputFilePath, rvData);
  
  if (!bResult)
  {
    logErr(byDay, byTask, "Error reading from input file");
    return -1;
  }
  uint32_t dwResult = findIncreases(rvData, false);
  return dwResult;
}