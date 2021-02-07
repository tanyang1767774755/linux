import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import animation

fig=plt.figure(figsize=(8,8))   
ax1=Axes3D(fig)                         
ax1.plot3D([0,1],[0,1],[0,1])
x_track=np.zeros((1,3))                     
x_track_s=np.array([.0,.0,.0])                 
theta=0
def gen_path():
    global x_track,x_track_s,theta
    theta+=10
    x=theta
    y=theta
    x_track_s+=[x,y,x*x+y*y+x]
    x_track=np.append(x_track,[x_track_s],axis=0)
    return x_track



def update(i):
    lable='time{0}'.format(i)
    # print(lable)
    x_track=gen_path()
    ax1.set_xlabel(lable)

    ax1.plot3D(x_track[:, 0], x_track[:, 1], x_track[:, 2], 'green')
    return ax1

if __name__=='__main__':
    anim=animation.FuncAnimation(fig=fig,func=update,frames=np.arange(0,100),interval=200)
plt.show()
