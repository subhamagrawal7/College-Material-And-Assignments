The program has 4 functions as follows:-
1) Encryption:- 
As it is Caesar Cipher, so it shifts the plain text by the key entered by the user in a cyclic way.

Input:
A file containing a string of lower case, uppercase letters as well as numbers and symbols called Plain Text.
An Integer between 0-25 denoting the required shift called key.

Output:
A file containing encrypted string of the Plain Text called Cipher Text. 
	 
2) Decryption:- 
As it is Caesar Cipher, so it decrypts the cipher text by shifting in reverse manner by the key entered by the user in a cyclic way.

Input:
A file containing a encrypted string of lower case, uppercase letters as well as numbers and symbols called Cipher Text.
An Integer between 0-25 denoting the required shift called key.

Output:
A file containing decrypted string of the Cipher Text called Plain Text. 

3) Brute Force Attack:-
It tries all the keys from 0-25 and prints the required Plain Text for each key.

Input:
A file containing a encrypted string of lower case, uppercase letters as well as numbers and symbols called Cipher Text.

Output:
All the Plain text for each key from 0-25.

4) Frequency Analysis Attack:-
Knowing the usual frequencies of letters in English communication, it maps one by one highest freq letter in descending order with highest frequency letter of 
the entered cipher text and try to find the plain text.

Input:
A file containing a encrypted string of lower case, uppercase letters as well as numbers and symbols called Cipher Text.

Output:
Plain text as well as encryption key.
