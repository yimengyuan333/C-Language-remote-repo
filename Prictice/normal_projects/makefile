# ============================================
# Makefile 配置文件
# 适用环境：WSL2 / Linux / macOS
# 编译器：默认使用 clang（可切换为 gcc）
# ============================================

# ---------- 编译器选择 ----------
# 如果你想用 gcc，把下面这行注释掉，取消注释 CC = gcc
CC = clang
# CC = gcc

# ---------- 编译选项 ----------
# -Wall    ：开启所有常见警告
# -Wextra  ：开启额外警告
# -g       ：生成调试信息（供 gdb/lldb 使用）
# -lm      ：链接数学库（sqrt、sin 等）
# -std=c17 ：使用 C17 标准（可根据需要改为 c99、c11）
CFLAGS = -Wall -Wextra -g -lm -std=c17

# ---------- 目标文件 ----------
# 最终生成的可执行文件名
TARGET = myprogram

# 源文件列表（将所有 .c 文件添加到这里）
SRCS = main.c utils.c

# 自动将 .c 替换为 .o，生成目标文件列表
OBJS = $(SRCS:.c=.o)

# ---------- 默认目标 ----------
# 当你只输入 `make` 时，执行的是第一个目标（all）
all: $(TARGET)

# ---------- 链接阶段 ----------
# 将所有的 .o 文件链接成最终的可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# ---------- 编译阶段 ----------
# 将每个 .c 文件编译成对应的 .o 文件
# $< 表示第一个依赖（即 .c 文件）
# $@ 表示目标文件（即 .o 文件）
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ---------- 清理目标 ----------
# 删除所有 .o 文件和可执行文件
# 用法：make clean
clean:
	rm -f $(OBJS) $(TARGET)

# ---------- 运行目标 ----------
# 编译并运行程序
# 用法：make run
run: $(TARGET)
	./$(TARGET)

# ---------- 调试目标 ----------
# 编译并启动调试器（lldb 或 gdb）
# 用法：make debug
debug: $(TARGET)
	lldb ./$(TARGET)
	# 如果使用 gdb，把上面那行改为：
	# gdb ./$(TARGET)

# ---------- 查看编译细节 ----------
# 显示当前使用的编译器和选项
# 用法：make info
info:
	@echo "编译器: $(CC)"
	@echo "编译选项: $(CFLAGS)"
	@echo "源文件: $(SRCS)"
	@echo "目标文件: $(OBJS)"
	@echo "可执行文件: $(TARGET)"

# ---------- 伪目标 ----------
# 这些目标不对应实际文件，避免冲突
.PHONY: all clean run debug info