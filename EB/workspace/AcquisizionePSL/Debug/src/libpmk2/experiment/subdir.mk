################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/libpmk2/experiment/eth-selector.o \
../src/libpmk2/experiment/example-selector.o \
../src/libpmk2/experiment/experiment.o \
../src/libpmk2/experiment/nn-experiment.o \
../src/libpmk2/experiment/prob-svm-experiment.o \
../src/libpmk2/experiment/random-selector.o \
../src/libpmk2/experiment/svm-experiment.o 

CC_SRCS += \
../src/libpmk2/experiment/eth-selector.cc \
../src/libpmk2/experiment/example-selector.cc \
../src/libpmk2/experiment/example-selector_unittest.cc \
../src/libpmk2/experiment/experiment.cc \
../src/libpmk2/experiment/nn-experiment.cc \
../src/libpmk2/experiment/prob-svm-experiment.cc \
../src/libpmk2/experiment/random-selector.cc \
../src/libpmk2/experiment/svm-experiment.cc 

OBJS += \
./src/libpmk2/experiment/eth-selector.o \
./src/libpmk2/experiment/example-selector.o \
./src/libpmk2/experiment/example-selector_unittest.o \
./src/libpmk2/experiment/experiment.o \
./src/libpmk2/experiment/nn-experiment.o \
./src/libpmk2/experiment/prob-svm-experiment.o \
./src/libpmk2/experiment/random-selector.o \
./src/libpmk2/experiment/svm-experiment.o 

CC_DEPS += \
./src/libpmk2/experiment/eth-selector.d \
./src/libpmk2/experiment/example-selector.d \
./src/libpmk2/experiment/example-selector_unittest.d \
./src/libpmk2/experiment/experiment.d \
./src/libpmk2/experiment/nn-experiment.d \
./src/libpmk2/experiment/prob-svm-experiment.d \
./src/libpmk2/experiment/random-selector.d \
./src/libpmk2/experiment/svm-experiment.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk2/experiment/%.o: ../src/libpmk2/experiment/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


