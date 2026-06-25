#include <stdio.h>
#include <string.h>
#include "string_funcs.h"
#define MAX_SENTENCE_LENGTH 256
#define NUM_OF_TESTS 5

int main(void)
{
	int rc = 0;
	char first_sentence[MAX_SENTENCE_LENGTH] = "Wello world!";
	char second_sentence[MAX_SENTENCE_LENGTH] = "Hello world!";
	char chr = 'w';
	int mistakes = NUM_OF_TESTS;

	if (my_strpbrk(first_sentence, second_sentence) == strpbrk(first_sentence, second_sentence))
		mistakes--;

	if (my_strspn(first_sentence, second_sentence) == strspn(first_sentence, second_sentence))
		mistakes--;

	if (my_strcspn(first_sentence, second_sentence) == strcspn(first_sentence, second_sentence))
		mistakes--;

	if (my_strchr(first_sentence, chr) == strchr(first_sentence, chr))
		mistakes--;

	if (my_strrchr(first_sentence, chr) == strrchr(first_sentence, chr))
		mistakes--;

	if (mistakes != 0)
		rc = 1;

	printf("%d", mistakes);

	return rc;
}
