import java.util.*;

/*
Question 3: Fruit Frequency

You are given a string S containing fruits, where each character represents 
a fruit type.

Your task:
Find and return the largest absolute difference between:
    • the count of the fruit with the MAXIMUM odd frequency, and
    • the count of the fruit with the MINIMUM even frequency.

Note:
The string contains at least one character with an odd frequency 
and at least one with an even frequency.

Input:
    A string S

Output:
    An integer → | maxOddFreq - minEvenFreq |

Example:
If S = "aabbccc"
Frequencies: a=2 (even), b=2 (even), c=3 (odd)
Max odd = 3
Min even = 2
Answer = |3 - 2| = 1
*/
public class fruitdiff {
    public static int diffi (String s){
        Map<Character,Integer>mp=new HashMap<>();
        for(char ch:s.toCharArray()){
           mp.put(ch,mp.getOrDefault(ch,0)+1);
        }
        int maxOdd = Integer.MIN_VALUE;
        int minEven = Integer.MAX_VALUE;
        for (int count : mp.values()) {
            if (count % 2 == 1) {       
                maxOdd = Math.max(maxOdd, count);
            } else {                   
                minEven = Math.min(minEven, count);
            }
        }

        return Math.abs(maxOdd - minEven);
    }
    public static void main(String[]args){
        Scanner sc=new Scanner(System.in);
        String s = sc.next();
        System.out.println(diffi(s));
        sc.close();
    }
}

