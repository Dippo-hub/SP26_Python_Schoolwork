#DECORATORS
# strip off dashes
'''
def strip_string(b_function):
    def wrapper():
        func = b_function()
        strip_string = func.strip('-')
        return strip_string
    return wrapper

#create upper case version of clli code
def uppercase_decorator(some_function):
  def a_wrapper():
    func = some_function()
    make_uppercase = func.upper()
    return make_uppercase

  return a_wrapper
@uppercase_decorator
@strip_string
def clli_code():
  print('The Florida router clli code is', end = '')
  return '---tpaflxacg19----'


print(clli_code())
# Double click to copy code'''

# map.grades.py
# produce list of tuples
'''grades = [95, 88, 85, 75]
letter_grade = ['A', 'B+', 'B', 'C']
print('The original list ',letter_grade)
print('The zipped tuples ', list(zip(letter_grade, grades)))
print('Next is a map-lambda version')
result=map(lambda *a: a, letter_grade, grades) # equivalent to zip
print(list(result))

# Double click to copy code'''

# listcomp_vs_genexp.py
# list comprehension vs generator expression
import sys
a = [x for x in range(1000000)] #list comp
b = (x for x in range(1000000))
print('list comp byte size is ',sys.getsizeof(a))
print('generator expression byte size is ',sys.getsizeof(b))






