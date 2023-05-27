def climbingLeaderboard(ranked, player):
    ranked=list(set(ranked))
    ranked.sort()
    ls=[]
    n=len(ranked)
    rank=0
    for i in player:
        while(rank<n and ranked[rank]<=i):
            rank+=1
        ls.append(n-rank+1)
    return ls
print(climbingLeaderboard([100,90,90,80,75,60],[50,65,77,90,102]))

# players 50 65 77 90 102
# ranked 60 70 80 90 100