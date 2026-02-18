WASM
----

I haven't tested making an executable yet...

```
emcmake cmake . -DCMAKE_CXX_FLAGS=-I$PWD -fwasm-exceptions -pthread -std=c++23 -sMEMORY64=1 --use-port=libjpeg -I<my wasm boost location>/include/
make
```

NATIVE
------

But this should work (on a Mac with Homebrew `libpng` and `libjpeg`) in you have an input mesh `test.npts`:

```
cmake . -DCMAKE_CXX_FLAGS="-std=c++23 -I$PWD/ -I/opt/homebrew/include/" -DCMAKE_EXE_LINKER_FLAGS="-L/opt/homebrew/lib -lpng -ljpeg"
make poisson_recon_test
./poisson_recon_test test.npts test.ply
```
