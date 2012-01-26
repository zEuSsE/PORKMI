################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/libpmk-2.5/libpmk2/pyramids/global-vg-pyramid-maker.o \
../src/libpmk-2.5/libpmk2/pyramids/input-specific-vg-pyramid-maker.o \
../src/libpmk-2.5/libpmk2/pyramids/normalized-uniform-pyramid-maker.o \
../src/libpmk-2.5/libpmk2/pyramids/pyramid-maker.o \
../src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher.o \
../src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker.o \
../src/libpmk-2.5/libpmk2/pyramids/vg-pyramid-maker.o 

CC_SRCS += \
../src/libpmk-2.5/libpmk2/pyramids/global-vg-pyramid-maker.cc \
../src/libpmk-2.5/libpmk2/pyramids/input-specific-vg-pyramid-maker.cc \
../src/libpmk-2.5/libpmk2/pyramids/normalized-uniform-pyramid-maker.cc \
../src/libpmk-2.5/libpmk2/pyramids/pyramid-maker.cc \
../src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher.cc \
../src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher_unittest.cc \
../src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker.cc \
../src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker_unittest.cc \
../src/libpmk-2.5/libpmk2/pyramids/vg-pyramid-maker.cc 

OBJS += \
./src/libpmk-2.5/libpmk2/pyramids/global-vg-pyramid-maker.o \
./src/libpmk-2.5/libpmk2/pyramids/input-specific-vg-pyramid-maker.o \
./src/libpmk-2.5/libpmk2/pyramids/normalized-uniform-pyramid-maker.o \
./src/libpmk-2.5/libpmk2/pyramids/pyramid-maker.o \
./src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher.o \
./src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher_unittest.o \
./src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker.o \
./src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker_unittest.o \
./src/libpmk-2.5/libpmk2/pyramids/vg-pyramid-maker.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk2/pyramids/global-vg-pyramid-maker.d \
./src/libpmk-2.5/libpmk2/pyramids/input-specific-vg-pyramid-maker.d \
./src/libpmk-2.5/libpmk2/pyramids/normalized-uniform-pyramid-maker.d \
./src/libpmk-2.5/libpmk2/pyramids/pyramid-maker.d \
./src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher.d \
./src/libpmk-2.5/libpmk2/pyramids/pyramid-matcher_unittest.d \
./src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker.d \
./src/libpmk-2.5/libpmk2/pyramids/uniform-pyramid-maker_unittest.d \
./src/libpmk-2.5/libpmk2/pyramids/vg-pyramid-maker.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk2/pyramids/%.o: ../src/libpmk-2.5/libpmk2/pyramids/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


