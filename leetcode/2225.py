class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        count = defaultdict(int)
        players = set()
        for [w, l] in matches:
            count[l] += 1
            players.add(w)
            players.add(l)
        
        no_loss, exactly_one_loss = [], []
        for p in sorted(players):
            if p not in count:
                no_loss.append(p)
            elif count[p] == 1:
                exactly_one_loss.append(p)
        return [no_loss, exactly_one_loss]
        
        