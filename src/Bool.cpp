
#include "PosixTest.h"

namespace PSX
{
std::ostream& operator<<(std::ostream& outputStream, const Boolean& value)
{
    return outputStream << (value == Boolean::True ? "True" : "False");
}

} // namespace PSX