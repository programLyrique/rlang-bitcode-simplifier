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
    std::string moduleName = argv[1];
    Module *m = parseIRFile(moduleName, error, context).release();
    if (!m)
    {
        errs() << "ERROR: Cannot read IR file " << moduleName << "\n";
        error.print(argv[0], errs());
        exit(1);
    }

    m->print(llvm::errs(), nullptr); //dump is not included with LLVM in Release mode

    delete m;

    return 0;
}