################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/avt/tools/grow-vocabulary-tree.cc \
../src/libpmk-2.5/avt/tools/partial-pyramids.cc \
../src/libpmk-2.5/avt/tools/test-vocabulary-tree.cc 

OBJS += \
./src/libpmk-2.5/avt/tools/grow-vocabulary-tree.o \
./src/libpmk-2.5/avt/tools/partial-pyramids.o \
./src/libpmk-2.5/avt/tools/test-vocabulary-tree.o 

CC_DEPS += \
./src/libpmk-2.5/avt/tools/grow-vocabulary-tree.d \
./src/libpmk-2.5/avt/tools/partial-pyramids.d \
./src/libpmk-2.5/avt/tools/test-vocabulary-tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/avt/tools/%.o: ../src/libpmk-2.5/avt/tools/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


