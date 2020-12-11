//
// Created by Tadej Medved on 11/12/2020.
//

#include "task.h"

void parsePwdEntry(std::string strRaw,
                   uint32_t &dwParamA,
                   uint32_t &dwParamB,
                   char &cSearched,
                   std::string &strPwd)
{
  uint32_t dwStartIdx = 0;
  uint32_t dwChIdx, dwSize;
  for (dwChIdx=dwStartIdx; dwChIdx < strRaw.size(); dwChIdx++)
  {
    if (strRaw.at(dwChIdx) == '-')
    {
      break;
    }
  }
  std::string strMin = strRaw.substr(dwStartIdx, dwChIdx);
  dwParamA = std::stoi(strMin);

  dwStartIdx = dwChIdx + 1;
  for (dwChIdx; dwChIdx < strRaw.size(); dwChIdx++)
  {
    if (strRaw.at(dwChIdx) == ' ')
    {
      break;
    }
  }
  dwSize = dwChIdx - dwStartIdx;
  std::string strMax = strRaw.substr(dwStartIdx, dwSize);
  dwParamB = std::stoi(strMax);

  dwChIdx++;
  cSearched = strRaw.at(dwChIdx);
  dwChIdx+=3;
  strPwd = strRaw.substr(dwChIdx, std::string::npos);
}

uint32_t runDay2Task1()
{
  const char *c_pcInputFilePath = "../day2/input.txt";

  std::ifstream fileHandle(c_pcInputFilePath);

  std::string strCurrLine = "";
  uint32_t nValidPwds = 0;
  uint32_t dwMin, dwMax, nFound;
  char cSearched;
  std::string strPwd;

  while (std::getline(fileHandle, strCurrLine))
  {
    parsePwdEntry(strCurrLine, dwMin, dwMax, cSearched, strPwd);

    nFound = 0;
    for (char &cCurr : strPwd)
    {
      if (cCurr == cSearched)
      {
        nFound++;
      }
    }
    if (nFound >= dwMin && nFound <= dwMax)
    {
      nValidPwds++;
    }
  }

  fileHandle.close();

  return nValidPwds;
}


uint32_t runDay2Task2()
{
  const char *c_pcInputFilePath = "../day2/input.txt";

  std::ifstream fileHandle(c_pcInputFilePath);

  std::string strCurrLine = "";
  uint32_t nValidPwds = 0;
  uint32_t dwFirstOcc, dwSecondOcc;
  char cSearched, cAtFirstOcc, cAtSecondOcc;
  std::string strPwd;
  bool bValidPwd;

  while (std::getline(fileHandle, strCurrLine))
  {
    parsePwdEntry(strCurrLine,
                  dwFirstOcc,
                  dwSecondOcc,
                  cSearched,
                  strPwd);

    bValidPwd = false;
    if (dwFirstOcc < strPwd.size())
    {
      cAtFirstOcc = strPwd.at(dwFirstOcc);
      if (cAtFirstOcc == cSearched)
      {
        bValidPwd = true;
      }
    }
    if (dwSecondOcc < strPwd.size())
    {
      cAtSecondOcc = strPwd.at(dwSecondOcc);
      if (cAtSecondOcc == cSearched)
      {
        bValidPwd = true;
      }
    }
    if (bValidPwd)
    {
      nValidPwds++;
    }
  }

  fileHandle.close();

  return nValidPwds;
}