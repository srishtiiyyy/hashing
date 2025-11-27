import java.util.*;

/*
Question 4

Given a string (which may contain multiple spaces), you must:

1. Extract each word (ignore extra spaces).

2. For every word, create a 2-letter combination made of:
       - first character of the word
       - last character of the word
   Example: "hello" → "ho"

3. Count the frequency of each combination.

4. Return the combination(s) with the highest frequency,
   while maintaining the ORIGINAL order of appearance (NO reordering!).

Example:

Input:
"   hello   hi   hey   halo   hi   "

Words → hello, hi, hey, halo, hi  
Combinations → ho, hi, hy, ho, hi

Frequencies:
ho → 2  
hi → 2  
hy → 1  

Highest frequency = 2  
Original order appearance of max freq → ho, hi  

Output:
["ho", "hi"]
*/

public class highfreq {

    public static List<String> topCombinations(String s) {
        // Step 1: split words + ignore extra spaces
        String[] words = s.trim().split("\\s+");

        // Step 2 & 3: map combination → frequency
        Map<String, Integer> freq = new HashMap<>();
        List<String> order = new ArrayList<>();

        for (String w : words) {
            if (w.length() == 0) continue;
            String comb = "" + w.charAt(0) + w.charAt(w.length() - 1);

            freq.put(comb, freq.getOrDefault(comb, 0) + 1);

            // Maintain first appearance order
            if (!order.contains(comb)) {
                order.add(comb);
            }
        }

        // Step 4: Find the highest frequency
        int maxFreq = Collections.max(freq.values());

        // Collect combinations in original order
        List<String> result = new ArrayList<>();
        for (String comb : order) {
            if (freq.get(comb) == maxFreq) {
                result.add(comb);
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();

        List<String> ans = topCombinations(input);
        System.out.println(ans);
        
        sc.close();
    }
}
