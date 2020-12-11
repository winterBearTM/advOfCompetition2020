//
// Created by Tadej Medved on 08/12/2020.
//

#include "task.h"

void runDay1Task1()
{
  const char *c_pcInputFilePath = "../day1/input.txt";

  std::vector<uint32_t> result;
  readListOfIntsFromFile(c_pcInputFilePath, result);

  std::sort(result.begin(), result.end() + sizeof(uint32_t));

  uint32_t dwPosFromBegin = 0;
  uint32_t dwPosFromEnd = result.size() - 1;
  uint32_t dwCurrSum, dwCurrNumA, dwCurrNumB;

  bool bFoundIt = false;

  for (uint32_t dwPosA=dwPosFromBegin; dwPosA <= dwPosFromEnd; dwPosA++)
  {
    dwCurrNumA = result.at(dwPosA);

    for (uint32_t dwPosB=dwPosFromEnd; dwPosB > dwPosA; dwPosB--)
    {
      dwCurrNumB = result.at(dwPosB);
      dwCurrSum = dwCurrNumA + dwCurrNumB;

      if (dwCurrSum < 2020)
      {
        break;
      }
      if (dwCurrSum == 2020)
      {
        bFoundIt = true;
        break;
      }
    }
    if (bFoundIt)
    {
      break;
    }
  }

  uint32_t dwAns = dwCurrNumA * dwCurrNumB;
  printf("%d\n", dwAns);

  printf("Finished");
}

void runDay1Task2()
{
  const char *c_pcInputFilePath = "../day1/input.txt";

  std::vector<uint32_t> result;
  readListOfIntsFromFile(c_pcInputFilePath, result);

  std::sort(result.begin(), result.end() + sizeof(uint32_t));



}