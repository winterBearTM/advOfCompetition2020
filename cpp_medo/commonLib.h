//
// Created by Tadej Medved on 11/12/2020.
//
#pragma once

#include <stdint.h>
#include <vector>
#include <fstream>
#include <string>

#define READ_BUFF_SIZE 256

/**
 * Reads file and based on newline reads integers (32-bit)
 * from file and returns them in vector return paramter.
 *
 * @param c_pcFilePath Path to file that will be parsed
 * @param vectOfValues Vectore of 32-bit ints where parsed values are returned
 */
void readListOfIntsFromFile(const char *c_pcFilePath,
                            std::vector<uint32_t> &vectOfValues);
