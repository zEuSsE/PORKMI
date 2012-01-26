################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/libpmk_ism/shape_model/codebook-entry.cc \
../src/libpmk-2.5/libpmk_ism/shape_model/hough-accumulator-3d.cc \
../src/libpmk-2.5/libpmk_ism/shape_model/implicit-shape-model.cc \
../src/libpmk-2.5/libpmk_ism/shape_model/model-group.cc \
../src/libpmk-2.5/libpmk_ism/shape_model/object-position-vote.cc \
../src/libpmk-2.5/libpmk_ism/shape_model/uniform-balloon-density-estimator.cc 

OBJS += \
./src/libpmk-2.5/libpmk_ism/shape_model/codebook-entry.o \
./src/libpmk-2.5/libpmk_ism/shape_model/hough-accumulator-3d.o \
./src/libpmk-2.5/libpmk_ism/shape_model/implicit-shape-model.o \
./src/libpmk-2.5/libpmk_ism/shape_model/model-group.o \
./src/libpmk-2.5/libpmk_ism/shape_model/object-position-vote.o \
./src/libpmk-2.5/libpmk_ism/shape_model/uniform-balloon-density-estimator.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk_ism/shape_model/codebook-entry.d \
./src/libpmk-2.5/libpmk_ism/shape_model/hough-accumulator-3d.d \
./src/libpmk-2.5/libpmk_ism/shape_model/implicit-shape-model.d \
./src/libpmk-2.5/libpmk_ism/shape_model/model-group.d \
./src/libpmk-2.5/libpmk_ism/shape_model/object-position-vote.d \
./src/libpmk-2.5/libpmk_ism/shape_model/uniform-balloon-density-estimator.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk_ism/shape_model/%.o: ../src/libpmk-2.5/libpmk_ism/shape_model/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


