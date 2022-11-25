x = lambda a : a + 10
print(x(5))

x = lambda a, b : a * b
print(x(5, 6))

x = lambda a, b, c : a + b + c
print(x(5, 6, 2))

my_list = [1, 2, 3, 4, 5, 6]
new_list = list(map(lambda x: x*2, my_list))
print(new_list) # [2, 4, 6, 8, 10, 12]

