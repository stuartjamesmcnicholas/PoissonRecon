#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

std::string PoissonReconMain( int argc , char* argv[], const std::stringstream &input  );

int main(int argc, char *argv[]){

   std::string input = "";

   std::ifstream t("5a3h.npts");
   std::stringstream buffer;
   buffer << t.rdbuf();
   
   std::cout << argc << std::endl;

   const char *args[] = {"PoissonReconMoorhen","--in","5a3h.npts","--out","5a3h-wasm.ply","--depth","8","--verbose","--parallel","1","--degree","1"};
   const int n_args = 12;

   PoissonReconMain( n_args , (char**)args, buffer );
   return 0;
}
