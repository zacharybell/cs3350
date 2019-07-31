def main():
    
    # testing code
    n = 3  # states
    m = 4  # symbols
    state = [
        [0, 2, 1, 1],   # state 0
        [1, 1, 2, 2],   # state 1
        [0, 1, 0, 0]    # state 2
    ]
    final = [
        False,
        False,
        True
    ]
    trace(n, m, state, final, l="a+b-a")

# FSM emulation
def trace(n, m, state, final, l):
    curr = 0
    for i in l:
        print("Current state: " + str(curr))
        curr = state[curr][symbol(i)]
        print("Symbol " + i + " moves to " + str(curr))
    print("Final: " + str(final[curr]))

def symbol(c):
    sym_dict = {
        "+" : 0,
        "-" : 1,
        "a" : 2,
        "b" : 3
    }
    return sym_dict[c]

if(__name__=="__main__"):
    main()
