// ============================================================================
//
//       Filename:  love-letter_mystery.cpp
//        Created:  20/09/2014
//         Author:  Ljinod
//
//    Description: James found a love letter his friend Harry has written for
//      his girlfriend. James is a prankster, so he decides to meddle with
//      the letter. He changes all the words in the letter into palindromes.
//
//      To do this, he follows 2 rules:
//      (a) He can reduce the value of a letter, e.g. he can change 'd' to 'c'
//          but he cannot change 'c' to 'd'.
//      (b) In order to form a palindrome, if he has to repeatedly reduce the
//          value of a letter, he can do it until the letter becomes 'a'. Once
//          a letter has been changed to 'a', it can no longer be changed.
//
//      Each reduction in the value of any letter is counted as a single
//      operation. Find the minimum number of operations required to convert
//      a given string into a palindrome.
//
//      Input format:
//      The first line contains an integer T, i.e., the number of test cases.
//      The next T lines will contain a string each.
//
//      Output format:
//      A single line, for each test case, containing the number of minimum
//      operations.
//
//      Constraints:
//      1 <= T <= 10
//      1 <= length of a string <= 10⁴
//      All characters are lower case English letters.
//
// ============================================================================

#define MAX_TEST_CASES 10
#define MAX_STRING_LENGTH 10000


#include <iostream>
#include <stdlib.h>
#include <string>
#include <cmath>


int main()
{
  int line_index  = 0;
  int nb_of_tests = 0;
  std::string tmp;

  do
  {
    // first line of std input
    if(!line_index)
    {
      std::getline(std::cin, tmp);
      nb_of_tests = atoi(tmp.c_str());
    }
    // test cases
    else
    {
      int test_case_length = tmp.length();
      unsigned int nb_of_operations = 0;
      for(int i=0; i<test_case_length/2; i++)
      {
        // For every loop turn I compare two chars that composed the current 
        // test case: the first and last chars at the beginning then the
        // second and the one before last, etc... until I reach the middle
        // of the string. In order to form a palindrome those char must be
        // identical and they are identical if they have the same ASCII value.
        // The conversion from char to int gives me their ASCII values. Now to
        // know how many operations are needed to make the identical I only have
        // to retreat one from the other.
        nb_of_operations += 
          std::abs(int(tmp[i]) - int(tmp[test_case_length-1-i]));
      }
      std::cout << nb_of_operations << std::endl;
    }
    
    line_index++;

  } while(line_index <= nb_of_tests && std::getline(std::cin, tmp));


  return 0;
}
