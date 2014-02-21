# BSP is expected to include the adv7511_lib library.

CPU_TARGET := XIL

include ../../common/xil_app_vars.mk
include sources.mk

EXTRA_CC_FLAGS := -DDEMO -DSYSTEM_ZEDBOARD

APP_INCLUDE_DIRS := ../common

ALT_LIBRARY_ROOT_DIR := ../../lib/vbxware
include ../../lib/vbxware/public.mk
ALT_LIBRARY_ROOT_DIR := ../../lib/vbxtest
include ../../lib/vbxtest/public.mk
ALT_LIBRARY_ROOT_DIR := ../../lib/scalar
include ../../lib/scalar/public.mk
ALT_LIBRARY_ROOT_DIR := ../../lib/libfixmath
include ../../lib/libfixmath/public.mk

include ../../common/xil_app.mk

