################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/libpmk-2.5/libpmk2/clustering/clusterer.o \
../src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer.o \
../src/libpmk-2.5/libpmk2/clustering/k-means-clusterer.o \
../src/libpmk-2.5/libpmk2/clustering/rnn-clusterer.o 

CC_SRCS += \
../src/libpmk-2.5/libpmk2/clustering/clusterer.cc \
../src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer.cc \
../src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer_unittest.cc \
../src/libpmk-2.5/libpmk2/clustering/k-means-clusterer.cc \
../src/libpmk-2.5/libpmk2/clustering/k-means-clusterer_unittest.cc \
../src/libpmk-2.5/libpmk2/clustering/rnn-clusterer.cc \
../src/libpmk-2.5/libpmk2/clustering/rnn-clusterer_unittest.cc 

OBJS += \
./src/libpmk-2.5/libpmk2/clustering/clusterer.o \
./src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer.o \
./src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer_unittest.o \
./src/libpmk-2.5/libpmk2/clustering/k-means-clusterer.o \
./src/libpmk-2.5/libpmk2/clustering/k-means-clusterer_unittest.o \
./src/libpmk-2.5/libpmk2/clustering/rnn-clusterer.o \
./src/libpmk-2.5/libpmk2/clustering/rnn-clusterer_unittest.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk2/clustering/clusterer.d \
./src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer.d \
./src/libpmk-2.5/libpmk2/clustering/hierarchical-clusterer_unittest.d \
./src/libpmk-2.5/libpmk2/clustering/k-means-clusterer.d \
./src/libpmk-2.5/libpmk2/clustering/k-means-clusterer_unittest.d \
./src/libpmk-2.5/libpmk2/clustering/rnn-clusterer.d \
./src/libpmk-2.5/libpmk2/clustering/rnn-clusterer_unittest.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk2/clustering/%.o: ../src/libpmk-2.5/libpmk2/clustering/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


