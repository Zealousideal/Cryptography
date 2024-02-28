#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void encryption_Shift_cipher(char *plaintext, int key)
{
    int i = 0;
    int cypherval;
    char cypher;

    while (plaintext[i] != '\0' && (strlen(plaintext) - 1) > i)
    {
        if (plaintext[i] != ' ')
        { // Excluding whitespaces
            if (islower(plaintext[i]))
            {
                cypherval = ((((int)plaintext[i] - 97) + key) % 26) + 97;
                cypher = (char)cypherval;
            }

            else if (isupper(plaintext[i]))
            {
                cypherval = ((((int)plaintext[i] - 65) + key) % 26) + 65;
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

void decryption_Shift_cipher(char *plaintext, int key)
{
    int i = 0;
    int cypherval;
    char cypher;

    while (plaintext[i] != '\0' && (strlen(plaintext) - 1) > i)
    {
        if (plaintext[i] != ' ')
        { // Excluding whitespaces

            if (islower(plaintext[i]))
            {
                cypherval = ((((int)plaintext[i] - 97) - key) % 26);
                if (cypherval < 0)
                    cypherval += 26; // Ensure positive value
                cypher = (char)(cypherval + 97);
            }

            else if (isupper(plaintext[i]))
            {
                cypherval = ((((int)plaintext[i] - 65) - key) % 26);
                if (cypherval < 0)
                    cypherval += 26; // Ensure positive value
                cypher = (char)(cypherval + 65);
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
    int key = 1;
    char plaintext[101]; // This will contain the plaintext
    char ciphertext[101];
    printf("Enter the plaintext:\n");
    fgets(plaintext, sizeof(plaintext), stdin); // Input the plaintext

    printf("The ciphertext is:\n");
    encryption_Shift_cipher(plaintext, key);

    printf("Enter the ciphertext:\n");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    printf("The plaintext is: \n");
    decryption_Shift_cipher(ciphertext, key);

    return 0;
}
