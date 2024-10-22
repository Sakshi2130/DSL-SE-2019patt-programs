'''In second year computer engineering class, group A student’s play cricket, group B 

students play badminton and group C students play football. 

Write a Python program using functions to compute following: -

a) List of students who play both cricket and badminton 

b) List of students who play either cricket or badminton but not both 

c) Number of students who play neither cricket nor badminton

d) Number of students who play cricket and football but not badminton.

(Note- While realizing the group, duplicate entries should be avoided, Do not use SET 

built-in functions)'''
def create_group(group_name):
  """Creates a group of students."""
  group = []
  while True:
    student_name = input(f"Enter the name of a student in group {group_name} (or 'done' to finish): ")
    if student_name.lower() == "done":
      break
    group.append(student_name)
  return group

def find_common_students(group1, group2):
  """Finds students who are in both groups."""
  common_students = []
  for student in group1:
    if student in group2 and student not in common_students:
      common_students.append(student)
  return common_students

def find_either_not_both_students(group1, group2):
  """Finds students who are in either group but not both."""
  either_not_both_students = []
  for student in group1 + group2:
    if (student in group1 and student not in group2) or (student not in group1 and student in group2):
      either_not_both_students.append(student)
  return either_not_both_students

def find_neither_students(group1, group2, group3):
  """Finds students who are not in any of the groups."""
  neither_students = []
  for student in group3:
    if student not in group1 and student not in group2:
      neither_students.append(student)
  return neither_students

def find_cricket_football_not_badminton_students(group_cricket, group_football, group_badminton):
  """Finds students who play cricket and football but not badminton."""
  students = []
  for student in group_cricket:
    if student in group_football and student not in group_badminton:
      students.append(student)
  return students

# Create groups
group_cricket = create_group("A")
group_badminton = create_group("B")
group_football = create_group("C")

# Compute and print results
a = find_common_students(group_cricket, group_badminton)
print("Students who play both cricket and badminton:", a)

b = find_either_not_both_students(group_cricket, group_badminton)
print("Students who play either cricket or badminton but not both:", b)

c = find_neither_students(group_cricket, group_badminton, group_football)
print("Number of students who play neither cricket nor badminton:", len(c))

d = find_cricket_football_not_badminton_students(group_cricket, group_football, group_badminton)
print("Number of students who play cricket and football but not badminton:", len(d))
