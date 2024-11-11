'''Write a pythonprogram to store first year percentage of students in array. Write function 

for sorting array of floating point numbers in ascending order using 

a) Selection Sort 

b) Bubble sort and display top five scores'''

# Function for Selection Sort
def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_index = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # Swap the found minimum element with the first element
        arr[i], arr[min_index] = arr[min_index], arr[i]

# Function for Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                # Swap if the element found is greater than the next element
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Function to display top five scores
def display_top_five(arr):
    # Sorting array in descending order to get top scores
    arr.sort(reverse=True)
    print("Top Five Scores:")
    for i in range(min(5, len(arr))):
        print(arr[i])

# Main program
percentages = [78.5, 88.0, 92.5, 69.0, 85.0, 74.5, 90.0]  # Sample percentages

# Sorting using Selection Sort
print("Sorting using Selection Sort:")
selection_sort(percentages)
print("Sorted Percentages:", percentages)
display_top_five(percentages)

# Sorting using Bubble Sort
percentages = [78.5, 88.0, 92.5, 69.0, 85.0, 74.5, 90.0]  # Reset array
print("\nSorting using Bubble Sort:")
bubble_sort(percentages)
print("Sorted Percentages:", percentages)
display_top_five(percentages)
