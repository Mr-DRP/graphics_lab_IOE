#!/usr/bin/python

from __future__ import division
from graphics import *
import math
import time

def Shape():
    pntx = list()
    pnty = list()
    ver = int(input("Enter number of vertices"))
    for x in range(ver):
        xc = int(input('Enter x'))
        yc = int(input('Enter y'))
        pntx.append(xc)
        pnty.append(yc)
    pntx.append(pntx[0])
    pnty.append(pnty[0])
    print(pntx)
    win = GraphWin("Lab 4", 800, 600)
    win.setCoords(-400, -300, 400, 300)
    draw(ver, pntx, pnty, win)
    translate(win,ver,pntx,pnty)
    scale(win,ver,pntx,pnty)
    rotate(win,ver,pntx,pnty)
    rotate(win,ver,pntx,pnty)
    rotate(win,ver,pntx,pnty)
    rotate(win,ver,pntx,pnty)
    win.getKey()
    win.close()

def draw(ver, arrx,arry,win):
    for x in range(ver):
        aLine = Line(Point(arrx[x],arry[x]), Point(arrx[x+1],arry[x+1]))
        aLine.draw(win)
        
def translate(win,ver,pntx,pnty):
    print("Enter translation vector")
    tx = int(input("tx: "))
    ty = int(input("ty: "))
    nx = list()
    ny = list()
    for x in range(ver):
        nx.append(pntx[x]+tx)
        ny.append(pnty[x]+ty)
    nx.append(nx[0])
    ny.append(ny[0])
    draw(ver,nx,ny,win)

def scale(win,ver,pntx,pnty):
    print("Enter Scaling factor")
    tx = float(input("sx: "))
    ty = float(input("sy: "))
    nx = list()
    ny = list()
    for x in range(ver):
        nx.append(pntx[x]*tx)
        ny.append(pnty[x]*tx)
    nx.append(nx[0])
    ny.append(ny[0])
    draw(ver,nx,ny,win)
    
def rotate(win,ver,pntx,pnty):
    print("Enter rotating angle")
    ang = float(input("angle in radian: "))
    nx = list()
    ny = list()
    for x in range(ver):
        nx.append(pntx[x]* math.cos(ang) - pnty[x] * math.sin(ang))
        ny.append(pntx[x]* math.sin(ang) + pnty[x] * math.cos(ang))
    nx.append(nx[0])
    ny.append(ny[0])
    draw(ver,nx,ny,win)
    
def main():

 
    Shape()
    
main()