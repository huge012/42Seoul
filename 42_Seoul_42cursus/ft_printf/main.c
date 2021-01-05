#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("%s\n", "");
	printf("%s\n", "");
	fflush(stdout);
	ft_printf("%s, %s!\n", "Hello", "world");
	ft_printf("%0d\n", 100);		//100
	printf("%s, %s!\n", "Hello", "world");
	fflush(stdout);
	printf("%0d\n", 100);		//100
	fflush(stdout);
	ft_printf("%09.5d\n", 100);		//    00100
	ft_printf("%09d\n", 100);		//000000100
	ft_printf("%9.5d\n", 100);		//    00100
	ft_printf("%9.*d\n", 5, 100);		//    00100
	ft_printf("%09.5d\n", -100);		//   -00100
	ft_printf("%09d\n", -100);		//-00000100
	ft_printf("%9.5d\n", -100);		//   -00100
	ft_printf("%9.*d\n", 5, -100);		//   -00100
	printf("===\n");
	fflush(stdout);
	ft_printf("%*.*d\n", 9,  5, -100);	//   -00100
	printf("%*.*d\n", 9,  5, -100);		//   -00100
	fflush(stdout);
	printf("===\n");
	fflush(stdout);
	ft_printf("%*.*d\n", 5,  5, -100);	//   -00100
	printf("%*.*d\n", 5,  5, -100);		//   -00100
	fflush(stdout);
	printf("-------\n");
	fflush(stdout);
	ft_printf("return = %d\n", ft_printf("%%d%-d\n", 0));	//%d0
	printf("return = %d\n", printf("%%d%-d\n", 0));	//%d0
	fflush(stdout);
	printf("-------\n");    //%d+0
	fflush(stdout);
	printf("%d\n",printf("%d %c\n", 50, -1));
	fflush(stdout);
	ft_printf("%d\n",printf("%d %c\n", 50, -1));
	printf("-------\n");  
	fflush(stdout);
	printf("%d\n",printf("%c %d\n", 128, 50));
	fflush(stdout);
	ft_printf("%d\n",printf("%c %d\n", 128, 50));
	printf("-------\n");    
	fflush(stdout);
	printf("%d\n",printf("|%20c|\n", 'a'));
	fflush(stdout);
	ft_printf("%d\n",ft_printf("|%20c|\n", 'a'));
	printf("-------\n");
	fflush(stdout);
	printf("%-5c\n", 'a');
	fflush(stdout);
	ft_printf("%-5c\n", 'a');
	printf("-------\n");
	fflush(stdout);	
	printf("%5c\n", 'a');
	fflush(stdout);
	ft_printf("%5c\n", 'a');
}
