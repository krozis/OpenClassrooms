"""Defines the classes Card and Deck"""

import random

CARD_SUITS = ("Diamonds", "Hearts", "Clubs", "Spades")

CARD_RANKS = (
	'2',
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'10',
	'Jack',
	'Queen',
	'King',
	'Ace')


class InvalidCardException(Exception):
	"""Exception raised for an invalid card"""
	def __init__(self, message) -> None:
		self.message = message
		super().__init__(self.message)


class Card:
	"""class to represent a playing card
	
	Attributes:
	----------
	suit : str
		The suit of the card (e.g., 'Hearts').
	rank : str
		The rank of the card (e.g., 'Ace').
	is_face_up : bool
	"""

	def __init__(self, suit, rank) -> None:
		"""defines a card"""

		if (suit not in CARD_SUITS or rank not in CARD_RANKS):
			raise (InvalidCardException(f"{rank} of {suit} is not a valid card."))

		self.suit = suit
		self.rank = rank
		self.is_face_up = False

		self._rank_score = CARD_RANKS.index(self.rank)
		self._suit_score = CARD_SUITS.index(self.suit)

	def __str__(self) -> str:
		return (f"{self.rank} of {self.suit}")
	
	def __repr__(self) -> str:
		return str(self)
	
	def __lt__(self, other: "Card"):
		"""Defines comparison between two cards"""
		if (self._rank_score != other._rank_score):
			return (self._rank_score < other._rank_score)
		return (self._suit_score < other._suit_score)


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
		

