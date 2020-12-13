//
// Created by Tadej Medved on 11/12/2020.
//
#pragma once

#include <stdint.h>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

/**
 * Reads file and based on newline reads integers (32-bit)
 * from file and returns them in vector return paramter.
 *
 * @param c_pcFilePath Path to file that will be parsed
 * @param vectOfValues Vector of 32-bit ints where parsed values are returned
 */
void readListOfIntsFromFile(const char *c_pcFilePath,
                            std::vector<uint32_t> &vectOfValues);

/**
 * Returns current timestamp using chrono::steady_clock as it is definitely
 * monotonic clock on all systems.
 *
 * @return Current timestamp (std::chrono::time_point type)
 */
std::chrono::time_point<std::chrono::steady_clock> getTimestamp();

/**
 * Returns time difference between timestamps A and B (A - B -> A
 * should be grater) in milliseconds. Reference points must be
 * derived from steady_clock.
 *
 * @param tickA Timestamp reference A (std::chrono::timepoint tyoe)
 * @param tickB Timestamp reference B (std::chrono::timepoint tyoe)
 * @return Time difference between references A and B in ms
 */
std::chrono::milliseconds getDiff_ms(std::chrono::time_point<std::chrono::steady_clock> tickA,
                                     std::chrono::time_point<std::chrono::steady_clock> tickB);

/**
 * Returns time difference between timestamps A and B (A - B -> A
 * should be grater) in microseconds. Reference points must be
 * derived from steady_clock.
 *
 * @param tickA Timestamp reference A (std::chrono::timepoint tyoe)
 * @param tickB Timestamp reference B (std::chrono::timepoint tyoe)
 * @return Time difference between references A and B in us
 */
std::chrono::microseconds getDiff_us(std::chrono::time_point<std::chrono::steady_clock> tickA,
                                     std::chrono::time_point<std::chrono::steady_clock> tickB);