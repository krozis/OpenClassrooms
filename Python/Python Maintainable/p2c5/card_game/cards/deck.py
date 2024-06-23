"""Defines a full Deck of Cards"""

import random
from cards import CARD_RANKS, CARD_SUITS, Card


class Deck(list):
	"""class that represents a complete card deck"""
	
	def __init__(self):
		"""Initialize the Deck"""
		for rank in CARD_RANKS:
			for suit in CARD_SUITS:
				card = Card(suit, rank)
				self.append(card)
		self.shuffle()

	def shuffle(self):
		"""Shuffle the cards in the Deck"""
		random.shuffle(self)

	def draw_card(self):
		"""draw a Card from the Deck"""
		try:
			return (self.pop())
		except (IndexError):
			return (None)
		

