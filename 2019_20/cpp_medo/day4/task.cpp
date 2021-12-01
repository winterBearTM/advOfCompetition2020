//
// Created by Tadej Medved on 12/12/2020.
//

#include "task.h"

int32_t getIndexOfEl(std::vector<std::string_view> vectSv,
                      std::string strSearchedEl)
{
  int32_t dwIdx = 0;
  for (std::string_view &svEl : vectSv)
  {
    if (svEl.compare(strSearchedEl) == 0)
    {
      return dwIdx;
    }
    dwIdx++;
  }
  return -1;
}

bool isYrValid(std::string strYr, const uint32_t dwMin, const uint32_t dwMax)
{
  for (char &cNum : strYr)
  {
    if (cNum < '0' || cNum > '9')
    {
      return false;
    }
  }

  uint32_t dwYr = std::stoi(strYr);

  if (dwYr >= dwMin && dwYr <= dwMax)
  {
    return true;
  }
  return false;
}

bool isHgtValid(std::string strHgt)
{

  size_t strHgtLen = strHgt.length();

  if (strHgtLen < 4)
  {
    return false;
  }

  std::string strNum = strHgt.substr(0, (strHgtLen - 2));

  for (char &cNum : strNum)
  {
    if (cNum < '0' || cNum > '9')
    {
      return false;
    }
  }

  uint32_t dwNum = std::stoi(strNum);

  std::string strUnit = strHgt.substr((strHgtLen - 2), std::string::npos);

  const uint32_t c_dwValidHgtCmMin = 150;
  const uint32_t c_dwValidHgtCmMax = 193;
  if ((strUnit.compare("cm") == 0) &&
      (dwNum >= c_dwValidHgtCmMin) &&
      (dwNum <= c_dwValidHgtCmMax))
  {
    return true;
  }

  const uint32_t c_dwValidHgtInMin = 59;
  const uint32_t c_dwValidHgtInMax = 76;
  if ((strUnit.compare("in") == 0) &&
      (dwNum >= c_dwValidHgtInMin) &&
      (dwNum <= c_dwValidHgtInMax))
  {
    return true;
  }
  return false;
}

bool isEclValid(std::string strEcl)
{
  const char *pc_dwValidEcl[] = {"amb", "blu", "brn", "gry",
                                 "grn", "hzl", "oth"};

  uint32_t nElements = sizeof(pc_dwValidEcl)/sizeof(char *);

  for (uint32_t dwIdx = 0; dwIdx < nElements; dwIdx++)
  {
    if (std::strcmp(strEcl.c_str(), pc_dwValidEcl[dwIdx]) == 0)
    {
      return true;
    }
  }
  return false;
}

bool isHclValid(std::string strHcl)
{
  uint32_t nHexChs = 0;
  bool bFirstCh = true;
  for (char &cChr : strHcl)
  {
    if (bFirstCh)
    {
      if (cChr != '#')
      {
        return false;
      }
      bFirstCh = false;
      continue;
    }
    if (cChr >= '0' && cChr <= '9')
    {
      nHexChs++;
      continue;
    }
    if (cChr >= 'a' && cChr <= 'f')
    {
      nHexChs++;
      continue;
    }
    return false;
  }

  return (nHexChs == 6);
}

bool isPidVaild(std::string strPid)
{
  uint32_t nNums = 0;
  for (char &cNum : strPid)
  {
    if (cNum < '0' || cNum > '9')
    {
      return false;
    }
    nNums++;
  }
  return (nNums == 9);
}

