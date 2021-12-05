#include "task.h"

int32_t runDay2Task1(std::string strInputFilePath)
{
  std::vector<std::string> vData;
  if (!readListOfStrsFromFile(strInputFilePath, vData))
  {
    return -1;
  }
  
  uint32_t dwHPos = 0;
  uint32_t dwDepth = 0;
  
  char cCurrAct;
  uint32_t dwCurrMove;
  
  for (uint32_t dwActIdx = 0; dwActIdx < vData.size(); dwActIdx += 2)
  {
    cCurrAct = vData.at(dwActIdx).at(0);
    dwCurrMove = stoi(vData.at(dwActIdx + 1));
  
    switch (cCurrAct)
    {
      case 'u':
        dwDepth -= dwCurrMove;
        break;
      case 'd':
        dwDepth += dwCurrMove;
        break;
      case 'f':
        dwHPos += dwCurrMove;
        break;
      default:
        return -1;
    }
  }
  
  return dwHPos * dwDepth;
}

int32_t runDay2Task2(std::string strInputFilePath)
{
  std::vector<std::string> vData;
  if (!readListOfStrsFromFile(strInputFilePath, vData))
  {
    return -1;
  }
  
  uint32_t dwHPos = 0;
  uint32_t dwDepth = 0;
  int32_t dwAim = 0;
  
  char cCurrAct;
  uint32_t dwCurrMove;
  
  for (uint32_t dwActIdx = 0; dwActIdx < vData.size(); dwActIdx += 2)
  {
    cCurrAct = vData.at(dwActIdx).at(0);
    dwCurrMove = stoi(vData.at(dwActIdx + 1));
    
    switch (cCurrAct)
    {
      case 'u':
        dwAim -= dwCurrMove;
        break;
      case 'd':
        dwAim += dwCurrMove;
        break;
      case 'f':
        dwHPos += dwCurrMove;
        dwDepth += (dwAim * dwCurrMove);
        break;
      default:
        return -1;
    }
  }
  
  return dwHPos * dwDepth;
}