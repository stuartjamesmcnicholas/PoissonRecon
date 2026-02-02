WASM
----

```
em++ -fwasm-exceptions -O2 -sASSERTIONS=2 -pthread -sPTHREAD_POOL_SIZE=8 -sPTHREAD_POOL_SIZE_STRICT=8 -sINITIAL_MEMORY=4096MB -sMEMORY64=1 -std=c++23 ./Src/Reconstruction.example.cpp
```

```
node a.out.js --verbose --samples 1000 --out wasm.ply
```

which doesn't sadly produce a mesh yet

Native
------

```
c++ -pthread -std=c++23 ./Src/Reconstruction.example.cpp
```

```
./a.out --verbose --samples 1000 --out native.ply
```

which does produce a mesh.
