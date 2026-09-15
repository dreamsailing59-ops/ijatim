TARGET := ijatim
BASEROM := ijatim_base.z64
BUILD_DIR := build

CROSS_COMPILE := mips-linux-gnu-
AS := $(CROSS_COMPILE)as
LD := $(CROSS_COMPILE)ld
OBJCOPY := $(CROSS_COMPILE)objcopy

TOOLS_DIR := tools
CC        := $(TOOLS_DIR)/gcc

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

# Automated tool chain fetcher for GCC 2.7.2
$(CC):
	@echo "--------------------------------------------------------"
	@echo "Fetching matching GCC 2.7.2 toolchain from decompals..."
	@echo "--------------------------------------------------------"
	mkdir -p $(TOOLS_DIR)
	curl -L https://github.com/decompals/mips-gcc-2.7.2/releases/download/v0.1/gcc-2.7.2-linux.tar.gz -o $(TOOLS_DIR)/gcc-2.7.2-linux.tar.gz
	tar -xzf $(TOOLS_DIR)/gcc-2.7.2-linux.tar.gz -C $(TOOLS_DIR)
	rm $(TOOLS_DIR)/gcc-2.7.2-linux.tar.gz

$(BUILD_DIR)/asm/%.o: asm/%.s | $(CC)
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) include/macro.inc $< -o $@

$(BUILD_DIR)/assets/%.o: assets/%.bin
	@mkdir -p $(dir $@)
	$(LD) -r -b binary $< -o $@

$(BUILD_DIR)/src/%.o: src/%.c | $(CC)
	@mkdir -p $(dir $@)
	$(CC) -B $(TOOLS_DIR)/ $(CFLAGS) -S $< -o $(BUILD_DIR)/src/$*.s
	@sed -i -e '/\.reg/d' $(BUILD_DIR)/src/$*.s
	$(AS) $(ASFLAGS) include/macro.inc $(BUILD_DIR)/src/$*.s -o $@

$(BUILD_DIR)/undefined_syms.ld: symbol_addrs.txt | $(BUILD_DIR)
	@mkdir -p $(BUILD_DIR)
	@sed -E 's|//.*||; /^[[:space:]]*$$/d' $< > $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJS) $(BUILD_DIR)/undefined_syms.ld
	$(LD) $(LDFLAGS) -T $(BUILD_DIR)/undefined_syms.ld -o $@

$(BUILD_DIR)/$(TARGET).z64: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $< $@ -O binary
	@echo "--------------------------------------------------------"
	@echo "Build completed! Checking ROM match integrity..."
	@sha1sum $@
	@sha1sum $(BASEROM)
	@echo "--------------------------------------------------------"

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean

