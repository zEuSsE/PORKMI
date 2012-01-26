################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/spatial_pmk/spatial/channelizer.cc \
../src/libpmk-2.5/spatial_pmk/spatial/channelizer_unittest.cc \
../src/libpmk-2.5/spatial_pmk/spatial/normalized-spatial-pyramid-maker.cc \
../src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-maker.cc \
../src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-reader.cc \
../src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-writer.cc 

OBJS += \
./src/libpmk-2.5/spatial_pmk/spatial/channelizer.o \
./src/libpmk-2.5/spatial_pmk/spatial/channelizer_unittest.o \
./src/libpmk-2.5/spatial_pmk/spatial/normalized-spatial-pyramid-maker.o \
./src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-maker.o \
./src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-reader.o \
./src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-writer.o 

CC_DEPS += \
./src/libpmk-2.5/spatial_pmk/spatial/channelizer.d \
./src/libpmk-2.5/spatial_pmk/spatial/channelizer_unittest.d \
./src/libpmk-2.5/spatial_pmk/spatial/normalized-spatial-pyramid-maker.d \
./src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-maker.d \
./src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-reader.d \
./src/libpmk-2.5/spatial_pmk/spatial/spatial-pyramid-writer.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/spatial_pmk/spatial/%.o: ../src/libpmk-2.5/spatial_pmk/spatial/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


