all:
	g++ main.cpp \
	compare_strings.cpp \
	make_arr_and_ptr_arr.cpp \
	print.cpp \
	sort_strings.cpp \
	-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef \
    -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations \
    -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain \
    -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion \
    -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 \
    -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers \
    -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo \
    -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel \
    -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE -o run



# all: program
#
# program: main.o compare_strings.o make_arr_and_ptr_arr.o print.o sort_strings.o
#     g++ -Wall -std=c++17 main.o compare_strings.o make_arr_and_ptr_arr.o print.o sort_strings.o -o program
#
# main.o: main.cpp
#     g++ -Wall -std=c++17 -c main.cpp -o main.o
#
# compare_strings.o: compare_strings.cpp
#     g++ -Wall -std=c++17 -c compare_strings.cpp -o compare_strings.o
#
# make_arr_and_ptr_arr.o: make_arr_and_ptr_arr.cpp
#     g++ -Wall -std=c++17 -c make_arr_and_ptr_arr.cpp -o make_arr_and_ptr_arr.o
#
# print.o: print.cpp
#     g++ -Wall -std=c++17 -c print.cpp -o print.o
#
# sort_strings.o: sort_strings.cpp
#     g++ -Wall -std=c++17 -c sort_strings.cpp -o sort_strings.o
#
# clean:
#     rm -f *.o program
