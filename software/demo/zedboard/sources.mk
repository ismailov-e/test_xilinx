ELF := demo.elf

C_SRCS += zedboard_demo.c
C_SRCS += platform.c
C_SRCS += sleep_mb.c
C_SRCS += ps7_uart.c
C_SRCS += board.c
C_SRCS += vfb_for_demo.c

C_SRCS += video_detector.c
C_SRCS += video_frame_buffer.c
C_SRCS += video_generator.c
C_SRCS += video_resolution.c

C_SRCS += ../common/main.c
C_SRCS += ../common/demo.c

C_SRCS += ../common/vblogo.c
C_SRCS += ../common/char_buffer.c
C_SRCS += ../common/draw.c

C_SRCS += ../common/mandel.c
C_SRCS += ../common/motest.c

C_SRCS += ../common/vector_functions.c
C_SRCS += ../common/scalar_functions.c

C_SRCS += ../common/haar_face_alt.c
C_SRCS += ../common/vector_haar_detect.c
C_SRCS += ../common/scalar_haar_detect.c

C_SRCS += ../common/repulse.c
C_SRCS += ../common/vector_repulsion.c
C_SRCS += ../common/scalar_repulsion.c
C_SRCS += ../common/gravity.c

