import numpy as np 
#____training___damta__huehue
x_f= np.array([1,2,3,4,5])
y_v=np.array([3,5,7,9,11]) # the relation is : 2x_f+1 so in the ouput after training these weights and bias should be presented.

# giving anything as weights and bias in starting 

w=0.0
b=0.0

#rate of learning 
lr=0.01

rp =1000 #times___to repeat__to__train

#putting everything in loop now for training 

for i in range(rp):
  y_p=w*x_f + b
  error= y_p -y_v
  cost = (error**2).mean() 
  #gradients__set
  dw=(2*(error*x_f)).mean() #as maths formula for gradient
  db = (2 * error).mean()  #as maths formula for bias
  #updateeeeee
  w-=lr*dw
  b-=lr*db



  if i %100== 0:   
    print(f"repeater {i}, Cost: {cost:.4f}, w: {w:.4f}, b: {b:.4f}")

print(f"Final model: relation is  = {w:.2f} x + {b:.2f}")    




 
