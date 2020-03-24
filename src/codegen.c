#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <llvm-c/Types.h>
#include <llvm-c/Target.h>
#include <llvm-c/TargetMachine.h>
#include <llvm-c/Core.h>
#include <llvm-c/Object.h>
#include <llvm-c/ExecutionEngine.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/Transforms/Scalar.h>
#include <llvm-c/Transforms/Utils.h>

static LLVMModuleRef		module = NULL;
static LLVMBuilderRef		builder = NULL;
static LLVMPassManagerRef	pass_manager = NULL;

void	codegen_init()
{
	LLVMInitializeAllTargetInfos();
	LLVMInitializeAllTargets();
	LLVMInitializeAllTargetMCs();
	LLVMInitializeAllAsmParsers();
	LLVMInitializeAllAsmPrinters();

	module = LLVMModuleCreateWithName("cpcsc");
	builder = LLVMCreateBuilder();

	pass_manager = LLVMCreateFunctionPassManagerForModule(module);
	LLVMAddPromoteMemoryToRegisterPass(pass_manager);
	LLVMAddInstructionCombiningPass(pass_manager);
	LLVMAddGVNPass(pass_manager);
	LLVMAddPromoteMemoryToRegisterPass(pass_manager);
	LLVMInitializeFunctionPassManager(pass_manager);
}

void	codegen_emit_entry(void)
{
	LLVMTypeRef main_type;
	LLVMValueRef main;
	LLVMBasicBlockRef entry;
	
	main_type = LLVMFunctionType(LLVMVoidType(), NULL, 0, false);
	main = LLVMAddFunction(module, "main", main_type);
	
	entry = LLVMAppendBasicBlock(main, "entry");
	LLVMPositionBuilderAtEnd(builder, entry);
	LLVMBuildRetVoid(builder);
}

void	codegen_emit(const char *obj_file)
{
	const char		*triple;
	LLVMTargetRef		target;
	LLVMTargetMachineRef	target_machine;
	char			*error;

	codegen_emit_entry();
	triple = LLVMGetDefaultTargetTriple();
	printf("Target triple: \033[35m%s\033[0m\n", triple);
	if (LLVMGetTargetFromTriple(triple, &target, &error) != 0)
	{
		printf("Error: %s\n", error);
		return;
	}
	printf("Target: \033[36m%s\033[0m\n", LLVMGetTargetName(target));
	target_machine = LLVMCreateTargetMachine(target, triple, "", "",
			LLVMCodeGenLevelDefault, LLVMRelocDefault, LLVMCodeModelDefault);
	if (LLVMTargetMachineEmitToFile(target_machine, module, (char *)obj_file, LLVMObjectFile, &error) != 0)
	{
		printf("Error: %s\n", error);
		return;
	}
}

int	codegen(const char *obj_file)
{
	codegen_init();
	codegen_emit(obj_file);

	LLVMDisposePassManager(pass_manager);
	LLVMDisposeBuilder(builder);
	LLVMDisposeModule(module);
	return (0);
}
