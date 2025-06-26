//DERIVATIVE OF SIGMOID FOR GRADIENT CALCULATION FOR BACKPROPAGATION
double derism(double x) {                          // after assuming  x is already passed by sigmoid function 
  return x * (1.0-x);
}
