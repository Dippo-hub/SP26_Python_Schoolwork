import hashlib
h = hashlib.new('md5', b'cab').hexdigest()
print(f'initial hash is {h}')
letters='abcdefghi'
foundHash=False

for letter1 in letters:
    for letter2 in letters:
        for letter3 in letters:
            best_guess = letter1+letter2+letter3
            test_hash = hashlib.new('md5', best_guess.encode('UTF8')).hexdigest()
            print(best_guess, test_hash)
            if test_hash==h:
                foundHash=True
                print('Found it!')
                break
        if foundHash:
            break
    if foundHash:
        break

if foundHash:
    print(f'Best guess is {test_hash} giving \"{best_guess}\"')
else:
    print('No good guesses.')

