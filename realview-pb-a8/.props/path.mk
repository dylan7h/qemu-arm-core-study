#============================================================
# Path of Build Product
#============================================================
BUILD_DIR	:=	$(TOPDIR)/build
OBJ_DIR		:=	$(BUILD_DIR)/obj/$(TARGET)
DEF_DIR		:=	$(BUILD_DIR)/def/$(TARGET)
BIN_DIR		:=	$(BUILD_DIR)/bin
ELF_DIR		:=	$(BUILD_DIR)/elf
MAP_DIR		:=	$(BUILD_DIR)/map
ASM_DIR		:=	$(BUILD_DIR)/asm


#============================================================
# Path of Include directoies
#============================================================
INC_PATH	:=	System/Include
INC_PATH	+=	System/CMSIS/Core_A/Include
INC_PATH	+=	Lib/Include
INC_PATH	+=	Lib/Include/SFR
INC_PATH	+=	App/Include


#============================================================
# Path of Source lists
#============================================================
# Linker
LDS			:= 	System/Source/ARMCA9.ld

# Assembly
ASRC		:= 	

# C Source
CSRC		:= 	System/Source/startup_ARMCA9.c
CSRC		+= 	App/Source/main.c
CSRC		+= 	Lib/Source/DrvUART.c


#============================================================
# Path of Libraries
#============================================================
LIB_DIR		:=


#============================================================
# Name of Libraries
#============================================================
LIB_NAME	:= gcc


#============================================================
# Convert Object & Denpendency file lists from Source Lists
# Add compiler option(-L, -l)
# (Must be Located at last line)
#============================================================
INCS		:=	$(addprefix -I , $(INC_PATH))
OBJS		:=	$(addprefix $(OBJ_DIR)/, $(ASRC:.S=.o))
OBJS		+=	$(addprefix $(OBJ_DIR)/, $(CSRC:.c=.o))
DEPS		:=	$(addprefix $(DEF_DIR)/, $(ASRC:.S=.d))
DEPS		+=	$(addprefix $(DEF_DIR)/, $(CSRC:.c=.d))
LIB_DIR		:=	$(addprefix -L, $(LIB_DIR))
LIBS		:=	$(addprefix -l, $(LIB_NAME))
