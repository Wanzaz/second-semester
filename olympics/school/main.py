# Zadani delitelnost 1, 2
from math import sqrt

numbers = []
with open('nums.txt') as file:
    for line in file:
        numbers += line.split()

# 2 -------------------------------
def divisible_by_all(n, array =[]):
    for i in array:
        if (int(array[i]) % n) != 0:
            return 0
    return 1
 

def test_it(array):
    for num in array:
        if divisible_by_all(num, array) == 1:
            print(f"{num}")
        else: 
            print("not")
 
 
# 1 -------------------------------
def countDivisors(num) :
    count = 0
    for index in range(1, int(sqrt(num)) + 1):
        if num % index == 0:
            if num / index == index:
                count += 1
            else :
                count += 2
    return count

def num_of_divisors(n):
    count = 0
    for i in range(1, int(n) + 1):
        if int(n) % i == 0:
            count += 1
    return count


def max_div_num(array):
    "finding a number with the most divisors"
    max_div_num_huh = 0
    diversed_num = 0
    for num in array:
        numerus = countDivisors(int(num))
        if numerus > max_div_num_huh:
            diversed_num = int(num)
            max_div_num_huh = numerus
    return (max_div_num_huh, diversed_num)

def writting_out():
    "Writting out all the numbers of this number"
    tuple_res = max_div_num(numbers)
    num_of_divisors_num = tuple_res[0]
    number = tuple_res[1]

    list_of_all_dividers = []
    for i in range(1, int(number) + 1):
        if int(number) % i == 0:
            list_of_all_dividers.append(i)


    print(f"The number with most divisors: {number}")
    print(f"The number has {num_of_divisors_num} divisors")
    print(f"The divisors of the number: {list_of_all_dividers}")
            
writting_out()

# test_it(numbers)


