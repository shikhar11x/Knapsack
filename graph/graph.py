import matplotlib.pyplot as plt

capacities = [10, 20, 30, 40]
fractional_steps = [17, 19, 19, 19]  
knapsack01_steps = [50, 100, 150, 200]  

plt.figure(figsize=(8, 5))
plt.plot(capacities, fractional_steps, marker='o', linestyle='-', color='b', label='Fractional Knapsack')
plt.plot(capacities, knapsack01_steps, marker='s', linestyle='-', color='r', label='0/1 Knapsack')

plt.xlabel('Knapsack Capacity')
plt.ylabel('Steps Taken')
plt.title('Comparison of Knapsack Algorithms')
plt.legend()
plt.grid(True)

plt.show()
