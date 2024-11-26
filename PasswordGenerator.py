import pandas as pd

df = pd.DataFrame({
"word": ['qwerty','qwertyuiop','asdfgh','asdfghjkl','zxcvbn','zxcvbnm']
})
df.to_csv('words.csv', index=False)


import random
df = pd.read_csv('words.csv') 
word_list = df['word']

password = []
password_length = int(input('Enter number of words to incorporate => ')) 
print()
sep = input('Enter seperator => ')

for _ in range(password_length):
    random_index = random.randint(0, len(word_list) - 1) 
    password.append( word_list[random_index] )

password = sep.join(password)
print('Generated password => ',password)
