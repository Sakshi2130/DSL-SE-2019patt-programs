'''Write a pythonprogram to store roll numbers of student in array who attended 

training program in random order. Write function for searching whether particular 

student attended training program or not, using Linear search and Sentinel search. '''

# Program to store roll numbers of students and search using Linear and Sentinel Search

# Sample array of roll numbers of students who attended training
roll_numbers = [101, 105, 112, 123, 132, 145, 150]

# Function to perform linear search
def linear_search(arr, target):
    for roll in arr:
        if roll == target:
            return True  # Found
    return False  # Not found

# Function to perform sentinel search
def sentinel_search(arr, target):
    # Adding a sentinel at the end of the array
    arr.append(target)
    i = 0
    
    # Searching for the target
    while arr[i] != target:
        i += 1
    
    # Remove the sentinel to restore the original array
    arr.pop()
    
    # If found within the original length, it was in the array
    return i < len(arr)

# Test the functions
roll_to_find = int(input("Enter roll number to check if student attended training: "))

# Using Linear Search
if linear_search(roll_numbers, roll_to_find):
    print("Student attended training (found using Linear Search).")
else:
    print("Student did not attend training (not found using Linear Search).")

# Using Sentinel Search
if sentinel_search(roll_numbers, roll_to_find):
    print("Student attended training (found using Sentinel Search).")
else:
    print("Student did not attend training (not found using Sentinel Search).")
