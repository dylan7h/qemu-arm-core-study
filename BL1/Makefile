#============================================================
# Target Name
#============================================================
TARGET_DIR	:=	$(CURDIR)
TARGET		:=	$(notdir $(CURDIR))


#============================================================
# Include Build Environments
#============================================================
include $(CURDIR)/.props/toolchain.mk
include $(CURDIR)/.props/config.mk
include $(CURDIR)/.props/path.mk


#============================================================
# Default Make Target
#============================================================
all: $(BIN_DIR)/$(TARGET).bin $(ASM_DIR)/$(TARGET).asm
	

#============================================================
# Clean Target
#============================================================
clean:
	@printf "%-10s Product of $(TARGET)\n" "RM"
	$(V)rm -rf $(OBJ_DIR)/*
	$(V)rm -rf $(DEF_DIR)/*
	$(V)rm -rf $(ELF_DIR)/$(TARGET).$(FILE_EXT)
	$(V)rm -rf $(BIN_DIR)/$(TARGET).bin
	$(V)rm -rf $(MAP_DIR)/$(TARGET).map
	$(V)rm -rf $(ASM_DIR)/$(TARGET).asm

#============================================================
# Run Target
#============================================================
run: all
	qemu-system-arm -M realview-pb-a8 -kernel $(ELF_DIR)/$(TARGET).$(FILE_EXT)

#============================================================
# Debug Target
#============================================================
debug: all
	qemu-system-arm -M realview-pb-a8 -kernel $(ELF_DIR)/$(TARGET).$(FILE_EXT) -S -gdb tcp::1234,ipv4

#============================================================
# Link Object files --> Make ELF File
#============================================================
# -n : Section의 자동 정렬 금지
# -T : lds 파일 지정
$(ELF_DIR)/$(TARGET).$(FILE_EXT): mkdir $(DEPS) $(OBJS)
	@printf "%-10s $@\n" "LD"
	$(V)$(CC) -n -T $(LDS) -o $@ $(OBJS) $(LIB_DIR) $(LIBS) -Wl,-Map=$(MAP_DIR)/$(TARGET).map  $(LDFLAGS)


#============================================================
# Extract Binary File
#============================================================
$(BIN_DIR)/$(TARGET).bin: $(ELF_DIR)/$(TARGET).$(FILE_EXT)
	@printf "%-10s $@\n" "OC"
	$(V)$(OC) -O binary $< $@


#============================================================
# Extract Assembly File
#============================================================
$(ASM_DIR)/$(TARGET).asm: $(ELF_DIR)/$(TARGET).$(FILE_EXT)
	@printf "%-10s $@\n" "OD"
	$(V)$(OD) -d $< > $@


#============================================================
# Make Directories
#============================================================
mkdir:
	@echo check build directoies...
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEF_DIR)
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(ELF_DIR)
	@mkdir -p $(MAP_DIR)
	@mkdir -p $(ASM_DIR)


#============================================================
# Make dependency files
#============================================================
# From *.s files
$(DEF_DIR)/%.d: %.s
	@mkdir -p $(dir $@)
	$(V)$(CC) $(INCS) $(CFLAGS) -M $< > $@

# From *.c files
$(DEF_DIR)/%.d: %.c
	@mkdir -p $(dir $@)
	$(V)$(CC) $(INCS) $(CFLAGS) -M $< > $@


#============================================================
# Compile Source files
#============================================================
# From *.s files
$(OBJ_DIR)/%.o:	%.s
	@mkdir -p $(dir $@)
	@printf "%-10s $<\n" "AS"
	$(V)$(CC) $(INCS) $(CFLAGS) -c $< -o $@ -MMD -MF $(DEF_DIR)/$*.d

# From *.c files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "%-10s $<\n" "CC"
	$(V)$(CC) $(INCS) $(CFLAGS) -c $< -o $@ -MMD -MF $(DEF_DIR)/$*.d


#============================================================
# Debug Information
#============================================================
info:
	$(info INCS     : $(INCS))
	$(info LDS      : $(LDS))
	$(info ASRC     : $(ASRC))
	$(info CSRC     : $(CSRC))
	$(info OBJS     : $(OBJS))
	$(info DEPS     : $(DEPS))
	$(info LIB_DIR  : $(LIB_DIR))
	$(info LIBS     : $(LIBS))
	$(info AFLAGS   : $(AFLAGS))
	$(info CFLAGS   : $(CFLAGS))
	$(info LDFLAGS  : $(LDFLAGS))
