##____Gradient___descent 
''' so partial derivative will tell us the the slope is it minimum or not is other story (if slope goes to 0) now if we put all directio partial derivatives in one place and start searching for 
that slope =0 we goin to do by gradient collectively all partial derivative put together ...... now  it goes like low to high but we need to go to low in terrain so we take desscent where we go down 1-1 step 
multiplying with a learning rate to gradient and then substracting it by the value we get prviously we can start by anywhere picking  a random place and then go for until convergance happens.
now language written here is very raw but we can get an idea '''

''' In regression, we aim to minimize a cost function, typically the Mean Squared Error (MSE).
The MSE is calculated by summing the squares of the differences between the predicted and actual values, then dividing by the number of samples.
Once we have this cost function, we compute its partial derivatives with respect to the model parameters (like weights w and bias b) — denoted as dw and db.
These derivatives form the gradient, and we apply gradient descent to iteratively update the parameters and reduce the error. '''
# sample___code_now 
#setting first  
w = 0, b = 0
#now for step by step iteration 
for i in epochs(10000):
    y_P = w*x+b #( the predicted one)
    dw= (1/m) * sum((y_P - y) * x)
    db= (1/m) * sum(y_p - y)
#above lines are gradient 
#now below is g descent 
    w = w - alpha * dw
    b = b - alpha * db
#so this is pseudo code for gradient descent .
    



