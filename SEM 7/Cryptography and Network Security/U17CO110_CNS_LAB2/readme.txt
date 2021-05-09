Program 1:- 
Program 1 (Columnar Transposition Cipher) has 2 functions:-
(1) Encryption:-
We first pick a keyword for our encryption. We write the plaintext out in a grid where the number
of columns is the number of letters in the keyword. We then title each column with the respective
letter from the keyword. We take the letters in the keyword in alphabetical order, and read down 
the columns in this order.

Input: Program takes plain text or message and key as input.
Output: Program gives cipher text according to the Columnar Transposition Cipher as output.

(2) Decryption:-
Firstly, we start by writing out the keyword and the alphabetical order of the letters of the 
keyword. We must then divide the length of the ciphertext by the length of the keyword. The 
answer to this is the number of rows we need to add to the grid. We then write the ciphertext down
the first column until we reach the last row. The next letter becomes the first letter in the 
second column (by the alphabetical order of the keyword), and so on.

Input: Program takes cipher text and key as input.
Output: Programs gives corresponding plain text as output.

Program 2:-
Program 2(Rail Fence Cipher) has 2 functions:-
(1) Encryption:-
To encrypt a message using the Rail Fence Cipher, we have to write your message in zigzag lines 
across the page, and then read off each row. Firstly, we need to have a key, which for this cipher
is the number of rows you are going to have. We then start writing the letters of the plaintext 
diagonally down to the right until we reach the number of rows specified by the key. We then bounce
back up diagonally until we hit the first row again. This continues until the end of the plaintext.

Input: Program takes plain text or message and key as input.
Output: Program gives cipher text according to the Rail Fence Cipher as output.

(2) Decryption:-
The decryption process for the Rail Fence Cipher involves reconstructing the diagonal grid 
used to encrypt the message. We start writing the message, but leaving a dash in place of the
spaces yet to be occupied. Gradually, we can replace all the dashes with the corresponding letters
, and read off the plaintext from the table.

Input: Program takes cipher text and key as input.
Output: Programs gives corresponding plain text as output.

