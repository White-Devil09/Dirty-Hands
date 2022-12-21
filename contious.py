import pyautogui as pg 
import time
time.sleep(10)

txt=open("animals.txt","r")
for word in txt:
    pg.write('Hey you look like ')
    pg.write(word)
    pg.press('Enter')
    
