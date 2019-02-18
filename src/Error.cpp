
#include "PosixTest.h"

namespace PSX
{

void ErrorMessage(const char* format, ...);
void ErrorExit(const char* format, ...);
void Error_Exit(const char* format, ...);
void ErrorExitEN(int ErrorNumber, const char* format, ...);
void FatalError(const char* format, ...);
void UsageError(const char* format, ...);
void CommandLineError(const char* format, ...);

} // namespace PSX
