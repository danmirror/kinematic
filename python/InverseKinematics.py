from numpy import *

# Length of links in cm
Length_a= 5.2
Length_b = 6.9
Length_c = 6.8

# Desired Position of End effector
px = 10
py = 3

phi = 90
phi = deg2rad(phi)

# Equations for Inverse kinematics
wx = px - Length_c*cos(phi)
wy = py - Length_c*sin(phi)
print(wx)
print(wy)
delta = wx**2 + wy**2
c2 = ( delta -Length_a**2 -Length_b**2)/(2*Length_a*Length_b)
s2 = sqrt(1-c2**2)  # elbow down
theta_2 = arctan2(s2, c2)

s1 = ((Length_a+Length_b*c2)*wy - Length_b*s2*wx)/delta
c1 = ((Length_a+Length_b*c2)*wx + Length_b*s2*wy)/delta
theta_1 = arctan2(s1,c1)
theta_3 = phi-theta_1-theta_2

print('theta_1: ', rad2deg(theta_1))
print('theta_2: ', rad2deg(theta_2))
print('theta_3: ', rad2deg(theta_3))

