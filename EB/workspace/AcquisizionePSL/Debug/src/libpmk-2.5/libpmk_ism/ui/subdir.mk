################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/libpmk_ism/ui/demo.cc \
../src/libpmk-2.5/libpmk_ism/ui/featured-image.cc \
../src/libpmk-2.5/libpmk_ism/ui/frame.cc \
../src/libpmk-2.5/libpmk_ism/ui/image-box.cc \
../src/libpmk-2.5/libpmk_ism/ui/image-display.cc \
../src/libpmk-2.5/libpmk_ism/ui/image-overlay.cc \
../src/libpmk-2.5/libpmk_ism/ui/label-input-dialog.cc \
../src/libpmk-2.5/libpmk_ism/ui/selecting-image-box.cc \
../src/libpmk-2.5/libpmk_ism/ui/training-set-view.cc 

OBJS += \
./src/libpmk-2.5/libpmk_ism/ui/demo.o \
./src/libpmk-2.5/libpmk_ism/ui/featured-image.o \
./src/libpmk-2.5/libpmk_ism/ui/frame.o \
./src/libpmk-2.5/libpmk_ism/ui/image-box.o \
./src/libpmk-2.5/libpmk_ism/ui/image-display.o \
./src/libpmk-2.5/libpmk_ism/ui/image-overlay.o \
./src/libpmk-2.5/libpmk_ism/ui/label-input-dialog.o \
./src/libpmk-2.5/libpmk_ism/ui/selecting-image-box.o \
./src/libpmk-2.5/libpmk_ism/ui/training-set-view.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk_ism/ui/demo.d \
./src/libpmk-2.5/libpmk_ism/ui/featured-image.d \
./src/libpmk-2.5/libpmk_ism/ui/frame.d \
./src/libpmk-2.5/libpmk_ism/ui/image-box.d \
./src/libpmk-2.5/libpmk_ism/ui/image-display.d \
./src/libpmk-2.5/libpmk_ism/ui/image-overlay.d \
./src/libpmk-2.5/libpmk_ism/ui/label-input-dialog.d \
./src/libpmk-2.5/libpmk_ism/ui/selecting-image-box.d \
./src/libpmk-2.5/libpmk_ism/ui/training-set-view.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk_ism/ui/%.o: ../src/libpmk-2.5/libpmk_ism/ui/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


