################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccsv5/tools/compiler/c2000_6.2.0

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./user_main.obj" \
"./fir_proc.obj" \
"./DSP2833x_usDelay.obj" \
"./DSP2833x_Xintf.obj" \
"./DSP2833x_SysCtrl.obj" \
"./DSP2833x_PieVect.obj" \
"./DSP2833x_PieCtrl.obj" \
"./DSP2833x_InitPeripherals.obj" \
"./DSP2833x_Gpio.obj" \
"./DSP2833x_GlobalVariableDefs.obj" \
"./DSP2833x_DefaultIsr.obj" \
"./DSP2833x_CpuTimers.obj" \
"./DSP2833x_CodeStartBranch.obj" \
"./CH395.obj" \
"../cmd/DSP2833x_Headers_nonBIOS.cmd" \
"../cmd/F28335_RAM_lnk.cmd" \
-l"libc.a" \
-l"C:\ti\ccsv5\tools\compiler\c2000_6.2.0\lib\rts2800_fpu32.lib" \
-l"C:\ti\ccsv5\tools\compiler\c2000_6.2.0\lib\rts2800_ml.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include cmd/subdir_vars.mk
-include subdir_rules.mk
-include cmd/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: AD-FIR-FFT.out

# Tool invocations
AD-FIR-FFT.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/bin/cl2000" -v28 -ml -mt --float_support=fpu32 -g --diag_warning=225 --display_error_number --diag_wrap=off -z -m"AD-FIR-FFT.map" --stack_size=0x300 --warn_sections -i"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/lib" -i"C:/ti/ccsv5/tools/compiler/c2000_6.2.0/include" -i"C:/ti/myproject/AD-FIR-FFT" --reread_libs --display_error_number --diag_wrap=off --xml_link_info="AD-FIR-FFT_linkInfo.xml" --rom_model -o "AD-FIR-FFT.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C2000_EXECUTABLE_OUTPUTS__QUOTED) "AD-FIR-FFT.out"
	-$(RM) "DSP2833x_CpuTimers.pp" "DSP2833x_DefaultIsr.pp" "DSP2833x_GlobalVariableDefs.pp" "DSP2833x_Gpio.pp" "DSP2833x_InitPeripherals.pp" "DSP2833x_PieCtrl.pp" "DSP2833x_PieVect.pp" "DSP2833x_SysCtrl.pp" "DSP2833x_Xintf.pp" "fir_proc.pp" "user_main.pp" 
	-$(RM) "CH395.pp" 
	-$(RM) "CH395.obj" "DSP2833x_CodeStartBranch.obj" "DSP2833x_CpuTimers.obj" "DSP2833x_DefaultIsr.obj" "DSP2833x_GlobalVariableDefs.obj" "DSP2833x_Gpio.obj" "DSP2833x_InitPeripherals.obj" "DSP2833x_PieCtrl.obj" "DSP2833x_PieVect.obj" "DSP2833x_SysCtrl.obj" "DSP2833x_Xintf.obj" "DSP2833x_usDelay.obj" "fir_proc.obj" "user_main.obj" 
	-$(RM) "DSP2833x_CodeStartBranch.pp" "DSP2833x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

