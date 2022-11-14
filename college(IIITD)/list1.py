#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    time=int(s[:2])
    tfact=(s[-2:])
    if(tfact=="PM"):
        time+=12
        return (str(time)+s[2:-2])
    elif(time==12 and tfact=="AM"):
        time-=12
        return (str(time)+s[2:-2])
    else:
        return s[:-2]
    return (str(time)+s[2:]);
if __name__ == '__main__':

    s = input()

    result = timeConversion(s)
    print(result)