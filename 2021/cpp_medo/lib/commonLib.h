#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <fstream>

bool readListOfIntsFromFile(std::string strPath, std::vector<uint32_t> &rvList);

void logErr(uint8_t byDay, uint8_t byTask, std::string msg);
void logInf(uint8_t byDay, uint8_t byTask, std::string msg);