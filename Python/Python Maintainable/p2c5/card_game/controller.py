from card_game.player import Player

MAX_PLAYERS = 5


class Controller:

	def __init__(self, deck, view):
		"""Initializes the Controller"""
		# models
		self.players = []
		self.deck = deck

		# views
		self.view = view

	def get_players(self):
		while (len(self.players) < MAX_PLAYERS):
			name = self.view.prompt_for_player()
			if not name:
				return
			player = Player(name)
			self.players.append(player)

	def evaluate_game(self):
		"""Compares the scores of all players
			return only the best card's player (name only)"""
		best_candidate = self.players[0]

		for player in self.players:
			player_card = player.hand[0]
			best_candidate_card = best_candidate.hand[0]

			if (player_card > best_candidate_card):
				best_candidate = player

		return (best_candidate.name)

	def rebuild_deck(self):
		for player in self.players:
			while (player.hand):
				card = player.hand.pop()
				card.is_face_up = False
				self.deck.append(card)
		self.deck.shuffle()

	def start_game(self):
		self.deck.shuffle()
		for player in self.players:
			card = self.deck.draw_card()
			if (card):
				player.hand.append(card)

	def run(self):
		"""run the Controller"""
		self.get_players()

		running = True
		while (running):
			self.start_game()
			for player in self.players:
				self.view.show_player_hand(player.name, player.hand)
			self.view.prompt_for_flip_cards()
			for player in self.players:
				for card in player.hand:
					card.is_face_up = True
				self.view.show_player_hand(player.name, player.hand)
			self.view.show_winner(self.evaluate_game())
			running = self.view.prompt_for_new_game()
			self.rebuild_deck()
