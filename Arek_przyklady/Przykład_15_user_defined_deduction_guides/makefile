CXX=clang++
CFLAGS  = -g -Wall -std=c++1z


SRC = $(wildcard *.cpp)


TARGET = Przyklad_15
  
all: $(TARGET)
  
$(TARGET): user_defined_deduction_guides.cpp
	$(CXX) $(CFLAGS) -o $(TARGET) user_defined_deduction_guides.cpp $(LFLAGS)

clean:
	rm $(TARGET)

class:
	read -p "Enter Class Name:" name; \
	touch $$name.cpp; \
	printf "#include \""$$name.h"\"\n" > $$name.cpp; \
	touch $$name.h; \
	printf "#ifndef "$$name"_h\n#define "$$name"_h\n\nclass "$$name"{\npublic:\n\nprivate:\n\n};\n\n\n\n#endif" > $$name.h

-include $(DEP)
