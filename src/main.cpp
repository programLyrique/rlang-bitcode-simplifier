#include <iostream>

#include <llvm/IR/Function.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <llvm/Support/raw_ostream.h>
#include <llvm/Support/SourceMgr.h>

#include <llvm/IR/DebugInfo.h>
#include <llvm/IRReader/IRReader.h>

using namespace llvm;

int main(int argc, char *argv[])
{
    LLVMContext context;

    std::cout << "R bitcode simplifier" << std::endl;

    SMDiagnostic error;
    std::string baseFname = argv[1];
    Module *base = parseIRFile(baseFname, error, context).release();
    if (!base)
    {
        errs() << "ERROR: Cannot read IR file " << baseFname << "\n";
        error.print(argv[0], errs());
        exit(1);
    }

    delete base;

    return 0;
}