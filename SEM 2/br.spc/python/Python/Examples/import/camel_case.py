import camelcase
c = camelcase.CamelCase()
txt = "hello world"
print(c.hump(txt))
txt1 = "1123hello world"
print(c.hump(txt1))