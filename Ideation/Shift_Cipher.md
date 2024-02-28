# Implementing the `Shift Cipher` in C language

E(x) =  (m + k) mod 26

D(x) =  (c + k) mod 26

[Gets and fgets in C Programming](https://www.digitalocean.com/community/tutorials/fgets-and-gets-in-c-programming)

- use this for the knowledge of `gets()` and `fgets()`  in stdio.h

## Steps

1. Input the plaintext
2. Pass the char * plaintext to the function `encrypt(char * plaintext, int key)`
3. Suppose 'a' = 0, 'b' = 1, ... , 'z' = 25. So we take in the plaintext and add the key to each letter to get the ciphertext.
4. This will follow mod 26 group operation.
5. ASCII of 'a' = 97, 'b' = 98... . So incorporate the math to include this too

## Functions reqd

((int)letter + key) mod 26 = cipherd_val

(char)ciphered_val = '[some letter]'


## Status of the code written

- The current version of this cipher can errorlessly encrypt lowercase and uppercase letters which is the main objective of the shift cipher.

## Objective for the next version

- To include numeric and special character encryption
