/* 
// 
//   Name: Mohammad Minarul Islam Shawon
//   Student ID: V00901650
//   Date: September 16, 2019   
//
//   Overview:  This program takes the alphabets to be used, a message
//              and a key from the user as an input and then the 
//              message is encrypted and decrypted
//
*/ 

#include <iostream>
#include <string>
#include <cctype>


int main()
{
    int index {0}, index_2 {0}, sum {0}, sum_2 {0};// initializing my variables

    std::string extended_string {};// for storing my key

    std::string alphabet {};
    std::string message {};
    std::string key {};

    //Read each of the alphabet, message and key (in that order).
    std::cout << "Alphabets:    ";
    std::getline(std::cin, alphabet);

    std::cout << "The Message:  ";
    std::getline(std::cin, message);

    std::cout << "The key:  " ;
    std::getline(std::cin, key);

    //Now prints out the three input strings
    std::cout << "Alphabet: [" << alphabet << "]" << std::endl;
    std::cout << "Message:  [" << message << "]" << std::endl;
    std::cout << "Key:  [" << key << "]" << std::endl;

    std::string encrypted {};
    std::string decrypted {};

    /* The code for encryption and decryption */

    int length_message= message.length();
    int length_key= key.length();

    for(int i=0; i< length_message; i++)
    {
        extended_string += key.at(i % length_key);
    }

    for(int i=0; i < length_message; i++)
    {
        for(unsigned int j=0; j<alphabet.length();j++)
        {
            if(alphabet.at(j)==message.at(i))
            {
                index=j;
            }
            if(alphabet.at(j)==extended_string.at(i))
            {
                index_2=j;
            }
        }// end of second loop

        // Calculations for encrypted data //

        sum = index + index_2;
        sum = sum%alphabet.length();

        encrypted += alphabet.at(sum);

        // Calculations for decrypted data //

        sum_2 = index - index_2;

        if( sum_2 < 0)
        {
            decrypted += alphabet.at(sum_2 + alphabet.length());
        }

        else
        {
            decrypted += alphabet.at(sum_2);
        }
        

    }// end of first loop


    /* Once both results have been computed, print them out in the format specified in the assignment */
    std::cout << "Encrypted:    [" << encrypted << "]" << std::endl;
    std::cout << "Decrypted:    [" << decrypted << "]" << std::endl;

    return 0;
}
