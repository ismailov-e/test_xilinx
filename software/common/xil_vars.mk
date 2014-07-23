MAKEFILE_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

PROJ_NAME :=

# $realpath is broken on Windows in Make 3.81; see
# http://lists.gnu.org/archive/html/make-w32/2008-02/msg00004.html
# Doesn't work properly when arg begins with drive letter; get current
# working directory concatenated with absolute path of argument.
# On Windows, use the work-around from the above link.
myrealpath = $(join \
             $(filter %:,$(subst :,: ,$(1))),\
             $(realpath $(filter-out %:,$(subst :,: ,$(1)))))

ifdef ComSpec
PROJ_ROOT := $(call myrealpath,$(MAKEFILE_DIR)/../../boards/zedboard_imageon_arm/prebuilt_zedboard_imageon_arm_v16)
else
PROJ_ROOT := $(realpath $(MAKEFILE_DIR)/../../boards/zedboard_imageon_arm/prebuilt_zedboard_imageon_arm_v16)
endif
SDK_EXPORT_ROOT := $(PROJ_ROOT)/SDK/SDK_Export

# HW_PLATFORM_XML
HW_PLATFORM_XML := $(SDK_EXPORT_ROOT)/hw/system.xml

# BSP_ROOT_DIR
BSP_ROOT_DIR := $(PROJ_ROOT)/bsp

# CPU gcc flags
# e.g. for MicroBlaze:
# CPU_FLAGS := -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare \
#              -mcpu=v8.40.b -mno-xl-soft-mul
CPU_FLAGS :=
# e.g. -DUSE_ZYNQ_UART for MicroBlaze on Zynq.
CMACRO_DEFS :=
# microblaze, cortexa9
PROCESSOR_TYPE := microblaze
# e.g. microblaze_0, ps7_cortexa9_0
PROCESSOR_INSTANCE := microblaze_0
# bsp_vars.mk overrides all these variables.
-include $(BSP_ROOT_DIR)/bsp_vars.mk

OPT_FLAGS := -O3
# Debug opt flags:
# OPT_FLAGS := -O0 -g3 -Wl,--no-relax
CC_FLAGS := -Wall -c -fmessage-length=0 $(CMACRO_DEFS) $(EXTRA_CC_FLAGS)
CXX_FLAGS := -fno-rtti -fno-exceptions $(CC_FLAGS)

BSP_INC_DIR  := $(BSP_ROOT_DIR)/$(PROCESSOR_INSTANCE)/include
BSP_LIB_DIR  := $(BSP_ROOT_DIR)/$(PROCESSOR_INSTANCE)/lib

ifeq ($(PROCESSOR_TYPE), microblaze)
CROSS_COMPILER=mb
else
CROSS_COMPILER=arm-xilinx-eabi
endif

CC := $(CROSS_COMPILER)-gcc
CXX := $(CROSS_COMPILER)-gcc -xc++
LD := $(CROSS_COMPILER)-g++
AR := $(CROSS_COMPILER)-ar
SZ := $(CROSS_COMPILER)-size


# LD_SCRIPT := lscript.ld
LD_SCRIPT := $(PROJ_ROOT)/etc/lscript.ld

LD_FLAGS := -Wl,-T -Wl,$(LD_SCRIPT)
# Debug linker flags
# LD_FLAGS += -Wl,--no-relax

ifeq ($(PROCESSOR_TYPE), microblaze)
LIBS += -Wl,--start-group,-lxil,-lgcc,-lc,--end-group
else
LIBS += -Wl,--start-group,-lxil,-lgcc,-lc,-lm,--end-group
endif

# On Windows, want to use gnuwin32 mkdir and not built-in cmd.exe mkdir
# Could also use ifeq (${OS}, Windows_NT)
ifdef ComSpec
MKDIR := $(XILINX_EDK)/gnuwin/bin/mkdir.exe
else
MKDIR := mkdir
endif

RM := rm -rf

OBJ_ROOT_DIR := obj
ifeq ($(PROCESSOR_TYPE), microblaze)
OBJ_DIR := $(OBJ_ROOT_DIR)/mb
else
OBJ_DIR := $(OBJ_ROOT_DIR)/arm
endif

OBJS := $(addprefix $(OBJ_DIR)/,$(notdir $(patsubst %.c,%.o,$(filter %.c,$(C_SRCS)))))
OBJS += $(addprefix $(OBJ_DIR)/,$(notdir $(patsubst %.cpp,%.o,$(filter %.cpp,$(CXX_SRCS)))))
C_DEPS := $(OBJS:.o=.d)

