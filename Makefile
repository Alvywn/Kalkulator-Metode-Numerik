# ============================================================
# Makefile - Gauss-Jordan Calculator
# ============================================================
# Cara pakai:
#   make          → compile program
#   make run      → compile dan langsung jalankan
#   make clean    → hapus file hasil compile
# ============================================================

# Compiler dan flag
CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I include

# Nama file output (executable)
TARGET = kalkulator

# Daftar file source yang dikompilasi
SRCS = src/main.cpp \
       src/gauss_jordan.cpp \
       src/input_handler.cpp

# ---- Target utama: compile semua source ----
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	@echo "Kompilasi berhasil! Jalankan dengan: ./$(TARGET)"

# ---- Target: compile + langsung jalankan ----
run: all
	./$(TARGET)

# ---- Target: hapus file binary ----
clean:
	rm -f $(TARGET)
	@echo "File binary dihapus."

# Tandai target yang bukan nama file
.PHONY: all run clean
