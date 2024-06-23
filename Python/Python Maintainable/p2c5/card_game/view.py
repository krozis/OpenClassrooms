class View:
	
	def prompt_for_player(self):
		name = input("Enter player's name: ")
		if not (name):
			return (None)
		return (name)
	
	def show_player_hand(self, name, hand):
		print(f"[Player {name}]")
		for card in hand:
			if card.is_face_up:
				print(card)
			else:
				print("(hidden card)")

	def prompt_for_flip_cards(self):
		input("\nPress Enter to flip the cards!")
		return (True)

	def prompt_for_new_game(self):
		replay = ""
		while (replay != "Y" or replay != "N"):
			replay = input("Do you want to play again? (Y/N)")
			if (replay == "Y"):
				return (True)
			elif (replay == "N"):
				return (False)

	def show_winner(self, name):
		print(f"Congratulations to the winner: {name} !")