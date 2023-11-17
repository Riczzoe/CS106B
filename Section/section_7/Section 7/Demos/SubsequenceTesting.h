#pragma once

#include "vector.h"
#include <string>
#include <functional>

/* Checks whether the output has the given subsequence. */
bool outputMatchesImpl(std::function<void()> callback,
                       const Vector<std::string>& expected);

#define outputMatches(expr, ...) outputMatchesImpl([&] { expr; }, __VA_ARGS__)
