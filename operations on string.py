'''Write a Python program to compute following operations on String:

a) To display word with the longest length

b) To determines the frequency of occurrence of particular character in the string

c) To check whether given string is palindrome or not 

d) To display index of first appearance of the substring

e) To count the occurrences of each word in a given string
'''

def longest_word(string):
    words = string.split()
    longest = max(words, key=len)
    return longest

def char_frequency(string, char):
    return string.count(char)

def is_palindrome(string):
    string = string.replace(" ", "").lower()
    return string == string[::-1]

def substring_index(string, substring):
    return string.find(substring)

def word_count(string):
    words = string.split()
    word_freq = {}
    for word in words:
        word_freq[word] = word_freq.get(word, 0) + 1
    return word_freq

# Test the functions
text = input("Enter a string: ")

# a) Display word with the longest length
print("Longest word:", longest_word(text))

# b) Determine frequency of occurrence of a particular character
character = input("Enter a character to check its frequency: ")
print(f"Frequency of '{character}':", char_frequency(text, character))

# c) Check whether the given string is a palindrome
if is_palindrome(text):
    print("The string is a palindrome.")
else:
    print("The string is not a palindrome.")

# d) Display index of the first appearance of a substring
substring = input("Enter a substring to find its first appearance: ")
index = substring_index(text, substring)
if index != -1:
    print(f"The substring '{substring}' first appears at index:", index)
else:
    print(f"The substring '{substring}' is not found.")

# e) Count the occurrences of each word in the given string
print("Word occurrences:", word_count(text))
