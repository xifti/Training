#include <iostream>


// Программа принимает строку (в С стиле) и делает все большие буквы маленькими в этой строке.


void to_lower(char* s)
{
	while ( * s != '\0')
	{
		if (*s > 64 && *s < 91) {
			*s += 32;
		}
		++s;
	}
	return;
}


int main()
{
	char str[102] = "";
	printf("Enter line (max size 101 char): ");
	fgets(str, 102, stdin);


	to_lower(&str[0]);
	printf(str);

	return 0;
}