/*
 * File:   roman.cpp
 * 
 * Enter either a Roman numeral or an integer, and convert it to
 * the other. C++ version, with an object Roman, representing the number in either 
 * format and with methods available to convert it and set it.
 * 
 * Admittedly not a task one needs to do often these days, maybe during superbowl season.
 * But this program once helped me land a job, including for good luck.  And the Java version
 * too, using a slightly different perhaps more old-fangled approach.  But practical for a relatively
 * simple exercise of this sort.
 * 
 * Author: Al Curry
 * December 2009, minor updates since
 *
 */
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdexcept>
using namespace std;

// class declaration
class Roman
{
private:
    string roman;
    int    value;
public:
   Roman();
   void SetRoman( string r );
   int convert();
   int RomanToInt();
   string IntToRoman();
   void SetValue(int result);
};


// implementation section
Roman::Roman()
{
    value = 0;
}
void Roman::SetRoman( string r )
{
    roman = r;
}

int DigitValue(char ch)
{
	switch (ch)
	{
	case 'M':
		return 1000;
		break;
	case 'D':
		return 500;
		break;
	case 'C':
		return 100;
		break;
	case 'L':
		return 50;
		break;
	case 'X':
		return 10;
		break;
	case 'V':
		return 5;
		break;
	case 'I':
		return 1;
		break;
	default:
		throw out_of_range ("Roman numerals may consist of M,D,C,L,X,V, or I");
		break;
	}

}

int Roman::RomanToInt()
{
int value = 0;

// for (char& c : roman )   range-based for loop  ?
// seems tricky to check previous or next character with it
// did it the old-fashioned way
for (string::size_type i = 0; i != roman.size(); ++i )
{

    if (i == (roman.size()-1) )
    {
           value += DigitValue(roman[i]);
    }
    else
        {
            if (DigitValue(roman[i]) >= DigitValue(roman[i+1]))
            {
               value += DigitValue(roman[i]);
            }
            else
            {
               value -= DigitValue(roman[i]);
            }
        }
}

return value;
}

string Roman::IntToRoman()
{
	int num1;

	num1 = value;
	roman = "";

while (num1 >= 1000)
	{
	    roman = roman + "M";
	    num1 -= 1000;
	}
	if (num1 >= 900)
	{
	    roman = roman + "CM";
	    num1 -= 900;
	}
	if (num1 >= 500)
	{
		roman = roman + "D";
		num1 -= 500;
	}
	if (num1 >= 400)
	{
		roman = roman + "CD";
		num1 -= 400;
	}
	while (num1 >= 100)
	{
		roman = roman + "C";
		num1 -= 100;
	}
	if (num1 >= 90)
	{
		roman = roman + "XC";
        num1 -= 90;
	}
	if (num1 >= 50)
	{
		roman = roman + "L";
		num1 -= 50;
	}
	if (num1 >= 40)
	{
		roman = roman + "XL";
		num1 -= 40;
	}
	while (num1 >= 10)
	{
		roman = roman + "X";
		num1 -= 10;
	}
	if (num1 >= 9)
	{
		roman = roman + "IX";
		num1 -= 9;
	}
	if (num1 >= 5)
	{
		roman = roman + "V";
        num1 -= 5;
	}
	if (num1 >= 4)
	{
		roman = roman + "IV";
		num1 -= 4;
	}
	while (num1 >= 1)
	{
		roman = roman + "I";
		num1 -= 1;
	}

    return roman;
}

void Roman::SetValue(int result)
{
     value = result;
}
int main()
{
   string rnum;
   string result_str;
   int inum = 0;
   int result = 0;
   Roman num1;

   while (rnum.front() != 'q')
   {
       cout << "Enter a number, Roman or integer: \n";
       cin>>rnum;
       if (rnum.front() == 'q')
    	   break;

       if (isalpha(rnum[0]))
       {
          cout << "Roman numeral : " << rnum << endl;
          num1.SetRoman( rnum );

		   try
		   {
			  result = num1.RomanToInt();
			  cout << "Integer result : " << num1.RomanToInt() << endl << endl;

			  num1.SetValue( result );
		   }
		   catch (out_of_range &err)
		   {
			  cout << err.what() << endl << endl;
		   }
	   }
       else
       {
           cout << "Integer input : " << rnum << endl;
           //inum = stoi(rnum);
           inum = atoi(rnum.c_str());
           num1.SetValue( inum );

		   try
		   {
			  result_str = num1.IntToRoman();
  			  cout << "Roman result : " << result_str << endl << endl;
			  num1.SetRoman( result_str );
		   }
		   catch (out_of_range &err)
		   {
			  cout << err.what() << endl << endl;
		   }
       }

   }
   cout << "Done.";
}



