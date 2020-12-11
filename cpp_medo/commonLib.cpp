//
// Created by Tadej Medved on 11/12/2020.
//

#include "commonLib.h"

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
