# Longest Substring Without Repeating Characters

![Problem Statement](https://github.com/user-attachments/assets/3cfe648b-cff6-48f8-bf0b-a49df053c0cf)

## Solution ✅ (Sliding Window Approach)

![Solution Part 1](https://github.com/user-attachments/assets/19d67687-da7c-4eb8-b785-ed9f9576e083)

![Solution Part 2](https://github.com/user-attachments/assets/697e107d-1535-4e59-a303-cd336439271e)

## C++ Code
```cpp
#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int left = 0, maxLength = 0;

    for (int right = 0; right < s.length(); right++) {
        // If duplicate character is found, move left pointer to remove it
        while (charSet.find(s[right]) != charSet.end()) {
            charSet.erase(s[left]); // Remove character from set
            left++; // Move left pointer
        }

        // Add new character to set
        charSet.insert(s[right]);

        // Update max length
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    string s = "abcabcbb";
    cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << endl;
    return 0;
}
```

## Java Code
```java

import java.util.HashSet;
import java.util.Scanner;



public class Main {


    public static int longestSubstringWithoutRepeating(String s) {
        int left = 0;
        int maxLength = 0;
        HashSet<Character> charSet = new HashSet<>();

        for (int right = 0; right < s.length(); right++) {
            while (charSet.contains(s.charAt(right))) {
                charSet.remove(s.charAt(left));
                left++;
            }

            charSet.add(s.charAt(right));
            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter any string: ");
        String s = sc.nextLine();
        System.out.println("Longest substring without repeating is: "+longestSubstringWithoutRepeating(s));

    }
}

```
