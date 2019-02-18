#ifndef POSIX_TEST_INCLUDES_BOOL_H_
#define POSIX_TEST_INCLUDES_BOOL_H_

namespace PSX
{
enum class Boolean {
    False,
    True
};

std::ostream& operator<<(std::ostream& outputStream, const Boolean& value);

} // namespace PSX

#endif // POSIX_TEST_INCLUDES_BOOL_H_