fruits = {
	"apple":"red",
	"banana":"yellow",
	"orange":"orange"
}

fruits["kiwi"] = "green"
banana_color = fruits["banana"]
fruits["kiwi"] = "green"
fruits.pop("orange")

print(fruits.keys())

print(fruits["apple"])
print(fruits.get("apple"))