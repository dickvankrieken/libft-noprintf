#include <stdio.h>
#include <unistd.h>

int main()
{
	int a = 100;
	char c = 'c';
	char d = 'd';

	char *string = "hello world";
	char *string2 = "bye world";
	char *pointer = string;
	char **ppointer = &pointer;

    /* character conversions */
    printf("1: width van 10 op een char(%%.-3s) >%.-3s<\n", string);

/*    printf("2: precision van 3 op een char(%%.3c) >%.3c<\n", c); */
/*********************************************************************************************************************************/
/* /\* printfpractice.c:16:53: warning: precision used with 'c' conversion specifier, resulting in undefined behavior [-Wformat] */
/*     printf("2: precision van 3 op een char(%%.3c) >%.3c<\n", c);								 */
/*                                                    ~^~~									 */
/*  1 warning generated. *\/													 */
/*********************************************************************************************************************************/

    printf("written bytes: %i\n", printf("3: precision van 3 met een min (%%*c) met 3 voor asterisk >%*c<\n", -3, c));


/* 2 field width*/
    printf("4. width met een integer voor een string (%%5s): %5s\n", string);
}



/****************************************************************************************************************************************/
/*     printf("width met een integer voor een integer (%%5s): %5i\n", a);							        */
/* 																        */
/*     printf("width met een ster (*) (%%*s, 5, string)): %*s\n", 5, string);							        */
/* 																        */
/*     /\* 3 precisie*\/													        */
/*     printf("3: %.*s\n", 12, string);												        */
/*     /\* 4 verschillende conversie specifiers *\/										        */
/*     printf("4: %12.12s\n", string);												        */
/*     /\* 5 *\/														        */
/*     printf("5: %12.*s\n", 3, string);											        */
/*     /\* 6 *\/ printf("6: dit is de waarde van de pointer genaamd string: %p\n", string);					        */
/*     /\* 7 *\/ printf("7: dit is het adres van de pointer genaamd pointer die de waarde heeft van string: %p\n", pointer);	        */
/*     /\* 8 *\/ printf("7: dit is het adres van een andere pointer genaamd ppointer die de waarde heeft van pointer: %p\n", ppointer); */
/*     /\* pointer en string hebben blijkbaar hetzelfde adres									        */
/*     het zijn verschillende pointers maar ze hebben hetzelfde adres...*\/							        */
/*     /\* 5 *\/  printf("5: %i\n", a);												        */
/* 																        */
/* }																        */
/****************************************************************************************************************************************/
