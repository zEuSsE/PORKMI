################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/libpmk-2.5/avt/trees/incremental-vocabulary-tree.cc \
../src/libpmk-2.5/avt/trees/inverted-file.cc \
../src/libpmk-2.5/avt/trees/simple-pyramid-maker.cc \
../src/libpmk-2.5/avt/trees/visual-word.cc \
../src/libpmk-2.5/avt/trees/vocabulary-tree-retriever.cc 

OBJS += \
./src/libpmk-2.5/avt/trees/incremental-vocabulary-tree.o \
./src/libpmk-2.5/avt/trees/inverted-file.o \
./src/libpmk-2.5/avt/trees/simple-pyramid-maker.o \
./src/libpmk-2.5/avt/trees/visual-word.o \
./src/libpmk-2.5/avt/trees/vocabulary-tree-retriever.o 

CC_DEPS += \
./src/libpmk-2.5/avt/trees/incremental-vocabulary-tree.d \
./src/libpmk-2.5/avt/trees/inverted-file.d \
./src/libpmk-2.5/avt/trees/simple-pyramid-maker.d \
./src/libpmk-2.5/avt/trees/visual-word.d \
./src/libpmk-2.5/avt/trees/vocabulary-tree-retriever.d 


# Each subdirectory must supply rules for building sources it contributes
src/libpmk-2.5/avt/trees/%.o: ../src/libpmk-2.5/avt/trees/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/andrea/workspace/AcquisizionePSL/src/libpmk-2.5/libpmk2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


