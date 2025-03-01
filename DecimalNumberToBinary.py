def decimalNumbercToBinary(num):
    """Function Convert numeric to binary

    Args:
        num (Number Decimal): The number you want to convert to binary
        numBinary (Converted Binary Number): Converted Binary Number
    """
    num = int(num)
    numBinary = ''
    while num>0:
        if num%2 == 0:
            numBinary = numBinary + '0'
            num = int(num/2)
        elif num%2 == 1: 
            numBinary = numBinary + "1"
            num = int(num/2)
    numBinary = reverse(numBinary)
    print(f"Binary number: {numBinary}")
    

def reverse(string):
    # the  slice syntax
    reversed_string = string[::-1]
    return reversed_string
    
def binaryToDecimal(num):
    num = reverse(num)
    counter = 0
    decimalNumber = 0
    for i in num:
        if i == '1' or i=='0':
            decimalNumber += int(i) * pow(2,counter)
            counter += 1
        else:
            print('You can only put 1 or 0 for binary number')
            menu()
    print(f"Decimal Number: {decimalNumber}")

def numberVerify(num):
    if num.isnumeric():
        return num
    else:
        print("You can't enter a non-numeric character")
        menu()

def menu():
    print("""Welcom to the program where you can convert to decimal number to binary number
        1 - Decimal to Binary
        2 - Binary to Decimal
        3 - Exit 
    """)
    option = input('choose an option:')
    menuOptions(option)

def menuOptions(option):
    if option == '1':
        decimalNumbercToBinary(numberVerify(input('Introduce your decimal Number:')))
        menu()
    elif option == '2':
        binaryToDecimal(numberVerify(input('Introduce your binary Number:')))
        menu()
    elif option == '3':
        exit()
    else: 
        print('Your choose isn\'t in options available')
        menu()

def __init__():
    menu()

__init__()