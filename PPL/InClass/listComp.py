"""
List comprehension program
PPL 
Erik Sundbald
"""


if __name__ == "__main__":
    li = [x for x in range(3,11)]
    print(li)
    li = [x for x in range(10,1,-2)]
    print(li)
    li = [x * x for x in range (1,11,3)]
    print(li)
    src = [2,3.75,0.04,59,0.3,6,7,8.5,9,10]
    li = [x for x in src if isinstance(x, int)]
    print(li)
    li = [x for x in range(1000) if x%7 == 0]
    print(li)
    a = [x for x in range(1,10)]
    b = [2,7,1,12]
    li = [(x,y) for x in a for y in b if x+y > 10]
    print(li)
