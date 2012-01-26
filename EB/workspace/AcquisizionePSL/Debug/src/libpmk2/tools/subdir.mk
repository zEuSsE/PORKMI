################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk2/tools/clean-psl.cc \
../src/libpmk2/tools/clean-single-psl.cc \
../src/libpmk2/tools/clusters-to-pyramids.cc \
../src/libpmk2/tools/exponent-kernel.cc \
../src/libpmk2/tools/extract-classes-from-psl.cc \
../src/libpmk2/tools/extract-subset-from-psl.cc \
../src/libpmk2/tools/feature-value-discretizer.cc \
../src/libpmk2/tools/generate-random-psl.cc \
../src/libpmk2/tools/hierarchical-cluster-point-set.cc \
../src/libpmk2/tools/kernel-adder.cc \
../src/libpmk2/tools/large-upmk-example.cc \
../src/libpmk2/tools/normalize-kernel.cc \
../src/libpmk2/tools/partial-pyramid-match-kernel.cc \
../src/libpmk2/tools/pointset-merger.cc \
../src/libpmk2/tools/pointsets-to-uniform-pyramids.cc \
../src/libpmk2/tools/psl-sampler.cc \
../src/libpmk2/tools/pyramid-match-chunk.cc \
../src/libpmk2/tools/pyramid-match-kernel.cc \
../src/libpmk2/tools/pyramid-match-self-similarity.cc \
../src/libpmk2/tools/pyramid-match-split.cc \
../src/libpmk2/tools/random-sampler.cc \
../src/libpmk2/tools/random-sampling-merger.cc \
../src/libpmk2/tools/reverse-psl.cc 

OBJS += \
./src/libpmk2/tools/clean-psl.o \
./src/libpmk2/tools/clean-single-psl.o \
./src/libpmk2/tools/clusters-to-pyramids.o \
./src/libpmk2/tools/exponent-kernel.o \
./src/libpmk2/tools/extract-classes-from-psl.o \
./src/libpmk2/tools/extract-subset-from-psl.o \
./src/libpmk2/tools/feature-value-discretizer.o \
./src/libpmk2/tools/generate-random-psl.o \
./src/libpmk2/tools/hierarchical-cluster-point-set.o \
./src/libpmk2/tools/kernel-adder.o \
./src/libpmk2/tools/large-upmk-example.o \
./src/libpmk2/tools/normalize-kernel.o \
./src/libpmk2/tools/partial-pyramid-match-kernel.o \
./src/libpmk2/tools/pointset-merger.o \
./src/libpmk2/tools/pointsets-to-uniform-pyramids.o \
./src/libpmk2/tools/psl-sampler.o \
./src/libpmk2/tools/pyramid-match-chunk.o \
./src/libpmk2/tools/pyramid-match-kernel.o \
./src/libpmk2/tools/pyramid-match-self-similarity.o \
./src/libpmk2/tools/pyramid-match-split.o \
./src/libpmk2/tools/random-sampler.o \
./src/libpmk2/tools/random-sampling-merger.o \
./src/libpmk2/tools/reverse-psl.o 

CC_DEPS += \
./src/libpmk2/tools/clean-psl.d \
./src/libpmk2/tools/clean-single-psl.d \
./src/libpmk2/tools/clusters-to-pyramids.d \
./src/libpmk2/tools/exponent-kernel.d \
./src/libpmk2/tools/extract-classes-from-psl.d \
./src/libpmk2/tools/extract-subset-from-psl.d \
./src/libpmk2/tools/feature-value-discretizer.d \
./src/libpmk2/tools/generate-random-psl.d \
./src/libpmk2/tools/hierarchical-cluster-point-set.d \
./src/libpmk2/tools/kernel-adder.d \
./src/libpmk2/tools/large-upmk-example.d \
./src/libpmk2/tools/normalize-kernel.d \
./src/libpmk2/tools/partial-pyramid-match-kernel.d \
./src/libpmk2/tools/pointset-merger.d \
./src/libpmk2/tools/pointsets-to-uniform-pyramids.d \
./src/libpmk2/tools/psl-sampler.d \
./src/libpmk2/tools/pyramid-match-chunk.d \
./src/libpmk2/tools/pyramid-match-kernel.d \
./src/libpmk2/tools/pyramid-match-self-similarity.d \
./src/libpmk2/tools/pyramid-match-split.d \
./src/libpmk2/tools/random-sampler.d \
./src/libpmk2/tools/random-sampling-merger.d \
./src/libpmk2/tools/reverse-psl.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk2/tools/%.o: ../src/libpmk2/tools/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


