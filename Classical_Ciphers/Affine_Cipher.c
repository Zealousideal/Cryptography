#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int key_a, key_b, a_inv;

void gen_key()
{
    char coprimes[] = {3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
    char inverses[] = {9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

    int index = rand() % 11;

    key_a = coprimes[index];
    a_inv = inverses[index];
    key_b = rand() % 26;
}

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

void decrypt_affine(char *ciphertext, int key_a, int key_b)
{
    int a_inv = 0, i = 0, plaintext_val;
    char plaintext;

    for (int j = 0; j < 26; j++)
        if (key_a != 0 && (key_a * j) % 26 == 1)
        {
            a_inv = j;
            break;
        }

    if (a_inv == 0)
    {
        printf("Invalid key_a. Modular multiplicative inverse does not exist.\n");
        return;
    }

    while (ciphertext[i] != '\0' && (strlen(ciphertext) - 1) > i)
    {
        if (ciphertext[i] != ' ')
        {
            if (islower(ciphertext[i]))
            {
                plaintext_val = ((((int)ciphertext[i] - 97 - key_b) * a_inv) % 26);
                if (plaintext_val < 0)
                    plaintext_val += 26;
                plaintext = (char)(plaintext_val + 97);
            }

            else if (isupper(ciphertext[i]))
            {
                plaintext_val = ((((int)ciphertext[i] - 65 - key_b) * a_inv) % 26);
                if (plaintext_val < 0)
                    plaintext_val += 26;
                plaintext = (char)(plaintext_val + 65);
            }

            printf("%c", plaintext);
        }

        else
            printf(" ");
        i++;
    }
    printf("\n");
}

int main()
{
    gen_key();

    char plaintext[101];
    char ciphertext[101];

    printf("Enter the plaintext: \n");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("The encrypted message is: \n");
    encrypt_affine(plaintext, key_a, key_b);

    printf("Enter the ciphertext:\n");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    printf("The plaintext is: \n");
    decrypt_affine(ciphertext, key_a, key_b);
    return 0;
}