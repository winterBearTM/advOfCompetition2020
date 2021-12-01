#include "commonLib.h"

bool readListOfIntsFromFile(std::string strPath, std::vector<uint32_t> &rvList)
{
  std::fstream fileHandler;
  try
  {
    fileHandler.open(strPath, std::ios_base::in);
    std::string strEntry;
    uint32_t dwEntry;
    while (!fileHandler.eof())
    {
      fileHandler >> strEntry;
      dwEntry = std::stoi(strEntry, nullptr);
      rvList.push_back(dwEntry);
    }
    fileHandler.close();
  }
  catch (std::exception &rex)
  {
    if (fileHandler.is_open())
    {
      fileHandler.close();
    }
    return false;
  }
  return true;
}

void logErr(uint8_t byDay, uint8_t byTask, std::string msg)
{
  printf("E [DAY%02d_TASK%d]: %s", byDay, byTask, msg.c_str());
}


void logInf(uint8_t byDay, uint8_t byTask, std::string msg)
{
  printf("I [DAY%02d_TASK%d]: %s", byDay, byTask, msg.c_str());
}