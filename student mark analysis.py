'''Write a Python program to store marks scored in subject “Fundamental of Data 

Structure” by N students in the class. Write functions to compute following:

a) The average score of class 

b) Highest score and lowest score of class 

c) Count of students who were absent for the test

d) Display mark with highest frequency
'''

# Function to calculate the average score of the class
def calculate_average(marks):
    total = sum(mark for mark in marks if mark is not None)
    count = sum(1 for mark in marks if mark is not None)
    return total / count if count != 0 else 0

# Function to find the highest and lowest scores
def find_highest_lowest(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    highest = max(valid_marks) if valid_marks else None
    lowest = min(valid_marks) if valid_marks else None
    return highest, lowest

# Function to count the number of students who were absent
def count_absent(marks):
    return marks.count(None)

# Function to find the mark with the highest frequency
def highest_frequency_mark(marks):
    valid_marks = [mark for mark in marks if mark is not None]
    if not valid_marks:
        return None
    frequency = {}
    for mark in valid_marks:
        frequency[mark] = frequency.get(mark, 0) + 1
    highest_freq_mark = max(frequency, key=frequency.get)
    return highest_freq_mark, frequency[highest_freq_mark]

# Main code
marks = [85, 90, None, 76, 85, 90, 92, None, 90, 88]  # Example marks list

# Displaying results
average_score = calculate_average(marks)
highest, lowest = find_highest_lowest(marks)
absent_count = count_absent(marks)
highest_freq_mark, freq = highest_frequency_mark(marks)

print("Average score of class:", average_score)
print("Highest score:", highest)
print("Lowest score:", lowest)
print("Number of absentees:", absent_count)
print("Mark with highest frequency:", highest_freq_mark, "(Frequency:", freq, ")")
