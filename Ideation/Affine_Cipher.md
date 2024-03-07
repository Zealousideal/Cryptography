# The Affine Cipher

An affine cipher is a type of monoalphabetic substitution cipher, where each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter. It's a type of substitution cipher where each letter in an alphabet is mapped to its numeric equivalent, encrypted using a simple mathematical function, and converted back to a letter. The formula used means that each letter encrypts to one other letter and back again, meaning the process is easy to reverse.

## Encryption

E(x) = (ax + b) mod m

where:

-   `E(x)` is the encrypted letter

*   `x` is the original letter (as a number, often starting from 0 or 1 for 'A' or 'a')
*   `a` and `b` are the key of the cipher (a and b must be coprime with `m`)
*   `m` is the size of the alphabet (26 for English alphabet)

## The idea behind Decryption

So affine cipher is basically

`c = a * m + b `, where `a `and `b` are the keys

When we go towards it's decryption, the equation becomes:-

`m = a^-1 (c - b)`

This `a ^ -1` exists only when;

1. A modulo M exists
2. gcd(A, M) = 1

## Decryption

Where:

-   `D(y)` is the decrypted letter
-   `y` is the encrypted letter (as a number)
-   `a^{-1}` is the modular multiplicative inverse of `a` modulo `m`
