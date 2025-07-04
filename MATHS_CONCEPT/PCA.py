''' principal componant analysis is used for reducting column while maintaining the useful information as it is in a dataset ... we use concept of basically 3 things 
1 . projection 
2. eigenvector and eigenvalues
3. covariance 
we will calculate the covariance first  ( to capture realtionship with features ) . then we will go for the eigenvector of this covariance matrix .. most stretched one is the principal .
means one with biggest eigenvalue is the one that can cover entire basis . then we will project it done :) '''

import numpy as np 
# A sample matrix 

X = np.array([
    [2.5, 2.4],
    [0.5, 0.7],
    [2.2, 2.9],
    [1.9, 2.2],
    [3.1, 3.0],
])
# data needs to be centered 
X_mean= X-X.mean(axis=0)  
# covariance of matrix
C = np.cov(X_mean.T)
# sosuke eigen :p eigenvector & values
eigvals, eigvecs = np.linalg.eig(C)
#sorting by largest to get the biggest variance vectors
idx = np.argsort(eigvals)[::-1]
eigvecs = eigvecs[:, idx]
#projection
X_pca = X_mean @ eigvecs[:, 0]

print("First principal component:", eigvecs[:, 0])
print("Projected data:", X_pca)
