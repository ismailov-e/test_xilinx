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

ifeq ($(ARCHIVER), mb-ar)
ADI_LIB := libHDMI_ZedBoardLib_MB.a
else
ADI_LIB := libHDMI_ZedBoardLib.a
endif

libs:
	echo "Compiling adv7511_lib"
	# echo "Extracting $(ADI_LIB) members for insertion into $(LIB)"
	mkdir tmplib && cd tmplib && $(ARCHIVER) x ../$(ADI_LIB)
	$(ARCHIVER) -r ${RELEASEDIR}/${LIB} tmplib/*.o
	make clean

include:
	${CP} $(INCLUDEFILES) $(INCLUDEDIR)

clean:
	rm -rf tmplib

