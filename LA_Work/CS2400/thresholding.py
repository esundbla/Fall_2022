import cv2 as cv
import matplotlib.pyplot as plt
import numpy as np


def masking(bgr, low, high):
  """ Actual implementaion of mask tool"""
  length, width, extra = bgr.shape
  # Thresholding done by direct anlysis of images 
  # Potentially will be optomized through open/close transformations
  mask = cv.inRange(src, np.array([185,125,0]),np.array([255,255,100]))
  result = cv.bitwise_and(src, src, mask= mask)
  return result



if __name__ == "__main__":
  src = cv.imread("C:/Users/13039/Desktop/Maize Seedling.jpeg", flags=cv.IMREAD_COLOR)
  rgb = cv.cvtColor(src, cv.COLOR_BGR2HSV)
  #rgb = src
  plt.figure(figsize=(10,10))
  plt.title('original')
  plt.imshow(rgb)
  #plt.show()

  print(rgb.shape)

  hist = np.histogram(rgb[:,:,1], 256)
  """
  plt.title('Red')
  plt.imshow(rgb[:,:,0])
  plt.show()

  plt.title('Green')
  plt.imshow(rgb[:,:,1])
  plt.show()

  
  plt.title('Blue')
  plt.imshow(rgb[:,:,2])
  plt.show()
  """
#np.array([125,255,165])


#Kernel Thresholding
  kern = masking(rgb,np.array([10,120,100]),np.array([25,255,255]))
  kern = cv.cvtColor(kern, cv.COLOR_HSV2RGB)
  plt.figure(figsize=(10,10))
  plt.title('Kernel')
  plt.imshow(kern)
  #plt.show()

  

#Stem
  stem = masking(rgb,np.array([125,155,10]),np.array([188,205,120]))
  stem = cv.cvtColor(stem, cv.COLOR_HSV2RGB)
  plt.figure(figsize=(10,10))
  plt.title('Stem') 
  plt.imshow(stem)
  plt.show()


"""
#Root
  root = masking(rgb,np.array([80,95,50]),np.array([200,220,150]))
  plt.figure(figsize=(10,10))
  plt.title('Root')
  plt.imshow(root)
  plt.show()
"""
