##-*- coding: utf-8 -*- 
# conda install cvxopt


from cvxopt import matrix, solvers
import numpy as np





Q =matrix([[4.0, 1.0], [1.0, 2.0]])
p = matrix([1.0,1.0],(2,1))
G = matrix([[-1.0,0.0,-1.0],[0.0,-1.0,0.0]],(3,2),tc='d')
h = matrix([0.0,0.0,-1.0])
A = matrix( [1.0, 1.0], (1,2)) 
#1行2列

b = matrix(1.0)

sol=solvers.qp(Q, p, G, h, A, b)


print(sol['x'])
print(sol['primal objective'])


