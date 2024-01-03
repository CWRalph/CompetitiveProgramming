import sys

# Get test case #
#################
test_case_fifo = sys.argv[1]
with open(test_case_fifo, 'r') as f:
    testcase = f.read().split()

# A set of five letter words and a maximum total number of guesses
max_guesses = int(testcase[0])
words = testcase[1:]
n = len(words)

# Get valid words #
###################
valid_words = set(open('words.txt', 'r').read().split())

# Interactor functions #
########################
def fail(reason):
    print('ERROR') # If your program ever receives ERROR, terminate immediately!
    print(reason)
    sys.exit(1)

def eval_guess(guess, word):
    res = list('_____')
    guess = list(guess)
    word = list(word)
    for i in range(5):
        if guess[i] == word[i]:
            res[i] = '*'
            guess[i] = ' '
            word[i] = '^'
    for i in range(5):
        for j in range(5):
            if word[i] == guess[j]:
                res[j] = '-'
                guess[j] = ' '
                word[i] = '^'
                break
    return ''.join(res)

# Interactive part #
####################
print(n, max_guesses, flush=True) # Make sure to flush your output after every print

tot_tries = 0
for w in words:
    res = ''
    while res != '*****':
        if tot_tries >= max_guesses:
            fail('Exceeded Maximum Guesses')
        try:
            tot_tries += 1
            guess = input().lower()
            if guess not in valid_words:
                fail('Invalid Guess')

            res = eval_guess(guess, w)
            print(res)            

        except Exception as e:
            fail(f'Uncaught Error: {e}')

# print(f'Total Tries: {tot_tries}')
sys.exit(0)

