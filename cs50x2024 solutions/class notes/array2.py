words = []
for i in range(5):
    word = input(f"Enter word {i + 1}: ")
    words.append(word)

result = ''.join(word[0] for word in words)

print(f"Result word: {result}")