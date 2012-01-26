################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/libpmk_ism/examples/test-model.cc \
../src/libpmk-2.5/libpmk_ism/examples/train-model.cc 

OBJS += \
./src/libpmk-2.5/libpmk_ism/examples/test-model.o \
./src/libpmk-2.5/libpmk_ism/examples/train-model.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk_ism/examples/test-model.d \
./src/libpmk-2.5/libpmk_ism/examples/train-model.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk_ism/examples/%.o: ../src/libpmk-2.5/libpmk_ism/examples/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


