Copyright (C) 2015  Nupur Malpani
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
----------------------------------------------
Title :- Data Compression
-----------------------------------------------
Name: Nupur Malpani
MISID:111303028
------------------------------------------------

------------------------------------------------
Description of the Project:-
------------------------------------------------

Summary:
I have selected the project of lossless Data compression.It is the technique of reducing number of bits required to store or transmit data.Below are two ways through which this could be done :-

1) Huffman Coding(Static Dictionary Based Approach):- It is optimal prefix code that is commonly used for lossless data compression.I have used variable length coding for this type.It derives a table from frequency of occurence for each possible value of source symbol.For this it needs to traverese the complete file once if the probability is not given.It also needs to transmit the dictionary created along with the comperessed file,so for small files with less redundancy the compressed file may have greater size than the original file .A binary trie to recreate the table will be used. 

2) Lempel-Ziv-Welch (Adaptive Dictionary Based Approach):- LZW compression is a adaptive table based lookup algorithm.The compression and the decompression program independently builds a dictionary and therefore there is no need to transmit the dictionary.

Setup:
*Copy the Zip file to your local machine.
ex:- C:\111303028_miniproject_dsa.tar.gz
*Decompress the .zip file in the previous step 
ex:- C:\111303028_miniproject_dsa
*Create the excutable file project using the make file in the previous step.
* Open terminal and type './project' and choose the appropriate option accordingly.

Implementation:
Below algorithms are implemented only for '.txt' file:-

1)  Huffman Coding(Static Dictionary Based Approach):- I have used a binary tree to create prefix code of each character used and store them in a table . I have used a bit library given by Mark Nelson to encode the prefix codes in a file.The table is transmitted along with the compressed file.

2)  Lempel-Ziv-Welch (Adaptive Dictionary Based Approach):- 0 to 255 values are used to represent the 256 ASCII values and further values are used to store patterns.I have created bit library according to the needs of the project.Because codes ending with 'FF' in hexadecimal is considered as end of file I have skipped them also the program intially uses 16-bit to store a given pattern and if the value > 65535 than 65535 is written to the file to show that 24 bits are to be read now on and no corresponding value is created for 65535. trie structure made using linked list is used to store the key and value pairs of the compression dictionary in order to save space and time.The decompressor uses array based trie for building the dictionary.

