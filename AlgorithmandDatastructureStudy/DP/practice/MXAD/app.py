#https://www.codechef.com/UADPIP01/problems/MXAD
import numpy as np
import logging

logging.basicConfig(filename='logger.log', encoding='utf-8', level=logging.DEBUG)

dp=[None]*1000
dp[0]= 0
dp[1] = 1
