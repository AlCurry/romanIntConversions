/*
 *  Author: Al Curry
 *  December 2009 
 * 
 * Enter either a Roman numeral or an integer, and convert it to the other.
 * 
 * The Java version, using a slightly different perhaps more old-fangled approach.  
 * But practical for a relatively simple exercise.  
 *
 * Thanks to stack overflow for the one line isNumeric function, nice to use a 
 * regular expression and less overhead and time than rustling up the StringUtils library.
 * 
 */
package roman;


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Roman {

    public static void main(String args[]) throws IOException {

        //Console c = System.console();
        BufferedReader bi = new BufferedReader(new InputStreamReader(System.in));

        int result;
        String romanResult;
        boolean convertAnother = true;

        while (convertAnother) {

            System.out.println("Enter a number, Roman or integer (q to quit): ");
            String rnum = bi.readLine();

            if (!rnum.equals("q")) {
                System.out.println("Number to convert is " + rnum);
                if (isNumeric(rnum)) {
                    romanResult = intToRoman(rnum);
                    System.out.println("Result is " + romanResult);
                } else {
                    result = romanToInt(rnum);
                    System.out.println("Result is " + result);
                }
            } else {
                convertAnother = false;
            }

        }
        bi.close();
        System.out.println("Program exited.");
    }

    public static int romanToInt(String roman_str) {

        int[] val = new int[]{1000, 500, 100, 50, 10, 5, 1};
        char[] RR = new char[]{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int[] ans = new int[]{0, 0, 0, 0, 0, 0, 0};

        int i = 0, j = 0, total = 0;

        for (int s = 0; s < roman_str.length(); s++) {
            // System.out.println( roman_str.charAt( s ) );
            i = 0;
            while (i < 7) {
                if (roman_str.charAt(s) == RR[i]) {
                    ans[i] = ans[i] + val[i];
                    break;
                }
                i++;
            }
            // System.out.println( ans[0] );

            if (i != j) {
                if (i > j) // add
                {
                    total = total + ans[j];
                } else // i < j subtract
                {
                    total = total - ans[j];
                }

                ans[j] = 0;
            }

            // System.out.println(" total = " + total );
            j = i; // save the last value of i
            // this value changing indicates we have moved to a
            // new set of letters in the Roman numeral
        }

        total = total + ans[j];
        return (total);

    }

    public static String intToRoman(String roman_str) {
        
        String romanNumeral = "";
        int num1 = Integer.parseInt(roman_str);
        
        while (num1 >= 1000)
	{
	    romanNumeral = romanNumeral + "M";
	    num1 -= 1000;
	}
	if (num1 >= 900)
	{
	    romanNumeral = romanNumeral + "CM";
	    num1 -= 900;
	}
	if (num1 >= 500)
	{
		romanNumeral = romanNumeral + "D";
		num1 -= 500;
	}
	if (num1 >= 400)
	{
		romanNumeral = romanNumeral + "CD";
		num1 -= 400;
	}
	while (num1 >= 100)
	{
		romanNumeral = romanNumeral + "C";
		num1 -= 100;
	}
	if (num1 >= 90)
	{
		romanNumeral = romanNumeral + "XC";
        num1 -= 90;
	}
	if (num1 >= 50)
	{
		romanNumeral = romanNumeral + "L";
		num1 -= 50;
	}
	if (num1 >= 40)
	{
		romanNumeral = romanNumeral + "XL";
		num1 -= 40;
	}
	while (num1 >= 10)
	{
		romanNumeral = romanNumeral + "X";
		num1 -= 10;
	}
	if (num1 >= 9)
	{
		romanNumeral = romanNumeral + "IX";
		num1 -= 9;
	}
	if (num1 >= 5)
	{
		romanNumeral = romanNumeral + "V";
        num1 -= 5;
	}
	if (num1 >= 4)
	{
		romanNumeral = romanNumeral + "IV";
		num1 -= 4;
	}
	while (num1 >= 1)
	{
		romanNumeral = romanNumeral + "I";
		num1 -= 1;
	}

        return romanNumeral;
    }

    public static boolean isNumeric(String str) {
        return str.matches("-?\\d+(\\.\\d+)?");  //match a number with optional '-' and decimal.
    }
}
