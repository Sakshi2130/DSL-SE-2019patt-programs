'''In second year computer engineering class, group A student’s play cricket, group B 

students play badminton and group C students play football. 

Write a Python program using functions to compute following: -

a) List of students who play both cricket and badminton 

b) List of students who play either cricket or badminton but not both 

c) Number of students who play neither cricket nor badminton

d) Number of students who play cricket and football but not badminton.

(Note- While realizing the group, duplicate entries should be avoided, Do not use SET 

built-in functions)'''
# Define lists of students for each group
group_a = ["Aman", "Bhavesh", "Chirag", "Dinesh"]  # Cricket players
group_b = ["Bhavesh", "Esha", "Farhan", "Gaurav"]  # Badminton players
group_c = ["Aman", "Dinesh", "Heena", "Ishita"]    # Football players


def cricket_and_badminton(cricket, badminton):
    common = []
    for student in cricket:
        if student in badminton:
            if student not in common:  # Avoid duplicates
                common.append(student)
    return common

# Function to find students who play either cricket or badminton but not both
def either_cricket_or_badminton(cricket, badminton):
    either = []
    for student in cricket:
        if student not in badminton:
            if student not in either:
                either.append(student)
    for student in badminton:
        if student not in cricket:
            if student not in either:
                either.append(student)
    return either

# Function to count students who play neither cricket nor badminton
def neither_cricket_nor_badminton(all_students, cricket, badminton):
    neither = []
    for student in all_students:
        if student not in cricket and student not in badminton:
            neither.append(student)
    return len(neither)

# Function to count students who play cricket and football but not badminton
def cricket_and_football_not_badminton(cricket, football, badminton):
    count = 0
    for student in cricket:
        if student in football and student not in badminton:
            count += 1
    return count

# All students in the class
all_students = ["Aman", "Bhavesh", "Chirag", "Dinesh", "Esha", "Farhan", "Gaurav", "Heena", "Ishita"]

# Calling each function and printing results
print("a) Students who play both cricket and badminton:", cricket_and_badminton(group_a, group_b))
print("b) Students who play either cricket or badminton but not both:", either_cricket_or_badminton(group_a, group_b))
print("c) Number of students who play neither cricket nor badminton:", neither_cricket_nor_badminton(all_students, group_a, group_b))
print("d) Number of students who play cricket and football but not badminton:", cricket_and_football_not_badminton(group_a, group_c, group_b))
