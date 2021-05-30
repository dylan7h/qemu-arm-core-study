#============================================================
# Set Toolchain
#============================================================
TOOL_CHAIN		:=	/opt/gcc-arm-10.2-2020.11-x86_64-arm-none-eabi/bin/
CROSS_COMPILE	:=	arm-none-eabi-

AS	:= $(TOOL_CHAIN)$(CROSS_COMPILE)as
CC	:= $(TOOL_CHAIN)$(CROSS_COMPILE)gcc
AR	:= $(TOOL_CHAIN)$(CROSS_COMPILE)ar
LD	:= $(TOOL_CHAIN)$(CROSS_COMPILE)ld
OD	:= $(TOOL_CHAIN)$(CROSS_COMPILE)objdump
OC	:= $(TOOL_CHAIN)$(CROSS_COMPILE)objcopy
