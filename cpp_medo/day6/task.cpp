//
// Created by Tadej Medved on 13/12/2020.
//

#include "task.h"

uint8_t getNAnsweredYes(std::string strAnswers, bool bOnlyUnanimusYes)
{
  uint32_t dwCurrAnsMask = (1 << 27) - 1;
  uint32_t dwFinalAnsMask = 0;
  uint8_t byNAnsYes = 0;
  uint32_t dwIdxMask;
  for (char &cAns : strAnswers)
  {
    if (cAns == ' ')
    {
      if (bOnlyUnanimusYes)
      {
        dwFinalAnsMask |= dwCurrAnsMask;
        dwCurrAnsMask = (1 << 27) - 1;
      }
      continue;
    }
    dwIdxMask = (1 << (cAns - 'a'));
    if (dwCurrAnsMask & dwIdxMask)
    {
      if (!bOnlyUnanimusYes)
      {
        byNAnsYes++;
      }
      dwCurrAnsMask &= ~dwIdxMask;
    }
  }

  if (bOnlyUnanimusYes)
  {
    for (uint8_t byIdx; byIdx < 27; byIdx++)
    {
      if (!(dwFinalAnsMask & (1 << byIdx)))
      {
        byNAnsYes++;
      }
    }
  }

  return byNAnsYes;
}

uint32_t findNYes(bool bOnlyUnanimusYes)
{
  const char *c_pcInputFilePath = "../input_data/day6.txt";
  std::ifstream fileHandle(c_pcInputFilePath);
  std::string strCurrLine;

  std::string strCurrGrpAns = "";
  uint8_t byCurrGrpYAns;
  uint32_t dwAllYAns = 0;
  while (!fileHandle.eof())
  {
    std::getline(fileHandle, strCurrLine);
    if (strCurrLine.length() == 0)
    {
      byCurrGrpYAns = getNAnsweredYes(strCurrGrpAns, bOnlyUnanimusYes);
      dwAllYAns += byCurrGrpYAns;
      strCurrGrpAns = "";
    }
    else
    {
      strCurrGrpAns.append(strCurrLine);
      strCurrGrpAns.append(1, ' ');
    }
  }
  if (strCurrGrpAns.length() > 0)
  {
    byCurrGrpYAns = getNAnsweredYes(strCurrGrpAns, bOnlyUnanimusYes);
    dwAllYAns += byCurrGrpYAns;
  }

  fileHandle.close();

  return dwAllYAns;
}

uint32_t runDay6Task1()
{
  return findNYes(false);
}

uint32_t runDay6Task2()
{
  return findNYes(true);
}