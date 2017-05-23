TARGET = projectile

all: $(TARGET)

$(TARGET): $(TARGET).cpp
	g++ -Wall -Wextra -O2 $(TARGET).cpp -o $(TARGET)

.PHONY: tar
tar:
	@tar -cvJf $(TARGET).tar.xz makefile $(TARGET).cpp

