################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/libpmk_features/extractor/extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/image-extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/location-extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/oxford-vgg-extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/shape-context-extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/sift-extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/steerable-filter-extractor.cc \
../src/libpmk-2.5/libpmk_features/extractor/surf-extractor.cc 

OBJS += \
./src/libpmk-2.5/libpmk_features/extractor/extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/image-extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/location-extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/oxford-vgg-extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/shape-context-extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/sift-extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/steerable-filter-extractor.o \
./src/libpmk-2.5/libpmk_features/extractor/surf-extractor.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk_features/extractor/extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/image-extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/location-extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/oxford-vgg-extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/shape-context-extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/sift-extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/steerable-filter-extractor.d \
./src/libpmk-2.5/libpmk_features/extractor/surf-extractor.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk_features/extractor/%.o: ../src/libpmk-2.5/libpmk_features/extractor/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


