import json

# json handling in python

# ------------read json --------------------------
# a JSON:
x = '{ "name":"Alex", "age":22, "city":"Bonn"}'

# load from json in  x:
y = json.loads(x)

# the data return as dictionary:
print(y["age"])
# output
# 30

# -----------write json-----------------------------
# the var for json must a dic:
x = {
    "name": "Dan",
    "age": 24,
    "city": "Berlin"
}

# convert to a JSON:
y = json.dumps(x)

# the output is a JSON string:
print(y)

# Output
# {"name": "Dan","age": 24,"city": "Berlin"}