bool isPassportFieldOK(std::string strField)
{
  const char c_cFieldDel = ':';

  uint32_t dwDelPos = strField.find(c_cFieldDel) + 1;
  std::string strVal = strField.substr(dwDelPos, std::string::npos);
  std::string strKey = strField.substr(0, dwDelPos - 1);
  bool bResult = false;

  if (strKey.compare("iyr") == 0)
  {
    const uint32_t c_dwValidIyrMin = 2010;
    const uint32_t c_dwValidIyrMax = 2020;

    bResult = isYrValid(strVal, c_dwValidIyrMin, c_dwValidIyrMax);
  }
  else if (strKey.compare("eyr") == 0)
  {
    const uint32_t c_dwValidEyrMin = 2020;
    const uint32_t c_dwValidEyrMax = 2030;

    bResult = isYrValid(strVal, c_dwValidEyrMin, c_dwValidEyrMax);
  }
  else if (strKey.compare("byr") == 0)
  {
    const uint32_t c_dwValidByrMin = 1920;
    const uint32_t c_dwValidByrMax = 2002;

    bResult = isYrValid(strVal, c_dwValidByrMin, c_dwValidByrMax);
  }
  else if (strKey.compare("hgt") == 0)
  {
    bResult = isHgtValid(strVal);
  }
  else if (strKey.compare("ecl") == 0)
  {
    bResult = isEclValid(strVal);
  }
  else if (strKey.compare("hcl") == 0)
  {
    bResult = isHclValid(strVal);
  }
  else if (strKey.compare("pid") == 0)
  {
    bResult = isPidVaild(strVal);
  }
  else if (strKey.compare("cid") == 0)
  {
    bResult = true;
  }
  return bResult;
}

bool isPassportOK(std::string strPassport,
                  std::vector<std::string_view> vectSvMandatory,
                  bool bExtendedCheck = false)
{
  const char cTokDel = ' ';
  const char cTokIDDel = ':';
  size_t dwTokStart = 0;
  size_t dwTokEnd, dwTokSize, dwTokIDEnd;
  std::string strTok, strTokID;

  uint32_t dwNotFoundMask = (0x1 << vectSvMandatory.size());
  dwNotFoundMask--;
  int32_t dwFoundIdx;

  while (dwTokEnd != std::string::npos)
  {
    dwTokEnd = strPassport.find(cTokDel, dwTokStart);
    dwTokSize = dwTokEnd - dwTokStart;
    strTok = strPassport.substr(dwTokStart, dwTokSize);

    dwTokIDEnd = strTok.find(cTokIDDel, 0);
    strTokID = strTok.substr(0, dwTokIDEnd);
    dwFoundIdx = getIndexOfEl(vectSvMandatory, strTokID);
    if (dwFoundIdx != -1)
    {
      dwNotFoundMask &= ~(0x1 << dwFoundIdx);
    }

    if (bExtendedCheck)
    {
      if (!isPassportFieldOK(strTok))
      {
        return false;
      }
    }

    dwTokStart = dwTokEnd + 1;
  }

  return (dwNotFoundMask == 0);
}

uint32_t getNValidPassports(bool bExtendedCheck = false)
{
  std::vector<std::string_view> vectSvMandatory;
  vectSvMandatory.push_back("byr");
  vectSvMandatory.push_back("iyr");
  vectSvMandatory.push_back("eyr");
  vectSvMandatory.push_back("hgt");
  vectSvMandatory.push_back("hcl");
  vectSvMandatory.push_back("ecl");
  vectSvMandatory.push_back("pid");

  const char *c_pcInputFilePath = "../input_data/day4.txt";

  std::ifstream fileHandle(c_pcInputFilePath);
  std::string strCurrLine;
  std::string strCurrPassport;
  uint32_t nOKPassports = 0;

  while (!fileHandle.eof())
  {
    std::getline(fileHandle, strCurrLine);
    if (fileHandle.eof())
    {
      strCurrPassport.append(strCurrLine);
    }
    if (strCurrLine.length() == 0 || fileHandle.eof())
    {
      if (isPassportOK(strCurrPassport, vectSvMandatory, bExtendedCheck))
      {
        nOKPassports++;
      }
      strCurrPassport = "";
      continue;
    }
    if (strCurrPassport.length() != 0)
    {
      strCurrPassport.append(1, ' ');
    }
    strCurrPassport.append(strCurrLine);
  }

  fileHandle.close();

  return nOKPassports;
}

uint32_t runDay4Task1()
{
  return getNValidPassports();
}
uint32_t runDay4Task2()
{
  return getNValidPassports(true);
}