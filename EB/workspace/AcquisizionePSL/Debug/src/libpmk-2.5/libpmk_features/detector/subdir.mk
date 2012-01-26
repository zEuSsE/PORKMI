################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/libpmk_features/detector/detector.cc \
../src/libpmk-2.5/libpmk_features/detector/filtering-grid-detector.cc \
../src/libpmk-2.5/libpmk_features/detector/grid-detector.cc \
../src/libpmk-2.5/libpmk_features/detector/harris-detector.cc \
../src/libpmk-2.5/libpmk_features/detector/image-detector.cc \
../src/libpmk-2.5/libpmk_features/detector/mser-detector.cc \
../src/libpmk-2.5/libpmk_features/detector/surf-detector.cc 

OBJS += \
./src/libpmk-2.5/libpmk_features/detector/detector.o \
./src/libpmk-2.5/libpmk_features/detector/filtering-grid-detector.o \
./src/libpmk-2.5/libpmk_features/detector/grid-detector.o \
./src/libpmk-2.5/libpmk_features/detector/harris-detector.o \
./src/libpmk-2.5/libpmk_features/detector/image-detector.o \
./src/libpmk-2.5/libpmk_features/detector/mser-detector.o \
./src/libpmk-2.5/libpmk_features/detector/surf-detector.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk_features/detector/detector.d \
./src/libpmk-2.5/libpmk_features/detector/filtering-grid-detector.d \
./src/libpmk-2.5/libpmk_features/detector/grid-detector.d \
./src/libpmk-2.5/libpmk_features/detector/harris-detector.d \
./src/libpmk-2.5/libpmk_features/detector/image-detector.d \
./src/libpmk-2.5/libpmk_features/detector/mser-detector.d \
./src/libpmk-2.5/libpmk_features/detector/surf-detector.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk_features/detector/%.o: ../src/libpmk-2.5/libpmk_features/detector/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


