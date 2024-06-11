import requests

from bs4 import BeautifulSoup


# Extraction
with open("index.html", 'r') as file:
	soup = BeautifulSoup(file, 'html.parser')

title = soup.title
h1 = soup.h1

# Name and price of the products
products = soup.find_all('li')
products_list = []
for product in products:
    name = product.h2.string
    price = product.find("p", string=lambda s: "Prix" in s).string
    products_list.append((name, price))

# description of the products
descriptions_list = []
for product in products:
    description = product.find('p', string=lambda s: 'Description' in s).string
    descriptions_list.append(description)

print("Page title:", title)
print("H1 text", h1)
print("Products list:", products_list)
print("Products desciptions list:", descriptions_list)

for i, (name, price) in enumerate(products_list):
    euro_price_str = ''.join(filter(str.isdigit, price.split()[2])) 
    euro_price = int(euro_price_str)
    dollar_price = euro_price * 1.2
    products_list[i] = (name, f"{dollar_price}$")


print("Products list:", products_list)