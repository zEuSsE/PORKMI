################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list.o \
../src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list.o \
../src/libpmk-2.5/libpmk2/point_set/point-ref.o \
../src/libpmk-2.5/libpmk2/point_set/point-set-list.o \
../src/libpmk-2.5/libpmk2/point_set/point-set.o \
../src/libpmk-2.5/libpmk2/point_set/point.o 

CC_SRCS += \
../src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list.cc \
../src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list_unittest.cc \
../src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list.cc \
../src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list_unittest.cc \
../src/libpmk-2.5/libpmk2/point_set/point-ref.cc \
../src/libpmk-2.5/libpmk2/point_set/point-set-list.cc \
../src/libpmk-2.5/libpmk2/point_set/point-set.cc \
../src/libpmk-2.5/libpmk2/point_set/point-set_unittest.cc \
../src/libpmk-2.5/libpmk2/point_set/point.cc \
../src/libpmk-2.5/libpmk2/point_set/point_unittest.cc 

OBJS += \
./src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list.o \
./src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list_unittest.o \
./src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list.o \
./src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list_unittest.o \
./src/libpmk-2.5/libpmk2/point_set/point-ref.o \
./src/libpmk-2.5/libpmk2/point_set/point-set-list.o \
./src/libpmk-2.5/libpmk2/point_set/point-set.o \
./src/libpmk-2.5/libpmk2/point_set/point-set_unittest.o \
./src/libpmk-2.5/libpmk2/point_set/point.o \
./src/libpmk-2.5/libpmk2/point_set/point_unittest.o 

CC_DEPS += \
./src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list.d \
./src/libpmk-2.5/libpmk2/point_set/mutable-point-set-list_unittest.d \
./src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list.d \
./src/libpmk-2.5/libpmk2/point_set/on-disk-point-set-list_unittest.d \
./src/libpmk-2.5/libpmk2/point_set/point-ref.d \
./src/libpmk-2.5/libpmk2/point_set/point-set-list.d \
./src/libpmk-2.5/libpmk2/point_set/point-set.d \
./src/libpmk-2.5/libpmk2/point_set/point-set_unittest.d \
./src/libpmk-2.5/libpmk2/point_set/point.d \
./src/libpmk-2.5/libpmk2/point_set/point_unittest.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/libpmk2/point_set/%.o: ../src/libpmk-2.5/libpmk2/point_set/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


