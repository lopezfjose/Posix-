
#include "PosixTest.h"

using namespace PSX;

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif


int main(int argc, char* argv[])
{
    if (argc != 3 || !strcmp(argv[1],"-h") || !strcmp(argv[1], "--help"))
    {
        std::cerr << argv[0] << " <Old File> <New File>\n";
    }

    const int DEFAULT = 0;

    int inputFile = DEFAULT;
    int outputFile = DEFAULT;
    int openFlags = DEFAULT;

    mode_t filePermissions;
    ssize_t numRead;
    char buffer[BUF_SIZE];

    inputFile = open(argv[1], O_RDONLY);

    if (inputFile == -1)
    {
        // TODO: Handle error.
        std::cerr << "Failed to open input file.\n";

        std::exit(EXIT_FAILURE);
    }

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePermissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

    outputFile = open(argv[2], openFlags, filePermissions);

    if (outputFile == -1)
    {
        // TODO: Handle error.
        std::cerr << "Failed to open output file.\n";

        std::exit(EXIT_FAILURE);
    }

    while ((numRead = read(inputFile, buffer, BUF_SIZE)) > 0)
    {
        if (write(outputFile, buffer, numRead) != numRead)
        {
            // TODO: This is a fatal error; handle it.
            std::cerr << "Error while transmitting; exiting.\n";

            std::exit(EXIT_FAILURE);
        }
    }

    if (close(inputFile) == -1)
    {
        // TODO: Handle closing file error.
        std::cerr << "Error closing input file.\n";

        std::exit(EXIT_FAILURE);
    }

    if (close(outputFile) == -1)
    {
        // TODO: Handle closing output file error.
        std::cerr << "Error closing output file.\n";

        std::exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
