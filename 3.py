#Knapsacck 01
#TC-O(n*capactiy), SC-O(n*capaciity)
def knapsack_dp(values, weights, capacity):
    n = len(values)
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for w in range(1, capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1])
            else:
                dp[i][w] = dp[i - 1][w]

    selected_items = [0] * n  
    w = capacity
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i - 1][w]:  
            selected_items[i - 1] = 1  
            w -= weights[i - 1]  

    return dp[n][capacity], selected_items

if __name__ == "__main__":
    n = int(input("Enter the number of items: "))

    values = []
    weights = []
    for i in range(n):
        value = int(input(f"Enter the value of item {i + 1}: "))
        weight = int(input(f"Enter the weight of item {i + 1}: "))
        values.append(value)
        weights.append(weight)

    capacity = int(input("Enter the capacity of the knapsack: "))

    max_value, selected_items = knapsack_dp(values, weights, capacity)

    print(f"The maximum value that can be obtained is: {max_value}")
    print(f"The selected items in binary form are: {''.join(map(str, selected_items))}")



#fractional knapsack
class Item:
	def __init__(self, profit, weight):
		self.profit = profit
		self.weight = weight

# Main greedy function to solve problem
def fractionalKnapsack(W, arr):
	# Sorting Item on basis of ratio
	arr.sort(key=lambda x: (x.profit / x.weight), reverse=True)

	# Result(value in Knapsack)
	finalvalue = 0.0

	# Looping through all Items
	for item in arr:
		# If adding Item won't overflow, add it completely
		if item.weight <= W:
			W -= item.weight
			finalvalue += item.profit
		# If we can't add current Item, add fractional part of it
		else:
			finalvalue += item.profit * W / item.weight
			break

	# Returning final value
	return finalvalue

# Driver Code
if __name__ == "__main__":
	# Taking input from the user
	W = float(input("Enter the maximum weight capacity of the knapsack: "))
	n = int(input("Enter the number of items: "))
	
	arr = []
	for i in range(n):
		profit = float(input(f"Enter the profit of item {i + 1}: "))
		weight = float(input(f"Enter the weight of item {i + 1}: "))
		arr.append(Item(profit, weight))

	# Function call
	max_val = fractionalKnapsack(W, arr)
	print(f"The maximum profit is: {max_val}")
