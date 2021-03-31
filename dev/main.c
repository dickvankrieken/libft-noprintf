#include "includes/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main()
{
    int a = 100;
    char c = 'e';
    char d = 'd';

    char *string = "hello world";
    char *pointer = string;
    char **ppointer = &pointer;

    /* 1 min of nul */
	ft_printf("1: ft_printf:\nstring >>>%-017s<<<\n", string);
	printf("1: printf:\nstring >>>%-017s<<<\n", string);
	ft_printf("\n");

	ft_printf("2: ft_printf:\nstring: >>>%017s<<<\n", string);
	printf("2: print:\nstring: >>>%017s<<<\n", string);
	ft_printf("\n");

	ft_printf("3: ft_printf:\nstring: >>>%-4.6s<<<\n", string);
	printf("3: print:\nstring: >>>%-4.6s<<<\n", string);
	ft_printf("\n");

	ft_printf("4: ft_printf:\ncharacter: >>>%c<<<\n", c);
	ft_printf("4: printf:\ncharacter: >>>%c<<<\n", c);
	ft_printf("\n");

	ft_printf("5: ft_printf:\nstring: >>>%s<<<\ndigit:|%.*d|\n", string, -9, a);
	ft_printf("5: ft_printf:\nstring: >>>%s<<<\ndigit:|%.*d|\n", string, -9, a);

/****************************************************************************************************************************************/
    /* ft_printf("2: 5s: >%5s<\n", string);												    */
    /* ft_printf("3: .* met een 3: >%.*s<\n", 3, string);										    */
    /* /\* 2 field width*\/														    */
    /* ft_printf("4: 30s: %30s\n", string);												    */
    /* ft_printf("5: 5i: %5i\n", a);													    */
    /* 																	    */
    /* ft_printf("6: (%%*s, 5, string)): %*s\n", 5, string);										    */
    /* 																	    */
    /* /\* 3 precisie*\/														    */
    /* ft_printf("7: %.*s\n", 12, string);												    */
    /* /\* 4 verschillende conversie specifiers *\/											    */
    /* ft_printf("8: %12.12s\n", string);												    */
    /* /\* 5 *\/															    */
    /* ft_printf("9: %12.*s\n", 3, string);												    */
    /* /\* 6 *\/ ft_printf("10: dit is de waarde van de pointer genaamd string: %p\n", string);						    */
    /* /\* 7 *\/ ft_printf("11: dit is het adres van de pointer genaamd pointer die de waarde heeft van string: %p\n", pointer);	    */
    /* /\* 8 *\/ ft_printf("12: dit is het adres van een andere pointer genaamd ppointer die de waarde heeft van pointer: %p\n", ppointer); */
    /* /\* pointer en string hebben blijkbaar hetzelfde adres										    */
    /* het zijn verschillende pointers maar ze hebben hetzelfde adres...*\/								    */
    /* /\* 5 *\/  ft_printf("13: %i\n", a);												    */
    /****************************************************************************************************************************************/

}
