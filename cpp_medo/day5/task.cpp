//
// Created by Tadej Medved on 12/12/2020.
//

#include "task.h"

#include <stdint.h>

uint8_t calcPos(std::string strPath, char cHPath)
{
  uint8_t byCurrRangeLen = (0x1 << strPath.length());
  uint8_t byPos = 0;
  for (char &cDir : strPath)
  {
    byCurrRangeLen >>= 1;
    if (cDir == cHPath)
    {
      byPos += byCurrRangeLen;
    }
  }
  return byPos;
}

uint16_t getBoardPassID(std::string strBoardPass)
{
  const uint8_t c_byDelIdx = 7;

  std::string strRowPath = strBoardPass.substr(0, c_byDelIdx);
  std::string strColPath = strBoardPass.substr(c_byDelIdx, std::string::npos);

  uint8_t byRow = calcPos(strRowPath, 'B');
  uint8_t byCol = calcPos(strColPath, 'R');
  uint16_t wId = (byRow * 8) + byCol;

  return wId;
}

uint32_t runDay5Task1()
{
  const char *c_pcInputFilePath = "../input_data/day5.txt";
  std::ifstream fileHandle(c_pcInputFilePath);
  std::string strCurrLine;

  uint16_t wCurrId;
  uint16_t wMaxId = 0;

  while (std::getline(fileHandle, strCurrLine))
  {
    wCurrId = getBoardPassID(strCurrLine);
    if (wCurrId > wMaxId)
    {
      wMaxId = wCurrId;
    }
  }

  fileHandle.close();

  return wMaxId;
}

uint32_t runDay5Task2()
{
  const char *c_pcInputFilePath = "../input_data/day5.txt";
  std::ifstream fileHandle(c_pcInputFilePath);
  std::string strCurrLine;

  std::vector<uint16_t> vectAllIds;
  uint16_t wCurrId;
  uint16_t wMyId = 0;

  uint16_t wPossibleMinId = getBoardPassID("FFFFFFBLLL");
  uint16_t wPossibleMaxId = getBoardPassID("BBBBBBFRRR");
  while (std::getline(fileHandle, strCurrLine))
  {
    wCurrId = getBoardPassID(strCurrLine);
    if (wCurrId >= wPossibleMinId && wCurrId <= wPossibleMaxId)
    {
      vectAllIds.push_back(wCurrId);
    }
  }
  fileHandle.close();

  std::sort(vectAllIds.begin(), vectAllIds.end());

  uint16_t wPrevId = 0, wDiff;
  bool bNoIdWasReadYet = true;
  for (uint16_t &wId : vectAllIds)
  {
    if (bNoIdWasReadYet)
    {
      wPrevId = wId;
      bNoIdWasReadYet = false;
      continue;
    }
    wDiff = wId - wPrevId;
    if (wDiff > 1)
    {
      return wId - 1;
    }
    wPrevId = wId;
  }
  return 0;
}