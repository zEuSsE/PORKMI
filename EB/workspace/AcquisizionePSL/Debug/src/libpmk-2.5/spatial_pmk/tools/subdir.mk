################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/spatial_pmk/tools/channelize-point-set-list.cc \
../src/libpmk-2.5/spatial_pmk/tools/pointsets-to-normalized-spatial-pyramids.cc \
../src/libpmk-2.5/spatial_pmk/tools/pointsets-to-spatial-pyramids.cc \
../src/libpmk-2.5/spatial_pmk/tools/pyramids-to-kernel.cc \
../src/libpmk-2.5/spatial_pmk/tools/simple-pointsets-to-spatial-pyramid.cc \
../src/libpmk-2.5/spatial_pmk/tools/split-into-channels.cc 

OBJS += \
./src/libpmk-2.5/spatial_pmk/tools/channelize-point-set-list.o \
./src/libpmk-2.5/spatial_pmk/tools/pointsets-to-normalized-spatial-pyramids.o \
./src/libpmk-2.5/spatial_pmk/tools/pointsets-to-spatial-pyramids.o \
./src/libpmk-2.5/spatial_pmk/tools/pyramids-to-kernel.o \
./src/libpmk-2.5/spatial_pmk/tools/simple-pointsets-to-spatial-pyramid.o \
./src/libpmk-2.5/spatial_pmk/tools/split-into-channels.o 

CC_DEPS += \
./src/libpmk-2.5/spatial_pmk/tools/channelize-point-set-list.d \
./src/libpmk-2.5/spatial_pmk/tools/pointsets-to-normalized-spatial-pyramids.d \
./src/libpmk-2.5/spatial_pmk/tools/pointsets-to-spatial-pyramids.d \
./src/libpmk-2.5/spatial_pmk/tools/pyramids-to-kernel.d \
./src/libpmk-2.5/spatial_pmk/tools/simple-pointsets-to-spatial-pyramid.d \
./src/libpmk-2.5/spatial_pmk/tools/split-into-channels.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/spatial_pmk/tools/%.o: ../src/libpmk-2.5/spatial_pmk/tools/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


