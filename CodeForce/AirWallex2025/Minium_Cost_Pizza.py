import sys
import math
i = 0

daily_pizza = []
daily_cost = []
for line in sys.stdin:
    if line == "\n":
        break
    if i == 0:
        N = int(line.split()[0])
    else:
        A = list(map(int, line.split()))
        if i <= N:
            daily_pizza.append(A)
        else:
            daily_cost.append(A)
    i += 1

prev_cost = [(i, math.inf) for i in range(1, 5)]

final = 0
for pizzas, costs in zip(daily_pizza, daily_cost):
    total = 0
    count = 3
    # pizza_price = [(type, amount, cost, prev_cost)]
    pizza_price = [(i, x, y, z) for x, y, (i, z) in zip(pizzas, costs, prev_cost)]
    # Sort by the max_difference between cost and prev_cost for each type
    pizza_price = sorted(pizza_price, key=lambda x: (x[2] - x[3], [1]), reverse=True)

    prev_cost = []
    for (i, pizza, cost1, cost2) in pizza_price: # (type, amount, cost, prev_cost)
        # The there is storage in the freezer, and today is more expensive than the previous day
        if count > 0 and (cost1 > cost2): 
            if pizza != 0:
                total += cost2
                pizza -=1
                prev_cost.append((i, cost1))
            # If there is storage in the freezer, and yesterday is cheaper and no new pizza today.
            else:
                prev_cost.append((i, cost2))
            count -= 1
        #If there is no storage or today is cheaper than yesterday.
        else:
            prev_cost.append((i, cost1))
        total += cost1 * pizza
    prev_cost.sort(key=lambda x: x[0])

    final += total

print(final)