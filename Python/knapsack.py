def knapsack(value, weight, capacity):
    n = len(value) - 1
    m = [[-1]*(capacity + 1) for _ in range(n + 1)]
 
    return knapsack_helper(value, weight, m, n, capacity)
 
 
def knapsack_helper(value, weight, m, i, w):
    if m[i][w] >= 0:
        return m[i][w]
 
    if i == 0:
        q = 0
    elif weight[i] <= w:
        q = max(knapsack_helper(value, weight,
                                m, i - 1 , w - weight[i])
                + value[i],
                knapsack_helper(value, weight,
                                m, i - 1 , w))
    else:
        q = knapsack_helper(value, weight,
                            m, i - 1 , w)
    m[i][w] = q
    return q
 
 
n = int(input('Enter number of items: '))
value = input('Enter the values of the {} item(s) in order: ' .format(n)).split()
value = [int(v) for v in value]
value.insert(0, None) 
weight = input('Enter the positive weights of the {} item(s) in order: '.format(n)).split()
weight = [int(w) for w in weight]
weight.insert(0, None)
capacity = int(input('Enter maximum weight: '))
ans = knapsack(value, weight, capacity)
print('The maximum value of items that can be carried:', ans)