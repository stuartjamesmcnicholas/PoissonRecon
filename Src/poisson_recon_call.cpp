#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

std::string PoissonReconMain( const std::string &input, bool doParallel );

int main(int argc, char *argv[]){

    std::ifstream file(argv[1]);

    std::stringstream buffer;
    buffer << file.rdbuf();

    std::string str = buffer.str();
    std::cout << str.size() << std::endl;

    std::string output = PoissonReconMain(str, true);
    std::ofstream ofile(argv[2]);
    ofile << output;

    return 0;
}
