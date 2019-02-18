#ifndef POSIX_TEST_INCLUDES_ERROR_H_
#define POSIX_TEST_INCLUDES_ERROR_H_

namespace PSX
{
    void ErrorMessage(const char* format, ...);

    /** @macro NORETURN
     *  
     *  The NORETURN macro stops 'gcc -Wall' from complaiing that "control
     *  reaches end of non-void function" if we use the following functions
     *  to terminate main() or some other non-void function.
     *
     */
    #ifdef __GNUC__
    #define NORETURN __attribute__ ((__noreturn__))
    #else
    #define NORETURN
    #endif

    void ErrorExit(const char* format, ...) NORETURN;

    void Error_Exit(const char* format, ...) NORETURN;

    void ErrorExitEN(int ErrorNumber, const char* format, ...) NORETURN;

    void FatalError(const char* format, ...) NORETURN;

    void UsageError(const char* format, ...) NORETURN;

    void CommandLineError(const char* format, ...) NORETURN;

} // namespace PSX

#endif // POSIX_TEST_INCLUDES_ERROR_H_