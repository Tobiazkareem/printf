Write a function that produces output according to a format.

Prototype: int _printf(const char *format, ...);
Returns: the number of characters printed (excluding the null byte used to end output to strings)
write output to stdout, the standard output stream
format is a character string. The format string is composed of zero or more directives. See man 3 printf for more detail. You need to handle the following conversion specifiers:
c
s
%
You don’t have to reproduce the buffer handling of the C library printf function
You don’t have to handle the flag characters
You don’t have to handle field width
You don’t have to handle precision
You don’t have to handle the length modifiers
Task 0
Write a function that produces output according to a format.
Task 1
Handle the conversion specifiers
Task 2
Handling custom conversion specifier b
Task 3
Handling conversion specifier u, o, x, X
Task 4
Use a local buffer 1024 to call write as little as possible
Task 5
Handle custom conversion specifier s
Task 6
Handle conversion specifier p 
