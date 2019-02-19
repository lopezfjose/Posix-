#ifndef POSIX_TEST_INCLUDES_POSIX_TEST_H_
#define POSIX_TEST_INCLUDES_POSIX_TEST_H_

#include <unistd.h>

#include <sys/fsuid.h>
#include <sys/inotify.h>
#include <sys/ioctl.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/statvfs.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/utsname.h>
#include <sys/xattr.h>

#include <dirent.h>
#include <fcntl.h>
#include <ftw.h>
#include <grp.h>
#include <libgen.h>
#include <pwd.h>
#include <signal.h>
#include <utime.h>

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstdarg>
#include <cstring>
#include <cerrno>
#include <climits>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include <gnu/libc-version.h>

#include <boost/program_options.hpp>

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

template <typename T>
void Swap(T& a, T& b)
{
    T t(std::move(a));
    a = std::move(b);
    b = std::move(t);
}

} // namespace PSX

#endif // POSIX_TEST_INCLUDES_POSIX_TEST_H_
