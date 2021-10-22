# Rlang bitcode simplifier

Given a bitcode file from the C part of an R package, function names with type specifications, the simplifier optimizes the bitcode to specialize the function to the type specification.


## How to generate the bitcode for an R package

Follow the instructions in the [rchk project](https://github.com/kalibera/rchk).