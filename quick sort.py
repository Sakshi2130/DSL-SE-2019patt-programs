'''Write a python program to store first year percentage of students in array. Write function 

for sorting array of floating point numbers in ascending order using quick sort and display 

top five scores.'''

# Function to partition the array for quicksort
def partition(arr, low, high):
    pivot = arr[high]  # Choose the last element as the pivot
    i = low - 1  # Pointer for smaller element

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Swap

    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Swap pivot
    return i + 1

# Function to perform quicksort
def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)  # Partitioning index
        quicksort(arr, low, pi - 1)  # Sort elements before partition
        quicksort(arr, pi + 1, high)  # Sort elements after partition

# Function to get top five scores
def get_top_five(arr):
    return arr[-5:] if len(arr) >= 5 else arr  # Return last 5 scores (top five in ascending)

# Main program
# Example: list of first-year percentages
percentages = [76.5, 82.3, 91.4, 68.0, 89.5, 77.7, 94.2, 72.9]

# Sorting the array
quicksort(percentages, 0, len(percentages) - 1)

# Display the sorted list
print("Sorted Percentages:", percentages)

# Display the top five scores
top_five = get_top_five(percentages)
print("Top Five Scores:", top_five)
