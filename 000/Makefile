# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -I/home/docker/mpfrxx/i/GMP-6.3.0/include/ -I/home/docker/mpfrxx/i/MPFR-4.2.2/include/
LDFLAGS = -L/home/docker/mpfrxx/i/MPFR-4.2.2/lib -lmpfr -L/home/docker/mpfrxx/i/GMP-6.3.0/lib -lgmp
RPATH_FLAGS = -Wl,-rpath,/home/docker/mpfrxx/i/GMP-6.3.0/lib -Wl,-rpath,/home/docker/mpfrxx/i/MPFR-4.2.2/lib

# Target executable
TARGET = boost_mpfr_sample

# Source files
SOURCES = boost_mpfr_sample.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Install dependencies (Ubuntu/Debian)
install-deps:
	sudo apt-get update
	sudo apt-get install -y libboost-dev libmpfr-dev libgmp-dev build-essential

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help target
help:
	@echo "Available targets:"
	@echo "  all          - Build the program (default)"
	@echo "  clean        - Remove build files"
	@echo "  install-deps - Install required dependencies"
	@echo "  run          - Build and run the program"
	@echo "  help         - Show this help message"

# Phony targets
.PHONY: all clean install-deps run help
