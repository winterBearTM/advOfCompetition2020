//
// Created by Tadej Medved on 08/12/2020.
//

#include "task.h"

uint32_t runDay1Task1()
{
  const char *c_pcInputFilePath = "../day1/input.txt";

  std::vector<uint32_t> vectData;
  readListOfIntsFromFile(c_pcInputFilePath, vectData);

  std::sort(vectData.begin(), vectData.end() + sizeof(uint32_t));

  uint32_t dwPosFromEnd = vectData.size() - 1;
  uint32_t dwCurrSum, dwCurrNumA, dwCurrNumB;

  bool bFoundIt = false;

  for (uint32_t dwPosA=0; dwPosA <= dwPosFromEnd; dwPosA++)
  {
    dwCurrNumA = vectData.at(dwPosA);

    for (uint32_t dwPosB = dwPosFromEnd; dwPosB > dwPosA; dwPosB--)
    {
      dwCurrNumB = vectData.at(dwPosB);
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
  return dwAns;
}

uint32_t runDay1Task2()
{
  const char *c_pcInputFilePath = "../day1/input.txt";

  std::vector<uint32_t> vectData;
  readListOfIntsFromFile(c_pcInputFilePath, vectData);

  std::sort(vectData.begin(), vectData.end() + sizeof(uint32_t));

  uint32_t dwDataSize = vectData.size();
  uint32_t dwNumA, dwNumB, dwNumC, dwRes;
  bool bFoundIt = false;

  for (uint32_t dwPosA=0; dwPosA < dwDataSize; dwPosA++)
  {
    dwNumA = vectData.at(dwPosA);
    for (uint32_t dwPosB=(dwPosA + 1); dwPosB < dwDataSize; dwPosB++)
    {
      dwNumB = vectData.at(dwPosB);
      for (uint32_t dwPosC=(dwPosB + 1); dwPosC < dwDataSize; dwPosC++)
      {
        dwNumC = vectData.at(dwPosC);
        dwRes = dwNumA + dwNumB + dwNumC;

        if (dwRes == 2020)
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
    if (bFoundIt)
    {
      break;
    }
  }

  uint32_t dwAns = dwNumA * dwNumB * dwNumC;
  return dwAns;
}