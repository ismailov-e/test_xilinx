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
PROJ_ROOT := $(call myrealpath,$(MAKEFILE_DIR)/../../boards/zedboard_imageon_arm_mxp/prebuilt_zedboard_imageon_arm_mxp_v16)
else
PROJ_ROOT := $(realpath $(MAKEFILE_DIR)/../../boards/zedboard_imageon_arm_mxp/prebuilt_zedboard_imageon_arm_mxp_v16)
endif
SDK_EXPORT_ROOT := $(PROJ_ROOT)/SDK/SDK_Export

# HW_PLATFORM_XML
HW_PLATFORM_XML := $(SDK_EXPORT_ROOT)/hw/system.xml

ifeq ($(CPU_TARGET), MB)
PROCESSOR_INSTANCE := microblaze_0
CC := mb-gcc
AR := mb-ar
SZ := mb-size
else
PROCESSOR_INSTANCE := ps7_cortexa9_0
CC := arm-xilinx-eabi-gcc
AR := arm-xilinx-eabi-ar
SZ := arm-xilinx-eabi-size
endif

# BSP_ROOT_DIR
BSP_ROOT_DIR := $(PROJ_ROOT)/bsp
BSP_INC_DIR  := $(BSP_ROOT_DIR)/$(PROCESSOR_INSTANCE)/include
BSP_LIB_DIR  := $(BSP_ROOT_DIR)/$(PROCESSOR_INSTANCE)/lib

# Get CPU gcc flags from BSP, e.g. for MicroBlaze:
# CPU_FLAGS := -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare \
#              -mcpu=v8.40.b -mno-xl-soft-mul
-include $(BSP_ROOT_DIR)/cpu_flags.mk
OPT_FLAGS := -O3
# Debug opt flags:
# OPT_FLAGS := -O0 -g3 -Wl,--no-relax
CC_FLAGS := -Wall -c -fmessage-length=0 $(EXTRA_CC_FLAGS)

# LD_SCRIPT := lscript.ld
LD_SCRIPT := $(PROJ_ROOT)/etc/lscript.ld

LD_FLAGS := -Wl,-T -Wl,$(LD_SCRIPT)
# Debug linker flags
# LD_FLAGS += -Wl,--no-relax

ifeq ($(CPU_TARGET), MB)
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
ifeq ($(CPU_TARGET), MB)
OBJ_DIR := $(OBJ_ROOT_DIR)/mb
else
OBJ_DIR := $(OBJ_ROOT_DIR)/arm
endif

OBJS := $(addprefix $(OBJ_DIR)/,$(patsubst %.c,%.o,$(filter %.c,$(C_SRCS))))

C_DEPS := $(OBJS:.o=.d)

