#include <string>

void PoissonReconMain( const std::string &input, const std::string &output  );

int main(int argc, char *argv[]){

   PoissonReconMain( "5a3h.npts", "5a3h-wasm.ply");
   return 0;
}
