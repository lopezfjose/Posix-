#ifndef POSIX_TEST_INCLUDES_POSIX_TEST_H_
#define POSIX_TEST_INCLUDES_POSIX_TEST_H_

#include <sys/types.h>
#include <sys/stat.h>

#include <fcntl.h>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <cstring>
#include <cerrno>
#include <climits>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include <unistd.h>

#include <gnu/libc-version.h>

#include "Args.h"
#include "Bool.h"
#include "Error.h"

namespace PSX
{

template <typename T1, typename T2>
auto Max(T1 a, T2 b) -> decltype(true ? a : b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
auto Min(T1 a, T2 b) -> decltype(true ? a : b)
{
    return (a < b) ? a : b;
}

} // namespace PSX

#endif // POSIX_TEST_INCLUDES_POSIX_TEST_H_
