################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/libpmk-2.5/libpmk2/util/distance-computer.o \
../src/libpmk-2.5/libpmk2/util/labeled-index.o \
../src/libpmk-2.5/libpmk2/util/sparse-vector.o 

CC_SRCS += \
../src/libpmk-2.5/libpmk2/util/distance-computer.cc \
../src/libpmk-2.5/libpmk2/util/labeled-index.cc \
../src/libpmk-2.5/libpmk2/util/sparse-vector.cc 

OBJS += \
./src/libpmk-2.5/libpmk2/util/distance-computer.o \
./src/libpmk-2.5/libpmk2/util/labeled-index.o \
./src/libpmk-2.5/libpmk2/util/sparse-vector.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk2/util/distance-computer.d \
./src/libpmk-2.5/libpmk2/util/labeled-index.d \
./src/libpmk-2.5/libpmk2/util/sparse-vector.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk2/util/%.o: ../src/libpmk-2.5/libpmk2/util/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


