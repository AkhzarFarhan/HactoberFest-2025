from collections import defaultdict

def findScoreSum(nums):
    value_map = defaultdict(lambda: {'count': 0, 'sum_indices': 0})
    total_score = 0

    for i, val in enumerate(nums):
        count = value_map[val]['count']
        sum_indices = value_map[val]['sum_indices']

        
        total_score += count * i - sum_indices


        value_map[val]['count'] += 1
        value_map[val]['sum_indices'] += i

    return total_score
