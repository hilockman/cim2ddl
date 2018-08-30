#include <ilog.h>
#include <stdio.h> 
#include <stdarg.h>
#include <iostream>
using namespace std;

void function(const char *format, ...) {
	va_list va_para_list;
	va_start(va_para_list, format);
	vprintf(format, va_para_list);
	va_end(va_para_list);
}

void function1(const char *format, ...) {
	cout << "function1 :";
	va_list va_para_list;
	va_start(va_para_list, format);
	function(format, va_para_list);
	va_end(va_para_list);
}

int FindMax(int n, ...) {
	int i, val, largest;
	va_list vl;
	va_start(vl, n);
	largest = va_arg(vl, int);
	for (i = 1; i < n; i++) {
		val = va_arg(vl, int);
		largest = (largest > val) ? largest : val;
	}
	va_end(vl);
	return largest;
}
int main(int argv, char ** argc) {
	printf("test %d\n", 8);
	function("test print %d %s %d\n", 100, "string", 55);
	function1("test print %d %s %d\n", 100, "string", 55);

	int m;
	m = FindMax(7, 702, 422, 631, 834, 892, 104, 772);

	log_reg(argv, argc);
	for (int i = 0; i < 10; i++) {
		log_error("log %i", i);
	}
	return 0;

}