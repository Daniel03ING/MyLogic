def numerictobinary(num):
    """Function Convert numeric to binary

    Args:
        num (numeric): The number you want to convert to binary
    """
    num_binary = ''
    try:
        num  = int(num)
        while num>0:
            if num%2 == 0:
                num_binary = num_binary + '0'
                num = int(num/2)
            elif num%2 == 1: 
                num_binary = num_binary + "1"
                num = int(num/2)
        print(num_binary)
    except:
        print("You can't enter a non-numeric character")
    

numerictobinary(1)
    