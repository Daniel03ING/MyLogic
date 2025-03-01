def decimalNumbercToBinary(num):
    """Function Convert numeric to binary

    Args:
        num (Number Decimal): The number you want to convert to binary
        numBinary (Converted Binary Number): Converted Binary Number
    """
    numBinary = ''
    try:
        num  = int(num)
        while num>0:
            if num%2 == 0:
                numBinary = numBinary + '0'
                num = int(num/2)
            elif num%2 == 1: 
                numBinary = numBinary + "1"
                num = int(num/2)
        print(f"Binary number: {numBinary}")
    except:
        print("You can't enter a non-numeric character")
    

print("""Welcom to the program where you can convert to decimal number to binary number
""")
decimalNumbercToBinary(int(input('Introduce your decimal Number:')))

    