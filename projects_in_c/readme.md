### This C program uses standard file I/O and string functions to parse a CSV file of exercise data. It extracts the Duration and Calories columns into arrays, then runs gradient descent for 1000 epochs with learning rate 0.0001. We use the linear model 
 𝑦 = 
 𝑤
𝑥
 +
 𝑏
### and minimize the MSE cost. The partial derivatives of the cost w.r.t. w and b are computed as shown in and parameters are updated accordingly. At every 100th epoch, the current epoch number, MSE cost, and parameter values are printed. Finally, the program prompts the user to enter a duration value and outputs the predicted calories burned using the trained model.
