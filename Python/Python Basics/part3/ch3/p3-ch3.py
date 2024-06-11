import csv

def extract():
	data = []
	with open('input.csv') as file:
		reader = csv.DictReader(file)
		for line in reader:
			data.append(line)
	return data

def transform(data_to_transform):
	data_to_load = []
	for data in data_to_transform:
		transformed_data = {}
		transformed_data["name"] = data["nom"]
		data["heures_travaillees"] = int(data["heures_travaillees"]) * 15
		transformed_data["salary"] = str(data["heures_travaillees"])
		data_to_load.append(transformed_data)
	return (data_to_load)

def load(data_to_load):
	with open("output.csv", mode="w") as file:
		fieldnames = ["name", "salary"]
		writer = csv.DictWriter(file, fieldnames=fieldnames)
		writer.writeheader()
		for data in data_to_load:
			writer.writerow(data)

def main():
	data_to_transform = extract()
	data_to_load = transform(data_to_transform)
	load(data_to_load)

if __name__ == "__main__":
	main()