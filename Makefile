TARGET := ijatim
BASEROM := ijatim_base.z64
BUILD_DIR := build

CROSS_COMPILE := mips-linux-gnu-
AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)ld
OBJCOPY := $(CROSS_COMPILE)objcopy

TOOLS_DIR   := tools
CC_272_DIR  := $(TOOLS_DIR)/gcc-2.7.2
CC_281_DIR  := $(TOOLS_DIR)/gcc-2.8.1

CC_272      := $(CC_272_DIR)/gcc
CC_281      := $(CC_281_DIR)/gcc

# Default compiler and prefix for generic C files
CC          := $(CC_272)
CC_DIR      := $(CC_272_DIR)

# Target-specific compiler override for 6C50.c
$(BUILD_DIR)/src/6C50.o: CC := $(CC_281)
$(BUILD_DIR)/src/6C50.o: CC_DIR := $(CC_281_DIR)
$(BUILD_DIR)/src/67A0.o: CC := $(CC_281)
$(BUILD_DIR)/src/67A0.o: CC_DIR := $(CC_281_DIR)

ASFLAGS := -march=vr4300 -mabi=32 -no-pad-sections -I . -I include
CFLAGS := -O2 -mips2 -mgp32 -mfp32 -G 0 -fno-pic -mno-abicalls -I include
LDFLAGS := -T indianajones.ld -Map $(BUILD_DIR)/$(TARGET).map --no-check-sections

C_SRCS := $(wildcard src/*.c)
ASM_SRCS := $(wildcard asm/*.s)
BIN_SRCS := $(wildcard assets/*.bin)

OBJS := $(C_SRCS:src/%.c=$(BUILD_DIR)/src/%.o) \
        $(ASM_SRCS:asm/%.s=$(BUILD_DIR)/asm/%.o) \
        $(BIN_SRCS:assets/%.bin=$(BUILD_DIR)/assets/%.o)

# Default Rule
all: $(BUILD_DIR)/$(TARGET).z64

# Toolchain download rules
$(CC_272):
	@echo "Fetching GCC 2.7.2 toolchain..."
	mkdir -p $(CC_272_DIR)
	curl -L https://github.com/decompals/mips-gcc-2.7.2/releases/download/v0.1/gcc-2.7.2-linux.tar.gz -o $(TOOLS_DIR)/gcc-2.7.2.tar.gz
	tar -xzf $(TOOLS_DIR)/gcc-2.7.2.tar.gz -C $(CC_272_DIR)
	rm $(TOOLS_DIR)/gcc-2.7.2.tar.gz

$(CC_281):
	@echo "Fetching GCC 2.8.1 toolchain..."
	mkdir -p $(CC_281_DIR)
	curl -L https://github.com/decompals/old-gcc/releases/download/0.17/gcc-2.8.1.tar.gz -o $(TOOLS_DIR)/gcc-2.8.1.tar.gz
	tar -xzf $(TOOLS_DIR)/gcc-2.8.1.tar.gz -C $(CC_281_DIR)
	rm $(TOOLS_DIR)/gcc-2.8.1.tar.gz

$(BUILD_DIR)/asm/%.o: asm/%.s | $(CC)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) include/macro.inc $< -o $@

$(BUILD_DIR)/assets/%.o: assets/%.bin
	@mkdir -p $(dir $@)
	$(LD) -r -b binary $< -o $@

$(BUILD_DIR)/src/%.o: src/%.c | $(CC_272) $(CC_281)
	@mkdir -p $(dir $@)
	$(CC) -B $(CC_DIR)/ $(CFLAGS) -S $< -o $(BUILD_DIR)/src/$*.s
	@sed -i -e '/\.reg/d' $(BUILD_DIR)/src/$*.s
	$(AS) $(ASFLAGS) include/macro.inc $(BUILD_DIR)/src/$*.s -o $@

$(BUILD_DIR)/undefined_syms.ld: symbol_addrs.txt
	@mkdir -p $(BUILD_DIR)
	@sed -E 's|//.*||; /^[[:space:]]*$$/d' $< > $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJS) $(BUILD_DIR)/undefined_syms.ld
	$(LD) $(LDFLAGS) -T $(BUILD_DIR)/undefined_syms.ld -o $@

$(BUILD_DIR)/$(TARGET).z64: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary
	@echo "--------------------------------------------------------"
	@echo "Build completed! Checking ROM match integrity..."
	@sha1sum -c checksum.sha1
	@echo "--------------------------------------------------------"

setup:
	python3 -m splat split indianajones.yaml
clean:
	rm -rf $(BUILD_DIR)

distclean:
	rm -rf asm/ assets/ build/ include/include_asm.h include/labels.inc include/macro.inc indianajones.d indianajones.ld undefined_funcs_auto.txt undefined_syms_auto.txt

.PHONY: all clean

