from contact.User import User
from contact.TextContactSystem import TextContactSystem
from contact.OwlContactSystem import OwlContactSystem
from contact.helpers import send_mass_messages

def	main():

	alice = User("Alice", TextContactSystem("0102030405"))
	bob = User("Bob", OwlContactSystem("4 Privet Drive"))

	user_list = [alice, bob]
	send_mass_messages("Hello {name}, Comment vas-tu?", user_list)
	send_mass_messages(
		"Salut {name}. Tes informations de contact sont-elles corrects?"
		" Nous avons celles-ci: {contact_info}.",
		user_list,
	)

if __name__ == "__main__":
	main()