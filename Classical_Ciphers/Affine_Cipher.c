#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void encrypt_affine(char *plaintext, int key_a, int key_b)
{
    int i = 0, cypherval;
    char cypher;

    while (plaintext[i] != '\0' && (strlen(plaintext) - 1) > i)
    {
        if (plaintext[i] != ' ')
        {
            if (islower(plaintext[i]))
            {
                cypherval = (((((int)plaintext[i] - 97) * key_a) + key_b) % 26) + 97;
                cypher = (char)cypherval;
            }

            else if (isupper(plaintext[i]))
            {
                cypherval = (((((int)plaintext[i] - 65) * key_a) + key_b) % 26) + 65;
                cypher = (char)cypherval;
            }

            printf("%c", cypher);
        }

        else
            printf(" ");
        i++;
    }
    printf("\n");
}
int main()
{
    int key_a = 17, key_b = 20;
    char plaintext[101];
    char ciphertext[101];

    printf("Enter the plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("The encrypted message is: \n");
    encrypt_affine(plaintext, key_a, key_b);
    return 0;
}