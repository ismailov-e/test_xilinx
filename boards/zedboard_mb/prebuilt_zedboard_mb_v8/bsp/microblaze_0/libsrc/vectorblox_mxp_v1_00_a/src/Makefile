##############################################################################
## Description:       Microprocessor Driver Makefile
## (Based on version from Create and Import Peripheral Wizard)
##############################################################################

COMPILER=
ARCHIVER=
CP=cp
COMPILER_FLAGS=
EXTRA_COMPILER_FLAGS=
LIB=libxil.a

RELEASEDIR=../../../lib
INCLUDEDIR=../../../include
INCLUDES=-I./. -I${INCLUDEDIR}

INCLUDEFILES=*.h
LIBSOURCES=*.c
OUTS = *.o

USE_VBXLIB_SRC := false

libs:
	echo "Compiling vectorblox_mxp"
	$(COMPILER) $(COMPILER_FLAGS) $(EXTRA_COMPILER_FLAGS) $(INCLUDES) $(LIBSOURCES)
ifeq ($(USE_VBXLIB_SRC), false)
	# echo "Extracting libvbxlib_mb.a members for insertion into $(LIB)"
	# mkdir vbxlib && cd vbxlib && $(ARCHIVER) xv ../libvbxlib_mb.a
	mkdir vbxlib && cd vbxlib && $(ARCHIVER) x ../libvbxlib_mb.a
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} vbxlib/*.o
endif
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} ${OUTS}
	$(MAKE) clean

include:
	${CP} $(INCLUDEFILES) $(INCLUDEDIR)

clean:
	rm -rf ${OUTS}
ifeq ($(USE_VBXLIB_SRC), false)
	rm -rf vbxlib
endif
