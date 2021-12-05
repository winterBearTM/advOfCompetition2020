#pragma once

#include <stdint.h>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>
#include <iostream>

bool readListOfIntsFromFile(std::string strPath, std::vector<uint32_t> &rvList);
bool readListOfStrsFromFile(std::string strPath, std::vector<std::string> &rvList);

std::chrono::time_point<std::chrono::steady_clock> getTimestamp();
uint64_t getDiff_us(std::chrono::time_point<std::chrono::steady_clock> tickA,
                    std::chrono::time_point<std::chrono::steady_clock> tickB);

void logErr(uint8_t byDay, uint8_t byTask, std::string msg);
void logInf(uint8_t byDay, uint8_t byTask, std::string msg);
void logResult(uint8_t byDay, uint8_t byTask, int32_t dwResult, uint64_t qwDuration_us);
void logResult(uint8_t byDay, uint8_t byTask, int64_t qwResult, uint64_t qwDuration_us);