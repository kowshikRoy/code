#!/usr/bin/env python3

def card_value(card: str):
    if card[0].isdigit():
        return int(card[0])
    return 10


def solve(case: int):
    cards = []
    while True:
        cards += input().split()
        if len(cards) == 52:
            break
    Y = 0
    cards.reverse()
    hand, pile = cards[0:25], cards[25:]
    for _ in range(3):
        value = card_value(pile[0])
        Y += value
        pile = pile[1 + 10-value:]
    pile = hand + pile
    pile.reverse()
    print(f'Case {case}: {pile[Y-1]}')


if __name__ == '__main__':
    t = int(input())
    for c in range(1, t + 1):
        solve(c)
