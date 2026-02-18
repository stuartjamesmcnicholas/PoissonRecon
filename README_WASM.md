WASM
----

This should work with emscripten if you have an input mesh `test.npts`:

```
emcmake cmake . -DCMAKE_CXX_FLAGS="-I$PWD -fwasm-exceptions -pthread -std=c++23 -sMEMORY64=1 --use-port=libjpeg" -DCMAKE_EXE_LINKER_FLAGS="-sALLOW_MEMORY_GROWTH -sNODERAWFS"
make poisson_recon_test
node poisson_recon_test.js test.npts test.ply
```

NATIVE
------

This should work on a Mac with Homebrew `libpng` and `libjpeg` if you have an input mesh `test.npts`:

```
cmake . -DCMAKE_CXX_FLAGS="-std=c++23 -I$PWD/ -I/opt/homebrew/include/" -DCMAKE_EXE_LINKER_FLAGS="-L/opt/homebrew/lib -lpng -ljpeg"
make poisson_recon_test
./poisson_recon_test test.npts test.ply
```
