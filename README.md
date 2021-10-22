# Rlang bitcode simplifier

Given a bitcode file from the C part of an R package, function names with type specifications, the simplifier optimizes the bitcode to specialize the function to the type specification.


## How to generate the bitcode for an R package

Follow the instructions in the [rchk project](https://github.com/kalibera/rchk).

## Dependencies

LLVM (tested with LLVM 11)

## Build

```bash
mkdir build;cd build
cmake -GNinja  ../src/CMakeLists.txt 
ninja
```

(drop `-CNinja` if you prefer to use a Makefile)