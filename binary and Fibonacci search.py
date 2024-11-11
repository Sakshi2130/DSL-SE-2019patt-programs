'''Write a python program to store roll numbers of student array who attended training 

program in sorted order. Write function for searching whether particular student 

attended training program or not, using Binary search and Fibonacci search'''

# Python program to store roll numbers and search if a student attended the training program

# Function to perform binary search
def binary_search(arr, x):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = left + (right - left) // 2
        # Check if x is present at mid
        if arr[mid] == x:
            return True
        # If x is greater, ignore left half
        elif arr[mid] < x:
            left = mid + 1
        # If x is smaller, ignore right half
        else:
            right = mid - 1
    return False

# Function to perform Fibonacci search
def fibonacci_search(arr, x):
    n = len(arr)
    fib_m2 = 0  # (m-2)'th Fibonacci number
    fib_m1 = 1  # (m-1)'th Fibonacci number
    fib_m = fib_m2 + fib_m1  # m'th Fibonacci number

    while fib_m < n:
        fib_m2, fib_m1 = fib_m1, fib_m
        fib_m = fib_m2 + fib_m1

    offset = -1

    while fib_m > 1:
        i = min(offset + fib_m2, n - 1)

        # If x is greater than the value at index fib_m2, cut the subarray from offset to i
        if arr[i] < x:
            fib_m = fib_m1
            fib_m1 = fib_m2
            fib_m2 = fib_m - fib_m1
            offset = i
        # If x is less than the value at index fib_m2, cut the subarray after i+1
        elif arr[i] > x:
            fib_m = fib_m2
            fib_m1 = fib_m1 - fib_m2
            fib_m2 = fib_m - fib_m1
        else:
            return True

    if fib_m1 and offset + 1 < n and arr[offset + 1] == x:
        return True

    return False

# Main code to store and search roll numbers
def main():
    # Sample sorted roll numbers of students who attended the program
    roll_numbers = [1, 3, 5, 7, 9, 11, 15, 18, 21, 25]

    # Input: roll number to search
    search_roll = int(input("Enter roll number to check if the student attended the program: "))

    # Check using binary search
    if binary_search(roll_numbers, search_roll):
        print("Student with roll number", search_roll, "attended the training program (found by Binary Search).")
    else:
        print("Student with roll number", search_roll, "did not attend the training program (not found by Binary Search).")

    # Check using Fibonacci search
    if fibonacci_search(roll_numbers, search_roll):
        print("Student with roll number", search_roll, "attended the training program (found by Fibonacci Search).")
    else:
        print("Student with roll number", search_roll, "did not attend the training program (not found by Fibonacci Search).")

# Run the main code
main()
