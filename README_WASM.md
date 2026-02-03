WASM
----

```
make reconexample
```

```
Bin/Wasm/ReconExample --verbose --samples 1000 --out wasm.ply
```

which produces a mesh!

NATIVE
------

The original native code with multi-threading can be tested with, e.g.:

```
c++ -O3 -pthread -std=c++23 ./Src/Reconstruction.example.cpp
/a.out --verbose --samples 1000 --out native.ply --multithread
