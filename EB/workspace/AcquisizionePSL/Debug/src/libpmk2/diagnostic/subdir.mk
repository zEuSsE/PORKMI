################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk2/diagnostic/hc-viewer.cc \
../src/libpmk2/diagnostic/kernel-viewer.cc \
../src/libpmk2/diagnostic/pointset-viewer.cc \
../src/libpmk2/diagnostic/pyramid-viewer.cc 

OBJS += \
./src/libpmk2/diagnostic/hc-viewer.o \
./src/libpmk2/diagnostic/kernel-viewer.o \
./src/libpmk2/diagnostic/pointset-viewer.o \
./src/libpmk2/diagnostic/pyramid-viewer.o 

CC_DEPS += \
./src/libpmk2/diagnostic/hc-viewer.d \
./src/libpmk2/diagnostic/kernel-viewer.d \
./src/libpmk2/diagnostic/pointset-viewer.d \
./src/libpmk2/diagnostic/pyramid-viewer.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk2/diagnostic/%.o: ../src/libpmk2/diagnostic/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


