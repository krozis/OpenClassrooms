from card_game.cards.cards import Card, CARD_SUITS, CARD_RANKS
# from card_game.cards.deck import Deck


class Hand(list):
	def append(self, object):
		if (not isinstance(object, Card)):
			return (ValueError("you can only add Cards"))
		return super().append(object)


class Player:
	
	def __init__(self, name) -> None:
		"""Defines the Player with a name and a hand"""
		self.name = name
		self.hand = Hand()

