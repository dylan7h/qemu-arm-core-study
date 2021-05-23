#============================================================
# Set Configurations
#============================================================
# File Extension
FILE_EXT		:=	elf

# Build Mode( debug | release )
BUILD_MODE		:=	debug

# Display Build Log( 0 | 1 )
BUILD_VERBOSE	:=	0

# C Standard Version
C_STANDARD_VER	:= 	11

# ARM Architecture Version
ARCH			:=	armv7-a

# ARM Core
CPU				:= 	cortex-a8

# Instruction Set
INSTRUCTION_SET	:=	arm

#============================================================
# Set Compile & Link Options by Configurations
#============================================================
CFLAGS		:= -march=$(ARCH) -mtune=$(CPU) -m$(INSTRUCTION_SET) -std=c$(C_STANDARD_VER) -Wall
LDFLAGS		:= -nostdlib -nostartfiles -nodefaultlibs -static

ifeq ($(BUILD_MODE), debug)
	CFLAGS		+= -g
else ifeq ($(BUILD_MODE), release)
	CFLAGS		+= -O2
else
	#error "Invalid BUILD_MODE"
endif

ifeq ($(BUILD_VERBOSE), 0)
	V	:=	@
endif
