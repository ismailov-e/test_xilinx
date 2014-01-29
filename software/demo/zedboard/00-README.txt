PLEASE TAKE NOTE:

This demo requires some source files which are not included in the GitHub repository.

The required source files are from Avnet's FMC-IMAGEON Building a Video Design
from Scratch Tutorial.

Avnet does not permit "publication" of their code, so we are not including the
files here.

If you wish to modify and/or re-compile the demo, you will need to download the
tutorial's zip file and copy the files listed below.

The Avnet zip file can downloaded from here:

ISE Design Suite 14.4 Tutorial: Creating a Video Design from Scratch
https://www.em.avnet.com/Support%20And%20Downloads/FMC_IMAGEON_Building_Video_Design_Tutorial_14_4_20130110.zip

If the above link does not work, try looking for it here:

HDMI Input/Output FMC Module Support Files
https://www.em.avnet.com/en-us/design/drc/pages/supportanddownloads.aspx?RelatedId=442

(Note: you will need to create an account on the Avnet web site in order to
access the above links.)

Alternatively, the zip file is also downloadable from
http://zedboard.org/sites/default/files/design/FMC_IMAGEON_Building_Video_Design_Tutorial_14_4_20130110.zip

Extract the zip file and copy the following files to this directory:

FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_detector.c
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_detector.h
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_frame_buffer.c
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_frame_buffer.h
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_generator.c
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_generator.h
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_resolution.c
FMC_IMAGEON_Tutorial/code/fmc_imageon_hdmi_framebuffer/video_resolution.h
FMC_IMAGEON_Tutorial/repository/ProcessorIPLib/sw_services/fmc_iic_sw_v2_03_a/src/fmc_iic.h
FMC_IMAGEON_Tutorial/repository/ProcessorIPLib/sw_services/fmc_imageon_sw_v1_07_a/src/fmc_imageon.h

For the same reasons, the contents of
FMC_IMAGEON_Tutorial/repository/ProcessorIPLib/sw_services/fmc_iic_sw_v2_03_a/ and
FMC_IMAGEON_Tutorial/repository/ProcessorIPLib/sw_services/fmc_imageon_sw_v1_07_a/
are not included in the BSPs of the pre-built systems, but the BSP library is already
compiled and you will probably not need to recompile it.

