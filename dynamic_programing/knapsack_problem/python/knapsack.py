from sys import stdin
from sys import stdout
'''
Knapsack Problem implementation

Created on Dec 6, 2010
@author: rohanbk
'''
capacity=10;
num_of_items=6;
total_weight=0;
total_value=0;

#Initialize backpack
B=[[0]*(capacity+1) for i in range(num_of_items)];
#Keep list will help determine which items to keep once we've solved the Knapsack problem
keep=[[0]*(capacity+1) for i in range(num_of_items)];

#Dictionary to store item numbers and corresponding weights
#<Item number, weight>
item_weight={0:4,1:2,2:3,3:1,4:7,5:10};
#Dictionary to store item numbers and corresponding values
#<Item number, value>
item_value={0:6,1:4,2:5,3:3,4:9,5:7};

total_weight=sum([value for value in item_weight.values()])
total_value=sum([value for value in item_value.values()])

#Solve Knapsack problem
for k in range(num_of_items):
    for w in range(capacity+1):
        if(w>=item_weight[k]):
            p1=B[k-1][w];
            p2=B[k-1][w-item_weight[k]]+item_value[k];
            if(p1>p2):
                keep[k][w]=0;
                B[k][w]=p1;
            else:
                keep[k][w]=1;
                B[k][w]=p2;
        else:
            B[k][w]= B[k-1][w];
            keep[k][w]=0;
            
rem_capacity=capacity;
items_to_take=[];
valueofgoods=0;

#Determine which items to keep and what their total value is       
for k in range(num_of_items-1,-1,-1):
    if(keep[k][rem_capacity]==1):
        items_to_take.append(k);
        rem_capacity=rem_capacity-item_weight[k];
        valueofgoods+=item_value[k];
print 'Total value of all goods: %s'%(total_value)
print 'Goods to choose: %s'%(items_to_take)
print 'Maximized Value of goods: %s'%(valueofgoods)
print 'Opportunity cost: %s'%(total_value-valueofgoods)            