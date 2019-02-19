
#include "PosixTest.h"

namespace Opt = boost::program_options;

using namespace PSX;

int main(int argc, char* argv[])
{
    Opt::options_description OptsDescription("Options");
    OptsDescription.add_options()
        ("help", "Print help message");
    
    Opt::variables_map VarMap;
    Opt::store(Opt::parse_command_line(argc, argv, OptsDescription), VarMap);
    Opt::notify(VarMap);

    if (VarMap.count("help"))
    {
        std::cout << OptsDescription << "\n";

        return EXIT_SUCCESS;
    }

    return EXIT_SUCCESS;
}
